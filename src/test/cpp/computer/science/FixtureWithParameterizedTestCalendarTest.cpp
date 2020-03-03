

#include <computer/science/FixtureWithParameterizedTestCalendarTest.hpp>

using namespace computer::science;

log4cxx::LoggerPtr FixtureWithParameterizedTestCalendarTest::logger = log4cxx::Logger::getLogger(std::string(
                                                                                                     "computer.science.FixtureWithParameterizedTestCalendarTest"));

FixtureWithParameterizedTestCalendarTest::FixtureWithParameterizedTestCalendarTest()
    : testee()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

FixtureWithParameterizedTestCalendarTest::~FixtureWithParameterizedTestCalendarTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void FixtureWithParameterizedTestCalendarTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    testee = new computer::science::Calendar();
}

void FixtureWithParameterizedTestCalendarTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    delete testee;
}

TEST_F(FixtureWithParameterizedTestCalendarTest, 1996_IsDivisibleBy4_ShouldBeALeapYear)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(testee->isLeap(1996));
}

TEST_F(FixtureWithParameterizedTestCalendarTest, 1700_IsDivisibleBy100AndNotBy400_ShouldNotBeALeapYear)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_FALSE(testee->isLeap(1700));
}

TEST_F(FixtureWithParameterizedTestCalendarTest, 1600_IsDivisibleBy400_ShouldBeALeapYear)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(testee->isLeap(1600));
}

class ParametrizedTestFixtureBasedOnFixture
    : public FixtureWithParameterizedTestCalendarTest
    , public ::testing::WithParamInterface<std::tuple<int, bool> >
{
    // public:
    // ParametrizedTestFixtureBasedOnFixture();
    // ParametrizedTestFixtureBasedOnFixture(const ParametrizedTestFixtureBasedOnFixture&) = default;
    // ParametrizedTestFixtureBasedOnFixture(ParametrizedTestFixtureBasedOnFixture&&) = default;
    // ParametrizedTestFixtureBasedOnFixture& operator=(const ParametrizedTestFixtureBasedOnFixture&) = default;
    // ParametrizedTestFixtureBasedOnFixture& operator=(ParametrizedTestFixtureBasedOnFixture&&) = default;
    // virtual ~ParametrizedTestFixtureBasedOnFixture();
};

TEST_P(ParametrizedTestFixtureBasedOnFixture, ChecksIfLeapYear) {
    bool expected = std::get<1>(GetParam());
    int year = std::get<0>(GetParam());
    ASSERT_EQ(expected, testee->isLeap(year));
}

INSTANTIATE_TEST_CASE_P(
    ParamOnFixtureTests,
    ParametrizedTestFixtureBasedOnFixture,
    ::testing::Values(
        std::tuple<int, bool>(7, false),
        std::tuple<int, bool>(2001, false),
        std::tuple<int, bool>(1996, true),
        std::tuple<int, bool>(1700, false),
        std::tuple<int, bool>(1600, true)));

