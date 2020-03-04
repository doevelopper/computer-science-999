

#ifndef CPPBDD101_LECTURES_GGLTEST_TURTLE_HPP
#define CPPBDD101_LECTURES_GGLTEST_TURTLE_HPP

class Turtle
{
    public:

        Turtle();
        Turtle(const Turtle & orig);
        Turtle(Turtle &&) = delete;
        Turtle & operator = (Turtle const &) = delete;
        Turtle & operator = (Turtle &&) = delete;
        virtual ~Turtle();

        virtual void PenUp () = 0;
        virtual void PenDown () = 0;
        virtual void Forward (int distance) = 0;
        virtual void Turn (int degrees) = 0;
        virtual void GoTo (int x, int y) = 0;
        virtual int GetX () const = 0;
        virtual int GetY () const = 0;
        virtual std::string name () const = 0;
        virtual std::string getArbitraryString () = 0;
        virtual bool IsActive () = 0;

    private:

        log4cxx::LoggerPtr logger;
};


#endif

