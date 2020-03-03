

#ifndef COMPUTER_SCIENCE_FixtureWithParameterizedTestCalendarTest_HPP
#define COMPUTER_SCIENCE_FixtureWithParameterizedTestCalendarTest_HPP
#include <tuple>
#include <gtest/gtest.h>
#include <computer/science/Calendar.hpp>
namespace computer::science
{
    class FixtureWithParameterizedTestCalendarTest : public ::testing::Test
    {
        public:

            FixtureWithParameterizedTestCalendarTest();
            FixtureWithParameterizedTestCalendarTest(const FixtureWithParameterizedTestCalendarTest&) = default;
            FixtureWithParameterizedTestCalendarTest( FixtureWithParameterizedTestCalendarTest&&) = default;
            FixtureWithParameterizedTestCalendarTest& operator=(const
                                                                FixtureWithParameterizedTestCalendarTest&) = default;
            FixtureWithParameterizedTestCalendarTest& operator=( FixtureWithParameterizedTestCalendarTest&&) = default;
            virtual ~FixtureWithParameterizedTestCalendarTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            computer::science::Calendar * testee;
            static log4cxx::LoggerPtr     logger;

        private:
    };
}
#endif

