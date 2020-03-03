

#ifndef CPPBDD101_SINGLETONTEST_HPP
#define CPPBDD101_SINGLETONTEST_HPP


#include <gtest/gtest.h>
#include <boost/shared_ptr.hpp>
#include <cppbdd101/Singleton.hpp>
#include <log4cxx/logger.h>


namespace cppbdd101
{
    // see
    // https://github.com/google/googletest/blob/master/googletest/docs/AdvancedGuide.md#how-to-write-value-parameterized-tests
    class SingletonTest : public ::testing::Test
        , public ::testing::WithParamInterface<Singleton>                                          //: public
                                                                                                   // Singleton<SingletonTest
                                                                                                   // >
    {
        public:

            SingletonTest();
            SingletonTest(const SingletonTest&) = delete;
            SingletonTest(SingletonTest&&) = delete;
            SingletonTest& operator=(const SingletonTest&) = delete;
            SingletonTest& operator=(SingletonTest&&) = delete;
            virtual ~SingletonTest();

            virtual void SetUp ();
            virtual void TearDown ();

        protected:

            cpp101::Singleton *       singleton;
            static log4cxx::LoggerPtr logger;
    };
}

#endif

