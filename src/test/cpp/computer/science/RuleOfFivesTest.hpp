

#ifndef RULEOFFIVESTEST_HPP
#define RULEOFFIVESTEST_HPP

#include <gtest/gtest.h>
#include <cppbdd101/lectures/CopyableAndMovable.hpp>
#include <cppbdd101/lectures/CopyableOnly.hpp>
#include <cppbdd101/lectures/MovableOnly.hpp>
#include <cppbdd101/lectures/NonCopyableNorMovable.hpp>

class RuleOfFivesTest
    : public ::testing::Test
{
    public:

        RuleOfFivesTest();
        virtual ~RuleOfFivesTest();
        virtual void SetUp();
        virtual void TearDown ();

    private:
};

#endif

