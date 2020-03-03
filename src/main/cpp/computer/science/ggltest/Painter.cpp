

#include <cppbdd101/lectures/ggltest/Painter.hpp>

Painter::Painter()
    : logger(log4cxx::Logger::getLogger(std::string("cppbdd101.lectures.ggltest.Painter")))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Painter::Painter(const Painter & orig)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Painter::~Painter()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Painter::Painter(Turtle * trtl)
    : turtle(trtl)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

bool Painter::DrawCircle (int x,
                          int y,
                          int r)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    LOG4CXX_DEBUG(logger, "x:" << x <<"y:" << y<<"r:" << r);
    //PARAM_UNUSED(x);
    //PARAM_UNUSED(y);

    //PARAM_UNUSED(r);
    return (true);
}

