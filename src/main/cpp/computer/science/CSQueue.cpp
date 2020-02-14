

#include <computer/science/CSQueue.hpp>

using namespace computer::science;

void CSQueue::add(std::size_t num)
{
    m_items.push_back(num);
}

std::size_t CSQueue::count() const
{
    return m_items.size();
}

void CSQueue::loop(functorIterator funcIt) const
{
    for(const std::size_t item: m_items)
    {
        funcIt(item);
    }
}

