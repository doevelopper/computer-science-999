

#include <cppbdd101/lectures/gotw/ComplexTest.hpp>

log4cxx::LoggerPtr ComplexTest::logger = log4cxx::Logger::getLogger(std::string("cppbdd101.lectures.gotw.ComplexTest"));

ComplexTest::ComplexTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ComplexTest::~ComplexTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void ComplexTest::SetUp ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    objectUnderTest = new Complex();
}

void ComplexTest::TearDown ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    delete objectUnderTest;
}

TEST_F(ComplexTest, basic)
{
    // Complex c(1, 2);
    // Complex c2(0, 1);
    // ++c;
    // EXPECT_DOUBLE_EQ(2.0, c.real());
    // EXPECT_DOUBLE_EQ(3.0, (c + c2).imaginary());
}

