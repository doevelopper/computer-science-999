

#ifndef COMPUTER_SCIENCE_CONTAINERTEST_HPP
#define COMPUTER_SCIENCE_CONTAINERTEST_HPP

#include <gtest/gtest.h>
#include <computer/science/CSVector.hpp>
#include <computer/science/CSList.hpp>
#include <computer/science/CSQueue.hpp>

namespace computer::science::test
{
    using ContainerTypes = ::testing::Types< computer::science::CSVector, computer::science::CSList,
                                             computer::science::CSQueue>;

    template <typename T>
    class ContainerTest : public ::testing::Test
    {
        public:

            ContainerTest();
            ContainerTest(const ContainerTest&) = default;
            ContainerTest(ContainerTest&&) = default;
            ContainerTest& operator=(const ContainerTest&) = default;
            ContainerTest& operator=(ContainerTest&&) = default;
            virtual ~ContainerTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };

    TYPED_TEST_CASE_P(ContainerTest);
}

#endif

