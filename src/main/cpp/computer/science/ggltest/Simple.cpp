

#include <cppbdd101/lectures/ggltest/Simple.hpp>

log4cxx::LoggerPtr Simple::logger = log4cxx::Logger::getLogger(std::string("cppbdd101.lectures.ggltest.Simple"));

Simple::Simple()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Simple::~Simple()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

int Simple::add(int aValue)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return 42 + aValue;
}

double Simple::multiply(double aValue)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return 42 * aValue;
}

std::string Simple::addPrefix(const char* aPrefix, const char* aTxt)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return std::string { aPrefix } + std::string { aTxt };
}

const char* Simple::getCStyleString()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return "abc";
}

