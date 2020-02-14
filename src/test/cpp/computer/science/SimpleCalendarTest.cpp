

#include <vector>
#include <gtest/gtest.h>
#include <computer/science/Calendar.hpp>

using namespace computer::science;

TEST(SimpleCalendarTest, 1IsOdd_IsNotLeapYear)
{
    Calendar calendar;
    ASSERT_FALSE(calendar.isLeap(1));
}

TEST(SimpleCalendarTest, 711IsOdd_IsNotLeapYear)
{
    Calendar calendar;
    ASSERT_FALSE(calendar.isLeap(711));
}

TEST(SimpleCalendarTest, 1989IsOdd_IsNotLeapYear)
{
    Calendar calendar;
    ASSERT_FALSE(calendar.isLeap(1989));
}

TEST(SimpleCalendarTest, 2013IsOdd_IsNotLeapYear)
{
    Calendar calendar;
    ASSERT_FALSE(calendar.isLeap(2013));
}

TEST(SimpleCalendarTest, OddYearsAreNotLeapYears)
{
    Calendar calendar;
    auto oddYears = std::vector<int>{1, 3, 711,1976, 1983, 2013, 2020};
    for (auto oddYear :  oddYears)
    {
        ASSERT_FALSE(calendar.isLeap(oddYear));
    }
}

