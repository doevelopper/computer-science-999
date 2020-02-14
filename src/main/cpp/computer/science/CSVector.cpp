

#include <computer/science/CSVector.hpp>

using namespace computer::science;

void CSVector::add(size_t num)
{
    m_items.push_back(num);
}

std::size_t CSVector::count() const
{
    return m_items.size();
}

void CSVector::loop(functorIterator funcIt) const
{
    for(const std::size_t item: m_items)
    {
        funcIt(item);
    }
}

