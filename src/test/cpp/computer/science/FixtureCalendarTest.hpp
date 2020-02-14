

#ifndef COMPUTER_SCIENCE_FIXTURECALENDARTEST_HPP
#define COMPUTER_SCIENCE_FIXTURECALENDARTEST_HPP
#include <tuple>
#include <gtest/gtest.h>
#include <computer/science/Calendar.hpp>
namespace computer::science
{
    class FixtureCalendarTest : public ::testing::Test
    {
        public:

            FixtureCalendarTest();
            FixtureCalendarTest(const FixtureCalendarTest&) = default;
            FixtureCalendarTest( FixtureCalendarTest&&) = default;
            FixtureCalendarTest& operator=(const FixtureCalendarTest&) = default;
            FixtureCalendarTest& operator=( FixtureCalendarTest&&) = default;
            virtual ~FixtureCalendarTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            computer::science::Calendar * testee;

        private:
    };
}
#endif

