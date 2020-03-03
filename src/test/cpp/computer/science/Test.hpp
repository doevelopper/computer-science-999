

/*
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

#ifndef COMPUTER_SCIENCE_TEST_HPP
#define COMPUTER_SCIENCE_TEST_HPP

#include <vector>
#include <gtest/gtest.h>
#include <computer/science/LoggingService.hpp>
namespace computer::science::test
{
    class Test
    {
        public:

            Test();
            Test(std::string & suite, unsigned int iteration = 1);
            Test(const Test & orig) = default;
            virtual ~Test();

            int run (int argc = 0, char * argv[] = NULL);
            static void showUsage(std::string name);

        private:

            std::string                m_testSuites;
            unsigned int               m_numberOfTestIteration;
            static const unsigned long LOGGER_WATCH_DELAY;
            LoggingService *           m_loggerService;
            /*!
             * @brief Class logger.
             */
            static log4cxx::LoggerPtr logger;
    };
}

#endif

