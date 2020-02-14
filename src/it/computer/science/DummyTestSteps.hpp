

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
    std::vector<computer::science::Dummy> dummies{};
    std::string say_hello_result{};
    void loop(std::mutex & mutex, bool const & running);
};


#endif

