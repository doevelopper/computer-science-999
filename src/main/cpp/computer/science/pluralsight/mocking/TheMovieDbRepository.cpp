

#include <computer/science/pluralsight/mocking/JsonHelper.hpp>
#include <computer/science/pluralsight/mocking/MovieNotFoundException.hpp>
#include <computer/science/pluralsight/mocking/StringHtmlEncoder.hpp>
#include <computer/science/pluralsight/mocking/TheMovieDbRepository.hpp>

using namespace computer::science::pluralsight::mocking;

log4cxx::LoggerPtr TheMovieDbRepository::logger = log4cxx::Logger::getLogger(std::string(
                                                                                 "computer.science.pluralsight.mocking.TheMovieDbRepository"));

TheMovieDbRepository::TheMovieDbRepository(const std::string& apiKey, const MovieDataFactory& movieDataFactory)
    : m_apiKey(apiKey)
    , m_movieDataFactory(movieDataFactory)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TheMovieDbRepository::TheMovieDbRepository(const std::string& apiKey, const MovieDataFactory& movieDataFactory,
                                           RestApiClient & client)
    : m_apiKey(apiKey)
    , m_movieDataFactory(movieDataFactory)
    , m_client(client)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TheMovieDbRepository::~TheMovieDbRepository()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

std::shared_ptr<MovieData> TheMovieDbRepository::findMovieData(const std::string& movieName)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto encodedMovieName = StringHtmlEncoder::encode(movieName);

    std::string getMovieListUrl = "http://api.themoviedb.org/3/search/movie?api_key=" + m_apiKey + "&page=1&query=" +
                                  encodedMovieName;
    std::string movieList = m_client.httpGet(getMovieListUrl);
    if(movieList.length() == 0)
    {
        throw MovieNotFoundException(movieName);
    }

    auto movieId = JsonHelper::getMatchingTitleIdFromMovieList(movieName, movieList);

    if(movieId.length() == 0)
    {
        throw MovieNotFoundException(movieName);
    }

    std::string getMovieDetailsUrl = "http://api.themoviedb.org/3/movie/" + movieId + "?api_key=" + m_apiKey;
    auto movieDataJson = m_client.httpGet(getMovieDetailsUrl);

    return (m_movieDataFactory.createFromJson(movieDataJson));
}

