

#ifndef COMPUTER_SCIENCE_PARAMETERIZEDFIXTURECALENDARTEST_HPP
#define COMPUTER_SCIENCE_PARAMETERIZEDFIXTURECALENDARTEST_HPP
#include <tuple>
#include <gtest/gtest.h>
#include <computer/science/Calendar.hpp>

namespace computer::science
{
    class ParameterizedFixtureCalendarTest : public ::testing::TestWithParam<int>
    {
        public:

            ParameterizedFixtureCalendarTest();
            ParameterizedFixtureCalendarTest(const ParameterizedFixtureCalendarTest&) = default;
            ParameterizedFixtureCalendarTest(  ParameterizedFixtureCalendarTest&&) = default;
            ParameterizedFixtureCalendarTest& operator=(const ParameterizedFixtureCalendarTest&) = default;
            ParameterizedFixtureCalendarTest& operator=(  ParameterizedFixtureCalendarTest&&) = default;
            virtual ~ParameterizedFixtureCalendarTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            computer::science::Calendar * testee;

        private:
    };
}
#endif

