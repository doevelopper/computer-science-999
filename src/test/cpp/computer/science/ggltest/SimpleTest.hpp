#ifndef CPPBDD101_LECTURES_GGLTEST_SIMPLETEST_HPP
#define CPPBDD101_LECTURES_GGLTEST_SIMPLETEST_HPP

#include <gtest/gtest.h>
#include <log4cxx/logger.h>
#include <cppbdd101/lectures/ggltest/Simple.hpp>

class SimpleTest : public ::testing::Test
{
public:
    SimpleTest();
    virtual ~SimpleTest();

    virtual void SetUp();
    virtual void TearDown ();

protected:
    /*!
     * @brief Object that is about to be tested. 
     */
    //Simple * objectUnderTest;
    /*!
     * @brief Class logger. 
     */
    static log4cxx::LoggerPtr logger;
        
private:

};
#endif
