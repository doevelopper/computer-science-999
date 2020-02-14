

#include <computer/science/Calendar.hpp>

using namespace computer::science;

Calendar::Calendar()
    : m_year(1)
    , m_month(1)
    , m_day(1)
{
}

bool Calendar::isLeap(unsigned int year)
{
    return (isDivisibleBy4(year) and (!isDivisibleBy100(year) or isDivisibleBy400(year)));
}

bool Calendar::isDivisibleBy4(unsigned int year)
{
    return (year % 4 == 0);
}

bool Calendar::isDivisibleBy100(unsigned int year)
{
    return (year % 100 == 0);
}

bool Calendar::isDivisibleBy400(unsigned int year)
{
    return (year % 400 == 0);
}

