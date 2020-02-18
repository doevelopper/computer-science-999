#ifndef CPPBDD101_LECTURES_GGLTEST_MOCKTURTLE_HPP
#define CPPBDD101_LECTURES_GGLTEST_MOCKTURTLE_HPP

#include <gmock/gmock.h>
#include <cppbdd101/lectures/ggltest/Turtle.hpp>
#include <cppbdd101/LoggingService.hpp>
/*
    We should use NiceMock with ON_CALL for stub object.
    We should use StrictMock with EXPECT_CALL for mock object.
                can separate stub and mock from one interface.
 */
// class MockTurtle : public Turtle{

class MockTurtle : public ::testing::NiceMock<Turtle>
{
public:

    MockTurtle();
    MockTurtle(const MockTurtle & orig);
    virtual ~MockTurtle();

    MOCK_METHOD0(PenUp , void());
    MOCK_METHOD0(PenDown , void());
    MOCK_METHOD1(Forward , void (int distance));
    MOCK_METHOD1(Turn , void (int degrees));
    MOCK_METHOD2(GoTo , void (int x , int y));
    MOCK_CONST_METHOD0(GetX , int());
    MOCK_CONST_METHOD0(GetY , int());
    MOCK_METHOD0(getArbitraryString , std::string());
    MOCK_CONST_METHOD0( name , std::string () );
    MOCK_METHOD0(IsActive , bool());
private:

    log4cxx::LoggerPtr logger;
};


#endif
