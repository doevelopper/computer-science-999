

#include <computer/science/pluralsight/mocking/SettableMovieData.hpp>

using namespace computer::science::pluralsight::mocking;

log4cxx::LoggerPtr SettableMovieData::logger = log4cxx::Logger::getLogger(std::string(
                                                                              "computer.science.pluralsight.mocking.SettableMovieData"));

void SettableMovieData::setImdbId(std::string id)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    MovieData::setImdbId(id);
}

void SettableMovieData::setTitle(std::string title)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    MovieData::setTitle(title);
}

void SettableMovieData::setLengthMin(unsigned length)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    MovieData::setLengthMin(length);
}

void SettableMovieData::setActors(std::vector<std::string> actors)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    MovieData::setActors(actors);
}

void SettableMovieData::setPlot(std::string plot)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    MovieData::setPlot(plot);
}

