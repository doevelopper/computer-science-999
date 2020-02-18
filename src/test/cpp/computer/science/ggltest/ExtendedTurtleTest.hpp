
#ifndef CPPBDD101_LECTURES_GGLTEST_EXTENDEDTURTLETEST_HPP
#define CPPBDD101_LECTURES_GGLTEST_EXTENDEDTURTLETEST_HPP

#include  <cppbdd101/lectures/ggltest/MockTurtleDelegate.hpp>

class ExtendedTurtleTest : public ::testing::Test
{
public:

    ExtendedTurtleTest();
    ExtendedTurtleTest(const ExtendedTurtleTest & orig);
    virtual ~ExtendedTurtleTest();

    virtual void SetUp ();

    virtual void TearDown ();

protected:

    static MockTurtleDelegate * objectUnderTest;
    static log4cxx::LoggerPtr logger;

private:
};


#endif
