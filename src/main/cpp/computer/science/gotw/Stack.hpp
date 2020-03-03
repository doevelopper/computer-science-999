

#ifndef CPPBDD101_LECTURES_GOTW_STACK_HPP
#define CPPBDD101_LECTURES_GOTW_STACK_HPP

#include <cppbdd101/lectures/gotw/StackException.hpp>

template <class T>
class Stack : private StackException<T>
{
    using StackException<T>::m_size;
    using StackException<T>::m_capacity;
    using StackException<T>::m_data;
    using StackException<T>::swap;
    using StackException<T>::constructAt;

    public:

        using valueType = T;
        using reference = T&;
        using constReference = const T&;
        using sizeType = std::size_t;

        Stack() noexcept;
        virtual ~Stack() noexcept;
        Stack(const Stack&) noexcept(std::is_nothrow_copy_constructible<T>::value);
        Stack& operator=(Stack) noexcept(std::is_nothrow_copy_constructible<T>::value);

        Stack(Stack&&) noexcept(std::is_nothrow_move_constructible<T>::value);
        Stack& operator=(Stack&&) noexcept(std::is_nothrow_move_constructible<T>::value);

        sizeType size() const noexcept;
        sizeType capacity() const noexcept;
        bool empty() const noexcept;

        reference top();
        constReference top() const;

        void push(const T&);
        template <class ... Args> void emplace(Args&&...);
        T pop();
        void reserve(sizeType);

    private:

        Stack(sizeType capacity);
        /*!
         * @brief Class logger.
         */
        static log4cxx::LoggerPtr logger;
};
#endif

