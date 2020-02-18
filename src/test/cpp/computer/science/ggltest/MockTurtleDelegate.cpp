#include  <cppbdd101/lectures/ggltest/MockTurtleDelegate.hpp>

// log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger(std::string("cppbdd101.lectures.ggltest.DelegateMockTurtle"));
MockTurtleDelegate::MockTurtleDelegate()
: logger (log4cxx::Logger::getLogger(std::string("cppbdd101.lectures.ggltest.DelegateMockTurtle")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

MockTurtleDelegate::MockTurtleDelegate(const MockTurtleDelegate & orig)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

MockTurtleDelegate::~MockTurtleDelegate()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void MockTurtleDelegate::DelegateToFake ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    // ON_CALL(*this, doSomeStuff( _, _ ) ).WillByDefault( Return( ERROR ));
    ON_CALL(*this , PenUp()).WillByDefault(testing::Invoke(&turtleNinja , &FakeTurtle::PenUp));
    ON_CALL(*this , PenDown()).WillByDefault(testing::Invoke(&turtleNinja , &FakeTurtle::PenDown));
    ON_CALL(*this , Forward(_)).WillByDefault(testing::Invoke(&turtleNinja , &FakeTurtle::Forward));
    ON_CALL(*this , Turn(_)).WillByDefault(testing::Invoke(&turtleNinja , &FakeTurtle::Turn));
    ON_CALL(*this , GoTo(_ , _)).WillByDefault(testing::Invoke(&turtleNinja , &FakeTurtle::GoTo));
    ON_CALL(*this , GetX()).WillByDefault(testing::Invoke(&turtleNinja , &FakeTurtle::GetX));
    ON_CALL(*this , GetY()).WillByDefault(testing::Invoke(&turtleNinja , &FakeTurtle::GetY));
    ON_CALL(*this , getArbitraryString()).WillByDefault(testing::Invoke(&turtleNinja , &FakeTurtle::getArbitraryString));
    ON_CALL(*this , name()).WillByDefault(testing::Invoke(&turtleNinja , &FakeTurtle::name));


    //    EXPECT_CALL(*this, GetX())
    //                .WillOnce(Return(100))
    //                .WillOnce(Return(200))
    //                .WillOnce(Return(300));
    //    EXPECT_CALL(*this, GetY())
    //                .WillOnce(Return(100))
    //                .WillOnce(Return(200))
    //                .WillRepeatedly(Return(300));
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__ << " Exit");
}

