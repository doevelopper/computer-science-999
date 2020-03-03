

/*!
 *      Copyright {{ year }} {{ organization }}

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing
    permissions and limitations under the License.
 */


#ifndef COMPUTER_SCIENCE_DUMMYTEST_HPP
#define COMPUTER_SCIENCE_DUMMYTEST_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <boost/shared_ptr.hpp>
#include <computer/science/Dummy.hpp>
#include <log4cxx/logger.h>

namespace computer::science::test
{
    class DummyTest : public ::testing::Test
    {
        public:

            DummyTest();
            DummyTest(const DummyTest&) = default;
            DummyTest(DummyTest&&) = default;
            DummyTest& operator=(const DummyTest&) = default;
            DummyTest& operator=(DummyTest&&) = default;
            virtual ~DummyTest();

            virtual void SetUp ();
            virtual void TearDown ();

        protected:

            computer::science::Dummy * dummy;
            static log4cxx::LoggerPtr  logger;

        private:

            //boost::shared_ptr<Dummy> dummy;
    };
}
#endif

