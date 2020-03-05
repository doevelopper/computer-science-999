

#ifndef CPPBDD101_FEATURES_STEP_DEFINITIONS_DUMMYTESTSTEPS_HPP
#define CPPBDD101_FEATURES_STEP_DEFINITIONS_DUMMYTESTSTEPS_HPP

#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <functional>

#include <gtest/gtest.h>

#include <cucumber-cpp/autodetect.hpp>

#include <computer/science/Dummy.hpp>

struct DummyCtx
{
    DummyCtx();
    ~DummyCtx();
    std::vector<computer::science::Dummy> dummies{};
    std::string say_hello_result{};
    void loop(std::mutex & mutex, bool const & running);
};


#endif

