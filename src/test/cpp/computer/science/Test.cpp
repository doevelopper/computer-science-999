

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


#include <computer/science/Test.hpp>

using namespace computer::science::test;

log4cxx::LoggerPtr Test::logger = log4cxx::Logger::getLogger(std::string("computer.science.test.Test") );
const unsigned long Test::LOGGER_WATCH_DELAY = 5000UL;


Test::Test()
    : m_testSuites(std::string() )
    , m_numberOfTestIteration(1)
    , m_loggerService(new LoggingService(LOGGER_WATCH_DELAY))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Test::Test(std::string & suite, unsigned int iteration)
    : m_testSuites(suite)
    , m_numberOfTestIteration(iteration)
    //    , m_loggerService(new LoggingService(LOGGER_WATCH_DELAY))
{
    ///    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Test::~Test()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    delete this->m_loggerService;
}

int Test::run (int argc, char * argv[])
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

void Test::showUsage(std::string name)
{
    LOG4CXX_TRACE(logger,"Usage called");

    std::cerr << "Usage: " << name << " <option(s)> SOURCES \n"
              << "Options:\n"
              << "\t-h,--help \t Show this help message\n"
              << "\t-i,--iterration \t Number of iteration on test Default 1\n"
              << "\t-o,--outputpath \t Specify the destination path Default netx to executable\n"
              << "\t-m,--module \t The name of xml test report to be generated\n"
              << "\t-l,--list \t Specify the list of tests to be executed Default netx to executable\n"
              << std::endl;
}

