#ifndef CPPBDD101_FEATURES_STEP_DEFINITIONS_ITTEST_HPP
#define CPPBDD101_FEATURES_STEP_DEFINITIONS_ITTEST_HPP

#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

using cucumber::ScenarioScope;

class ItTest 
{
public:
    ItTest();
    ItTest(int argc, char* argv[]);
    ItTest(const ItTest& orig);
    virtual ~ItTest();
private:

};

#endif

