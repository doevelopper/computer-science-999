

#include <computer/science/CSList.hpp>

using namespace computer::science;
log4cxx::LoggerPtr CSList::logger = log4cxx::Logger::getLogger(std::string("computer.science.CSList"));
void CSList::add(size_t num)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    m_items.push_back(num);
}

std::size_t CSList::count() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );

    return m_items.size();
}

void CSList::loop(functorIterator funcIt) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    for(const std::size_t item: m_items)
    {
        funcIt(item);
    }
}

