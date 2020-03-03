

#include <computer/science/pluralsight/mocking/MovieData.hpp>

using namespace computer::science::pluralsight::mocking;

log4cxx::LoggerPtr MovieData::logger = log4cxx::Logger::getLogger(std::string(
                                                                      "computer.science.pluralsight.mocking.MovieData"));

MovieData::MovieData()
    : m_id(std::string())
    , m_title(std::string())
    , m_posterUrl(std::string())
    , m_length(0)
    , m_actors()
    , m_plot(std::string())
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

MovieData::~MovieData()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void MovieData::setImdbId(std::string id)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_id = id;
}

void MovieData::setTitle(std::string title)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_title = title;
}

void MovieData::setLengthMin(unsigned length)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_length = length;
}

void MovieData::setActors(std::vector<std::string> actors)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_actors = actors;
}

void MovieData::setPlot(std::string plot)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_plot = plot;
}

std::string MovieData::getImdbId()const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return (m_id);
}

std::string MovieData::getTitle()const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return (m_title);
}

unsigned MovieData::getLengthMin()const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return (m_length);
}

std::vector<std::string>  MovieData::getActors()const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return (m_actors);
}

std::string MovieData::getPlot()const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return (m_plot);
}

