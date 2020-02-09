#ifndef COMPUTER_SCIENCE_DUMMYTESTSTEPS_HPP
#define COMPUTER_SCIENCE_DUMMYTESTSTEPS_HPP

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
    std::vector<cpp101::Dummy> dummies{};
    std::string say_hello_result{};
	void loop(std::mutex & mutex, bool const & running);
};


#endif
