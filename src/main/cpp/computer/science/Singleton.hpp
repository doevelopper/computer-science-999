#ifndef CPPBDD101_SINGLETON_HPP
#define CPPBDD101_SINGLETON_HPP

#include <memory>

#include <cppbdd101/SingletonFactory.hpp>

template <typename T>
class Singleton
{
    friend class SingletonFactory<T>;

protected:

    Singleton();
    Singleton & operator=(const Singleton & rsh);

public:

    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
    virtual ~Singleton();

    static T* instance()
    {
	return mp_Instance.get();
    }

protected:

    static std::auto_ptr<T> mp_Instance;

};

template <typename T> 
std::auto_ptr<T> Singleton<T>::mp_Instance;

#endif

