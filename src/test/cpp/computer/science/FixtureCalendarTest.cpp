

#include <computer/science/FixtureCalendarTest.hpp>

using namespace computer::science;

log4cxx::LoggerPtr FixtureCalendarTest::logger = log4cxx::Logger::getLogger(std::string(
                                                                                "computer.science.FixtureCalendarTest"));

FixtureCalendarTest::FixtureCalendarTest()
    : testee()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

FixtureCalendarTest::~FixtureCalendarTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void FixtureCalendarTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    testee = new computer::science::Calendar();
}

void FixtureCalendarTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    delete testee;
}

TEST_F(FixtureCalendarTest, 1IsOdd_IsNotLeapYear)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_FALSE(testee->isLeap(1));
}

TEST_F(FixtureCalendarTest, 711IsOdd_IsNotLeapYear)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_FALSE(testee->isLeap(711));
}

TEST_F(FixtureCalendarTest, 1989IsOdd_IsNotLeapYear)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_FALSE(testee->isLeap(1989));
}

TEST_F(FixtureCalendarTest, 2013IsOdd_IsNotLeapYear)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_FALSE(testee->isLeap(2013));
}

