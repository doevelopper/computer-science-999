

#include <utility>
#include <cppbdd101/lectures/gotw/StackException.hpp>

template <class T>
log4cxx::LoggerPtr StackException<T>::logger = log4cxx::Logger::getLogger(std::string(
                                                                              "cppbdd101.lectures.gotw.StackException"));


template <class T>
StackException<T>::StackException() noexcept
    : m_data(nullptr)
    , m_capacity(0)
    , m_size(0)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <class T>
StackException<T>::StackException(sizeType capacity)
    : m_data(static_cast<T*>(capacity == 0 ? nullptr : operator new(sizeof(T) * capacity)))
    , m_capacity(capacity)
    , m_size(0)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <class T>
StackException<T>::~StackException() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (m_data)
    {
        //std::allocator_traits::destroy(m_data, m_data + m_size);
        operator delete(m_data);
        m_data = nullptr;
    }
    else
    {
        LOG4CXX_WARN( logger, "Data not available." );
    }
}

template <class T>
void StackException<T>::swap(StackException<T>& other)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::swap(m_data, other.m_data);
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
}

