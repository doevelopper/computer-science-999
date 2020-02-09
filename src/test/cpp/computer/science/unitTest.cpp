#include <iostream>
#include <cstdlib>

#include <computer/science/Test.hpp>

int main(int argc, char**argv)
{
    computer::science::test::Test cfsDevToolsTest;

    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(),"TEST CPP-101: !");
    LOG4CXX_INFO(log4cxx::Logger::getRootLogger() , __LOG4CXX_FUNC__ );
    cfsDevToolsTest.run(argc,argv);

    return (EXIT_SUCCESS);
}
