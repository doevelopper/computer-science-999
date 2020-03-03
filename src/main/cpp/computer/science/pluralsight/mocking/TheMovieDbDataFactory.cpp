

#include <rapidjson/document.h>
#include <computer/science/pluralsight/mocking/SettableMovieData.hpp>
#include <computer/science/pluralsight/mocking/TheMovieDbDataFactory.hpp>

using namespace computer::science::pluralsight::mocking;

log4cxx::LoggerPtr TheMovieDbDataFactory::logger = log4cxx::Logger::getLogger(std::string(
                                                                                  "computer.science.pluralsight.mocking.TheMovieDbDataFactory"));

TheMovieDbDataFactory::TheMovieDbDataFactory()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TheMovieDbDataFactory::~TheMovieDbDataFactory()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

std::shared_ptr<MovieData>
TheMovieDbDataFactory::createFromJson(const std::string& jsonString) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    try
    {
        rapidjson::Document jsonDocument;
        jsonDocument.Parse(jsonString.c_str());
        if (!jsonDocument.IsObject())
        {
            return std::make_shared<SettableMovieData>();;
        }

        auto imdbId = jsonDocument["imdb_id"].GetString();
        auto title = jsonDocument["title"].GetString();
        auto plot = jsonDocument["overview"].GetString();
        auto lengthMin = jsonDocument["runtime"].GetUint();

        auto result = std::make_shared<SettableMovieData>();
        result->setImdbId(imdbId);
        result->setTitle(title);
        result->setPlot(plot);
        result->setLengthMin(lengthMin);

        return result;
    }
    catch (...)
    {
        LOG4CXX_ERROR(logger, "Exception occurs");
    }

    return std::make_shared<SettableMovieData>();
}

