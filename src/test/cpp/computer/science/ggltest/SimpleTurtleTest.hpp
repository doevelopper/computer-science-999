#ifndef CPPBDD101_LECTURES_GGLTEST_SIMPLETURTLETEST_HPP
#define CPPBDD101_LECTURES_GGLTEST_SIMPLETURTLETEST_HPP

#include <gtest/gtest.h>
#include  <cppbdd101/lectures/ggltest/FakeTurtle.hpp>
class SimpleTurtleTest : public ::testing::Test
{
public:

    SimpleTurtleTest();
    SimpleTurtleTest(const SimpleTurtleTest & orig);
    virtual ~SimpleTurtleTest();

    virtual void SetUp ();
    virtual void TearDown ();

protected:

    static FakeTurtle * objectUnderTest;
    static log4cxx::LoggerPtr logger;

};


#endif
