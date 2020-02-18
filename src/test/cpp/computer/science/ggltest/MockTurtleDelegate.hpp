#ifndef CPPBDD101_LECTURES_GGLTEST_MOCKTURTLEDELEGATE_HPP
#define CPPBDD101_LECTURES_GGLTEST_MOCKTURTLEDELEGATE_HPP

#include <gmock/gmock.h>
#include  <cppbdd101/lectures/ggltest/Turtle.hpp>
#include  <cppbdd101/lectures/ggltest/FakeTurtle.hpp>

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Gt;
using ::testing::NotNull;
using ::testing::InvokeWithoutArgs;
using ::testing::AnyNumber;
using ::testing::Return;
using ::testing::Invoke;
using ::testing::NiceMock;
using ::testing::ReturnRef;
using ::testing::SaveArg;
using ::testing::InSequence;

class MockTurtleDelegate : public Turtle
{

public:

    MockTurtleDelegate();
    MockTurtleDelegate(const MockTurtleDelegate & orig);
    virtual ~MockTurtleDelegate();

    MOCK_METHOD0(PenUp , void());
    MOCK_METHOD0(PenDown , void());
    MOCK_METHOD1(Forward , void (int distance));
    MOCK_METHOD1(Turn , void (int degrees));
    MOCK_METHOD2(GoTo , void (int x , int y));
    MOCK_CONST_METHOD0(GetX , int());
    MOCK_CONST_METHOD0(GetY , int());
    MOCK_CONST_METHOD0(name , std::string ());
    MOCK_METHOD0(getArbitraryString , std::string());
    MOCK_METHOD0(IsActive , bool());


    void DelegateToFake ();

private:

    FakeTurtle turtleNinja;
    log4cxx::LoggerPtr logger;

};


#endif
