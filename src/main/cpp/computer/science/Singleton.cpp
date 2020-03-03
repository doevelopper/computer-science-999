

#include <cppbdd101/Singleton.hpp>

template <typename T>
Singleton<T>::Singleton()
{
}

template <typename T>
Singleton<T> & Singleton<T>::operator=(const Singleton & rsh)
{
    return *this;
}

template <typename T>
Singleton<T>::~Singleton()
{
}

