#include  <cppbdd101/lectures/ggltest/FakeTurtle.hpp>

FakeTurtle::FakeTurtle()
        : xCord(0)
        , yCord(0)
        , deg(0)
        , dist(0)
        , logger (log4cxx::Logger::getLogger(std::string("cppbdd101.lectures.ggltest.FakeTurtle")))
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

FakeTurtle::FakeTurtle(const FakeTurtle & orig) {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

FakeTurtle::~FakeTurtle() {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void FakeTurtle::PenUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void FakeTurtle::PenDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void FakeTurtle::Forward (int distance)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    LOG4CXX_DEBUG(logger , "distance: " << distance);
    this->dist = distance;
}

void FakeTurtle::Turn (int degrees)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    LOG4CXX_DEBUG(logger , "degrees: " << degrees);
    this->deg = degrees;
}

void FakeTurtle::GoTo (int x ,
                       int y)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    LOG4CXX_DEBUG(logger , "x: " << x <<"y: " << y );
    this->xCord = x;
    this->yCord = y;
}

int FakeTurtle::GetX () const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (this->xCord);
}

int FakeTurtle::GetY () const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (this->yCord);
}

std::string FakeTurtle::name () const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    std::stringstream ss;
    ss << "X:"<<this->xCord<<"Y:"<<this->yCord<<"DEG:"<<this->deg<<"DIST:"<<this->dist;
    LOG4CXX_DEBUG(logger , ss.str());
    return ss.str();
}

std::string FakeTurtle::getArbitraryString ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    std::stringstream ss;
    ss << "X:"<<this->xCord<<"Y:"<<this->yCord<<"DEG:"<<this->deg<<"DIST:"<<this->dist;
    LOG4CXX_DEBUG(logger , ss.str());
    return ss.str();
}

bool FakeTurtle::IsActive ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (true);
}
