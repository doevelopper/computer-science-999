

#include <computer/science/CSQueue.hpp>

using namespace computer::science;

log4cxx::LoggerPtr CSQueue::logger = log4cxx::Logger::getLogger(std::string("computer.science.CSQueue"));

void CSQueue::add(std::size_t num)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    m_items.push_back(num);
}

std::size_t CSQueue::count() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );

    return m_items.size();
}

void CSQueue::loop(functorIterator funcIt) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    for(const std::size_t item: m_items)
    {
        funcIt(item);
    }
}

