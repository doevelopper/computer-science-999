#ifndef CPPBDD101_LECTURES_GGLTEST_PAINTERTEST_HPP
#define CPPBDD101_LECTURES_GGLTEST_PAINTERTEST_HPP
#include <gmock/gmock.h>
#include <cppbdd101/lectures/ggltest/MockTurtle.hpp>
#include <cppbdd101/lectures/ggltest/Painter.hpp>

using ::testing::AtLeast;

class PainterTest : public ::testing::Test
{

public:

    PainterTest();
    PainterTest(const PainterTest & orig);
    virtual ~PainterTest();

protected:

    void canDrawSomething ();
    static Painter * objectUnderTest;
    static MockTurtle * turtleMock;
    static log4cxx::LoggerPtr logger;

private:

};


#endif
