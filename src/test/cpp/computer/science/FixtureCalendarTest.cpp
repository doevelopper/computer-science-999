

#include <computer/science/FixtureCalendarTest.hpp>

using namespace computer::science;

FixtureCalendarTest::FixtureCalendarTest()
    : testee()
{
}

FixtureCalendarTest::~FixtureCalendarTest()
{
}

void FixtureCalendarTest::SetUp()
{
    testee = new computer::science::Calendar();
}

void FixtureCalendarTest::TearDown()
{
    delete testee;
}

TEST_F(FixtureCalendarTest, 1IsOdd_IsNotLeapYear) {
    ASSERT_FALSE(testee->isLeap(1));
}

TEST_F(FixtureCalendarTest, 711IsOdd_IsNotLeapYear) {
    ASSERT_FALSE(testee->isLeap(711));
}

TEST_F(FixtureCalendarTest, 1989IsOdd_IsNotLeapYear) {
    ASSERT_FALSE(testee->isLeap(1989));
}

TEST_F(FixtureCalendarTest, 2013IsOdd_IsNotLeapYear) {
    ASSERT_FALSE(testee->isLeap(2013));
}

