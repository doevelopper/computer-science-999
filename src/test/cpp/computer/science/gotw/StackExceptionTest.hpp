
#ifndef CPPBDD101_LECTURES_GOTW_STACKEXCEPTIONTEST_HPP
#define CPPBDD101_LECTURES_GOTW_STACKEXCEPTIONTEST_HPP

#include <gtest/gtest.h>
#include <cppbdd101/lectures/gotw/StackException.hpp>

class StackExceptionTest : public ::testing::Test 
{
public:
    StackExceptionTest();
    virtual ~StackExceptionTest();

    virtual void SetUp();
    virtual void TearDown ();
protected:
        /*!
         * @brief Object that is about to be tested. 
         */
        //StackException<int> * objectUnderTest;
        /*!
         * @brief Class logger. 
         */
        static log4cxx::LoggerPtr logger;

private:

};

#endif
