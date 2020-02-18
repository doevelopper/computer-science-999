

#include <iostream>
#include <cstdlib>

#include <computer/science/Test.hpp>

int main(int argc, char**argv)
{
    computer::science::test::Test csTest;

#if !defined(HAVE_LOG4CXX)

    std::cout << "TEST CPP-101: C++ Object Oriented Programming!" << std::endl;
    std::cout << "Simple and obvious Unit test frameworks" << std::endl;
    std::cout << "Each Test module should be able to have many small test cases." << std::endl;

#else

    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(),"TEST CPP-101: C++ Object Oriented Programming!");
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(),"Simple and obvious Unit test frameworks");
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(),"Each Test module should be able to have many small test cases.");
    LOG4CXX_INFO(log4cxx::Logger::getRootLogger() , __LOG4CXX_FUNC__ );

#endif

    csTest.run(argc,argv);

    return (EXIT_SUCCESS);
}

