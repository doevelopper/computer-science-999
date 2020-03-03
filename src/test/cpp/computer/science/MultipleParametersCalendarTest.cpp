

#include <computer/science/MultipleParametersCalendarTest.hpp>

using namespace computer::science;

log4cxx::LoggerPtr MultipleParametersCalendarTest::logger = log4cxx::Logger::getLogger(std::string(
                                                                                           "computer.science.MultipleParametersCalendarTest"));

MultipleParametersCalendarTest::MultipleParametersCalendarTest()
    : testee()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

MultipleParametersCalendarTest::~MultipleParametersCalendarTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void MultipleParametersCalendarTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    testee = new computer::science::Calendar();
}

void MultipleParametersCalendarTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    delete testee;
}

TEST_P(MultipleParametersCalendarTest, ChecksIfLeapYear)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    bool expected = std::get<1>(GetParam());
    int year = std::get<0>(GetParam());
    ASSERT_EQ(expected, testee->isLeap(year));
}

INSTANTIATE_TEST_CASE_P(
    XParamsTests,
    MultipleParametersCalendarTest,
    ::testing::Values(
        std::make_tuple(7, false),
        std::make_tuple(2001, false),
        std::make_tuple(1996, true),
        std::make_tuple(1700, false),
        std::make_tuple(1600, true)));

