
#ifndef COMPUTER_SCIENCE_MOVABLEONLY_HPP
#define COMPUTER_SCIENCE_MOVABLEONLY_HPP

namespace computer::science
{
class MovableOnly
{
public:
    MovableOnly();
    MovableOnly(const MovableOnly& orig) = delete;
    MovableOnly(MovableOnly&& orig);
    MovableOnly & operator=(const MovableOnly& orig) = delete;
    MovableOnly & operator=(MovableOnly && orig);
    virtual ~MovableOnly();
private:

};
}
#endif

