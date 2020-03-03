

#include <chrono>
#include <thread>

#include <computer/science/ContainerTest.hpp>
#include <computer/science/CSVector.hpp>
#include <computer/science/CSList.hpp>
#include <computer/science/CSQueue.hpp>

using namespace computer::science;
using namespace computer::science::test;

template <typename V>
log4cxx::LoggerPtr ContainerTest<V>::logger = log4cxx::Logger::getLogger(std::string(
                                                                             "computer::science::test.ContainerTest"));

template <typename V>
ContainerTest<V>::ContainerTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
ContainerTest<V>::~ContainerTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
void ContainerTest<V>::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
void ContainerTest<V>::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TYPED_TEST_P(ContainerTest, ShouldBeEmptyOnStartup)
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);
    TypeParam container;
    ASSERT_EQ(container.count(), 0);
}

TYPED_TEST_P(ContainerTest, ShouldAdd1)
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);
    TypeParam container;
    container.add(1);
    ASSERT_EQ(container.count(), 1);
}


TYPED_TEST_P(ContainerTest, ShouldIterate)
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);
    TypeParam container;
    container.add(1);
    container.add(2);
    container.add(3);

    std::vector<size_t> verification;
    auto proc = [&verification, &container] (const size_t item) -> void {
                    verification.push_back(item);
                };

    container.loop(proc);

    ASSERT_EQ(verification.size(), 3);
    ASSERT_EQ(verification[0], 1);
    ASSERT_EQ(verification[1], 2);
    ASSERT_EQ(verification[2], 3);
}

REGISTER_TYPED_TEST_CASE_P(ContainerTest,
                           ShouldBeEmptyOnStartup,
                           ShouldAdd1,
                           ShouldIterate
                           );

INSTANTIATE_TYPED_TEST_CASE_P(DifferentContainerTypes, ContainerTest, ContainerTypes);

