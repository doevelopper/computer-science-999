
#ifndef CPPBDD101_LECTURES_GOTW_COMPLEXTEST_HPP
#define CPPBDD101_LECTURES_GOTW_COMPLEXTEST_HPP

#include <gtest/gtest.h>
#include <log4cxx/logger.h>
#include <cppbdd101/lectures/gotw/Complex.hpp>

class ComplexTest : public ::testing::Test
{
public:
    ComplexTest();
    virtual ~ComplexTest();

    virtual void SetUp();
    virtual void TearDown ();

protected:
        /*!
         * @brief Object that is about to be tested. 
         */
        Complex * objectUnderTest;
        /*!
         * @brief Class logger. 
         */
        static log4cxx::LoggerPtr logger;
private:

};

#endif

