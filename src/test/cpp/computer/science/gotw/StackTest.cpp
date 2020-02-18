#include <cppbdd101/lectures/gotw/StackTest.hpp>

log4cxx::LoggerPtr StackTest::logger = log4cxx::Logger::getLogger(std::string("cppbdd101.lectures.gotw.StackTest"));

StackTest::StackTest()
: stack(nullptr)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

StackTest::~StackTest() 
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void StackTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //stack = new Stack<int>();
}

void StackTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete stack;
}

/*
TEST_F(StackTest, init)
{
	EXPECT_TRUE(_s.empty());
	EXPECT_EQ(0u, _s.size());
}

TEST_F(StackTest, push_once)
{
	_s.push(1);
	EXPECT_EQ(1u, _s.size());
}

TEST_F(StackTest, push_multiples)
{
	_s.push(1);
	_s.push(2);
	_s.push(3);
	_s.push(4);
	EXPECT_EQ(4u, _s.size());
	EXPECT_EQ(4, _s.pop());
}

TEST_F(StackTest, push_many)
{
	static const int ElementsCount = 100000;
	for (int i = 0; i < ElementsCount; ++i)
	{
		_s.push(i);
	}

	EXPECT_EQ(ElementsCount, _s.size());
	for (std::size_t i = 0; i < ElementsCount; ++i)
	{
		EXPECT_EQ(ElementsCount - i - 1, _s.pop());
	}
	EXPECT_EQ(0, _s.size());
	EXPECT_TRUE(_s.empty());
}

TEST_F(StackTest, pop)
{
	_s.push(1);
	EXPECT_EQ(1, _s.pop());
	EXPECT_TRUE(_s.empty());

	_s.push(1);
	_s.push(2);
	_s.push(3);
	EXPECT_EQ(3, _s.pop());
	EXPECT_FALSE(_s.empty());
	EXPECT_EQ(2, _s.size());
}

TEST_F(StackTest, pop_throw)
{
	EXPECT_THROW(_s.pop(), std::runtime_error);
}

TEST_F(StackTest, copy_ctor_empty)
{
	auto s = _s;
	EXPECT_TRUE(s.empty());
}
*/