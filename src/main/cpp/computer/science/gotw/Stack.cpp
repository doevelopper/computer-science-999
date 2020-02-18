#include <cppbdd101/lectures/gotw/Stack.hpp>

template <class T>
log4cxx::LoggerPtr Stack<T>::logger = log4cxx::Logger::getLogger(std::string("cppbdd101.lectures.gotw.Stack"));

template <class T>
Stack<T>::Stack()  noexcept
{
}

template <class T>
Stack<T>::Stack(std::size_t capacity) 
:  StackException<T>(capacity)
{
}

template <class T>
Stack<T>::~Stack()  noexcept
{
}

template <class T>
std::size_t Stack<T>::size() const noexcept 
{ 
    return m_size; 
}

template <class T>
std::size_t Stack<T>::capacity() const noexcept 
{ 
    return m_capacity; 
}

template <class T>
bool Stack<T>::empty() const noexcept 
{ 
    return size() == 0; 
}

template <class T>
Stack<T>::Stack(const Stack& other)
noexcept(std::is_nothrow_copy_constructible<T>::value) 
: StackException<T>(other.m_capacity)
{
    for (std::size_t pos = 0; pos < other.m_size; ++pos)
    {
        constructAt(pos, other.m_data[pos]);
        ++m_size;
    }
}

template <class T>
Stack<T>& Stack<T>::operator=(Stack<T> s)
noexcept(std::is_nothrow_copy_constructible<T>::value)
{
	swap(s);
	return *this;
}

template <class T>
Stack<T>& Stack<T>::operator=(Stack<T>&& s)
noexcept(std::is_nothrow_move_constructible<T>::value)
{
	swap(s);
	return *this;
}

template <class T>
void Stack<T>::push(const T& t)
{
	if (m_size == m_capacity)
	{
		reserve((m_capacity + 1) * 2);
	}

	LOG4CXX_ASSERT(logger,m_capacity > m_size,"m_capacity > m_size");

	m_data[m_size] = t;
	++m_size;
}

template <class T>
template <class... Args>
void Stack<T>::emplace(Args&&... args)
{
	if (m_size == m_capacity)
	{
		reserve((m_capacity + 1) * 2);
	}

	        LOG4CXX_ASSERT(logger,m_capacity > m_size,"m_capacity > m_size");

	constructAt(m_size, std::forward<Args>(args)...);
	++m_size;
}

template <class T>
void Stack<T>::reserve(std::size_t new_capacity)
{
	LOG4CXX_ASSERT(logger,new_capacity >= m_capacity,"new_capacity >= m_capacity");

	Stack<T> new_stack(new_capacity);
	for (std::size_t pos = 0; pos < m_size; ++pos)
	{
		new_stack.constructAt(pos, std::move_if_noexcept(m_data[pos]));
		++new_stack.m_size;
	}

	swap(new_stack);
}

template <class T>
typename Stack<T>::reference Stack<T>::top()
{
	if (empty())
	{
		throw std::runtime_error("empty container");
	}

	return m_data[m_size - 1];
}

template <class T>
typename Stack<T>::constReference Stack<T>::top() const
{
	return const_cast<Stack<T>&>(*this).top();
}

template <class T>
T Stack<T>::pop()
{
	if (empty())
	{
		throw std::runtime_error("empty container");
	}

	const T elem = m_data[m_size - 1];
	--m_size;

	return elem;
}
