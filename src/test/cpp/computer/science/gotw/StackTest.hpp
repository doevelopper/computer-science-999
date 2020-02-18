
#ifndef CPPBDD101_LECTURES_GOTW_STACKTEST_HPP
#define CPPBDD101_LECTURES_GOTW_STACKTEST_HPP

#include <gtest/gtest.h>
#include <cppbdd101/lectures/gotw/Stack.hpp>

class StackTest : public ::testing::Test 
{
public:
    StackTest();
    virtual ~StackTest();

    virtual void SetUp();
    virtual void TearDown ();

protected:
        /*!
         * @brief Object that is about to be tested. 
         */
        Stack<int> * stack;
        /*!
         * @brief Class logger. 
         */
        static log4cxx::LoggerPtr logger;
private:

};

#endif

