#ifndef CPPBDD101_LECTURES_GGLTEST_TURTLETEST_HPP
#define CPPBDD101_LECTURES_GGLTEST_TURTLETEST_HPP

#include <gtest/gtest.h>
#include  <cppbdd101/lectures/ggltest/MockTurtle.hpp>
#include  <cppbdd101/lectures/ggltest/FakeTurtle.hpp>
#include  <cppbdd101/lectures/ggltest/MockTurtleDelegate.hpp>


class TurtleTest : public ::testing::Test
{

public:

    TurtleTest();
    TurtleTest(const TurtleTest & orig);
    virtual ~TurtleTest();

    virtual void SetUp ();
    virtual void TearDown ();

protected:

    MockTurtle * objectUnderTest;
    static log4cxx::LoggerPtr logger;

};


#endif
