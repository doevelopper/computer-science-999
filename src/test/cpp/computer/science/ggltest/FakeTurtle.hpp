
#ifndef CPPBDD101_LECTURES_GGLTEST_FAKETURTLE_HPP
#define CPPBDD101_LECTURES_GGLTEST_FAKETURTLE_HPP

#include  <cppbdd101/lectures/ggltest/Turtle.hpp>
class FakeTurtle : public Turtle
{
public:

    FakeTurtle();
    FakeTurtle(const FakeTurtle & orig);
    virtual ~FakeTurtle();

    virtual void PenUp ();
    virtual void PenDown ();
    virtual void Forward (int distance);
    virtual void Turn (int degrees);
    virtual void GoTo (int x , int y);
    virtual int GetX () const;
    virtual int GetY () const;
    virtual std::string name () const;
    virtual std::string getArbitraryString ();
    virtual bool IsActive ();

private:

    int xCord;
    int yCord;
    int deg;
    int dist;
    log4cxx::LoggerPtr logger;

};


#endif
