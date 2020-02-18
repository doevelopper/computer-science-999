
#ifndef COMPUTER_SCIENCE_NONCOPYABLENORMOVABLE_HPP
#define COMPUTER_SCIENCE_NONCOPYABLENORMOVABLE_HPP

namespace computer::science
{
class NonCopyableNorMovable
{
public:
    NonCopyableNorMovable();
    NonCopyableNorMovable(const NonCopyableNorMovable& orig) = delete;
    NonCopyableNorMovable(NonCopyableNorMovable&& orig) = delete;
    NonCopyableNorMovable & operator=(const NonCopyableNorMovable& orig) = delete;
    NonCopyableNorMovable & operator=(NonCopyableNorMovable && orig) = delete;
    virtual ~NonCopyableNorMovable() = default;
private:

};
}
#endif

