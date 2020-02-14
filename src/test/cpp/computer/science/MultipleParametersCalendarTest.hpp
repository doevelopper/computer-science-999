

#ifndef COMPUTER_SCIENCE_MULTIPLEPARAMETERSCALENDARTEST_HPP
#define COMPUTER_SCIENCE_MULTIPLEPARAMETERSCALENDARTEST_HPP
#include <tuple>
#include <gtest/gtest.h>
#include <computer/science/Calendar.hpp>
namespace  computer::science
{
    class MultipleParametersCalendarTest : public ::testing::TestWithParam<std::tuple<int, bool> >
    {
        public:

            MultipleParametersCalendarTest();
            MultipleParametersCalendarTest(const MultipleParametersCalendarTest&) = default;
            MultipleParametersCalendarTest(MultipleParametersCalendarTest&&) = default;
            MultipleParametersCalendarTest& operator=(const MultipleParametersCalendarTest&) = default;
            MultipleParametersCalendarTest& operator=(MultipleParametersCalendarTest&&) = default;
            virtual ~MultipleParametersCalendarTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            computer::science::Calendar * testee;

        private:
    };
}
#endif

