

#include <computer/science/MultipleParametersCalendarTest.hpp>

using namespace computer::science;

MultipleParametersCalendarTest::MultipleParametersCalendarTest()
    : testee()
{
}

MultipleParametersCalendarTest::~MultipleParametersCalendarTest()
{
}

void MultipleParametersCalendarTest::SetUp()
{
    testee = new computer::science::Calendar();
}

void MultipleParametersCalendarTest::TearDown()
{
    delete testee;
}

TEST_P(MultipleParametersCalendarTest, ChecksIfLeapYear) {
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

