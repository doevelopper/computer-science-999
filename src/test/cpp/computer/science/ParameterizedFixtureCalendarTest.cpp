

#include <computer/science/ParameterizedFixtureCalendarTest.hpp>

using namespace computer::science;

ParameterizedFixtureCalendarTest::ParameterizedFixtureCalendarTest()
    : testee()
{
}

ParameterizedFixtureCalendarTest::~ParameterizedFixtureCalendarTest()
{
}

void ParameterizedFixtureCalendarTest::SetUp()
{
    testee = new computer::science::Calendar();
}

void ParameterizedFixtureCalendarTest::TearDown()
{
    delete testee;
}

TEST_P(ParameterizedFixtureCalendarTest, OddYearsAreNotLeapYears) {
    int year = GetParam();
    ASSERT_FALSE(testee->isLeap(year));
}

INSTANTIATE_TEST_CASE_P(
    FixtureParamTests,
    ParameterizedFixtureCalendarTest,
    ::testing::Values(
        1, 711, 1989, 2013
        ));

