

#include <computer/science/ParameterizedFixtureCalendarTest.hpp>

using namespace computer::science;

log4cxx::LoggerPtr ParameterizedFixtureCalendarTest::logger = log4cxx::Logger::getLogger(std::string(
                                                                                             "computer.science.ParameterizedFixtureCalendarTest"));

ParameterizedFixtureCalendarTest::ParameterizedFixtureCalendarTest()
    : testee()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ParameterizedFixtureCalendarTest::~ParameterizedFixtureCalendarTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void ParameterizedFixtureCalendarTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    testee = new computer::science::Calendar();
}

void ParameterizedFixtureCalendarTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    delete testee;
}

TEST_P(ParameterizedFixtureCalendarTest, OddYearsAreNotLeapYears)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    int year = GetParam();
    ASSERT_FALSE(testee->isLeap(year));
}

INSTANTIATE_TEST_CASE_P(
    FixtureParamTests,
    ParameterizedFixtureCalendarTest,
    ::testing::Values(
        1, 711, 1989, 2013
        ));

