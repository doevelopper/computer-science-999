

#include <cppbdd101/lectures/gotw/StackExceptionTest.hpp>

log4cxx::LoggerPtr StackExceptionTest::logger = log4cxx::Logger::getLogger(std::string(
                                                                               "cppbdd101.lectures.gotw.StackExceptionTest"));

StackExceptionTest::StackExceptionTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

StackExceptionTest::~StackExceptionTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void StackExceptionTest::SetUp ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    //objectUnderTest = new Simple();
}

void StackExceptionTest::TearDown ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    //delete objectUnderTest;
}

