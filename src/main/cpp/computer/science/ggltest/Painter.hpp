

#ifndef CPPBDD101_LECTURES_GGLTEST_PAINTER_HPP
#define CPPBDD101_LECTURES_GGLTEST_PAINTER_HPP

#include <cppbdd101/lectures/ggltest/Turtle.hpp>

class Painter
{
    public:

        Painter();
        Painter(Turtle * turtle);
        Painter(const Painter & orig);
        virtual ~Painter();
        bool DrawCircle (int x, int y, int r);

    private:

        Turtle *           turtle;
        log4cxx::LoggerPtr logger;
};


#endif

