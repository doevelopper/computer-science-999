#include  <cppbdd101/lectures/ggltest/MockTurtle.hpp>

MockTurtle::MockTurtle()
 : logger (log4cxx::Logger::getLogger(std::string("cppbdd101.lectures.ggltest.MockTurtle")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

MockTurtle::MockTurtle(const MockTurtle & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

MockTurtle::~MockTurtle() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}