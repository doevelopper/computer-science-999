

#include <computer/science/Calendar.hpp>

using namespace computer::science;
log4cxx::LoggerPtr Calendar::logger = log4cxx::Logger::getLogger(std::string("computer.science.Calendar"));
Calendar::Calendar()
    : m_year(1)
    , m_month(1)
    , m_day(1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

bool Calendar::isLeap(unsigned int year)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );

    return (isDivisibleBy4(year) and (!isDivisibleBy100(year) or isDivisibleBy400(year)));
}

bool Calendar::isDivisibleBy4(unsigned int year)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );

    return (year % 4 == 0);
}

bool Calendar::isDivisibleBy100(unsigned int year)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );

    return (year % 100 == 0);
}

bool Calendar::isDivisibleBy400(unsigned int year)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );

    return (year % 400 == 0);
}

