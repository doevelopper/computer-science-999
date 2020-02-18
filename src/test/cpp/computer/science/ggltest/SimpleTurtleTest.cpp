#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include  <cppbdd101/lectures/ggltest/SimpleTurtleTest.hpp>

FakeTurtle * SimpleTurtleTest::objectUnderTest = nullptr;
log4cxx::LoggerPtr SimpleTurtleTest::logger = log4cxx::Logger::getLogger(std::string("cppbdd101.lectures.ggltest.SimpleTurtleTest"));

SimpleTurtleTest::SimpleTurtleTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // srand (time(NULL));
}

SimpleTurtleTest::SimpleTurtleTest(const SimpleTurtleTest & orig)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

SimpleTurtleTest::~SimpleTurtleTest()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void SimpleTurtleTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    objectUnderTest = new FakeTurtle();
    objectUnderTest->PenUp();
    objectUnderTest->PenDown();
    objectUnderTest->Forward((rand() % 12 + 1));
    objectUnderTest->Turn((rand() % 12 + 1));
    objectUnderTest->GoTo((rand() % 50 + 1) , (rand() % 50 + 1));
}

void SimpleTurtleTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete objectUnderTest;
}

TEST_F(SimpleTurtleTest , testGetX)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    objectUnderTest->GetX();

}

TEST_F(SimpleTurtleTest , testGetY)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    objectUnderTest->GetY();
}

TEST_F(SimpleTurtleTest , testGetName)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    objectUnderTest->getArbitraryString();
}
