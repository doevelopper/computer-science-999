#ifndef COMPUTER_SCIENCE_COPYABLEANDMOVABLE_HPP
#define COMPUTER_SCIENCE_COPYABLEANDMOVABLE_HPP

namespace computer::science
{
class CopyableAndMovable
{
public:
    CopyableAndMovable();
    CopyableAndMovable(const CopyableAndMovable& orig);
    CopyableAndMovable(CopyableAndMovable&& orig);
    CopyableAndMovable & operator=(const CopyableAndMovable& orig);
    CopyableAndMovable & operator=(CopyableAndMovable && orig);
    virtual ~CopyableAndMovable();
protected:
private:

};
}
#endif

