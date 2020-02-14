

#include <computer/science/CSList.hpp>

using namespace computer::science;

void CSList::add(size_t num)
{
    m_items.push_back(num);
}

std::size_t CSList::count() const
{
    return m_items.size();
}

void CSList::loop(functorIterator funcIt) const
{
    for(const std::size_t item: m_items)
    {
        funcIt(item);
    }
}

