

#include <computer/science/pluralsight/mocking/MetaDataProcessor.hpp>
#include <computer/science/pluralsight/mocking/MovieData.hpp>

using namespace computer::science::pluralsight::mocking;
log4cxx::LoggerPtr MetaDataProcessor::logger = log4cxx::Logger::getLogger(std::string(
                                                                              "computer.science.pluralsight.mocking.MetaDataProcessor"));

/*
   MetaDataProcessor::MetaDataProcessor()
   :  m_repository()
   {

   }
 */
MetaDataProcessor::MetaDataProcessor(MovieMetaDataRepository& jsonClient)
    : m_repository(jsonClient)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

/*
   MetaDataProcessor::~MetaDataProcessor()
   {
   }
 */
void MetaDataProcessor::processMovies(const std::vector<std::string>& movieNames, Movies& result)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if(!movieNames.size()) return;

    for (auto movieName : movieNames)
    {
        try
        {
            std::shared_ptr<MovieData> movieData = m_repository.findMovieData(movieName);
            result.push_back(movieData);
        }
        catch (...)
        {
            LOG4CXX_ERROR(logger, __LOG4CXX_FUNC__);
        }
    }
}

