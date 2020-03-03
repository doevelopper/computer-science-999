

#include <cppbdd101/lectures/gotw/Complex.hpp>

log4cxx::LoggerPtr Complex::logger = log4cxx::Logger::getLogger(std::string("cppbdd101.lectures.gotw.Complex"));

Complex::Complex()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Complex::Complex(double real, double imaginary)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Complex::~Complex()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

double Complex::real() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return m_real;
}

double Complex::imaginary() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    return m_imaginary;
}

