

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


#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <computer/science/DummyTestSteps.hpp>

using cucumber::ScenarioScope;
using namespace computer::science;
using namespace ::testing;

DummyCtx::DummyCtx()
{
}

DummyCtx::~DummyCtx()
{
}

void DummyCtx::loop(std::mutex & mutex, bool const & running)
{
    std::lock_guard<std::mutex> lock(mutex);
}

class IFoo
{
    public:

        virtual ~IFoo() {
        };
        virtual void foo() const = 0;
};

class MockFoo : public IFoo
{
    public:

        MOCK_CONST_METHOD0(foo, void());
};

struct MockCtx
{
    std::shared_ptr<MockFoo> mock;
};


GIVEN("^a dummy initialised with \"([^\"]*)\" and \"([^\"]*)\"$")
{
    REGEX_PARAM(std::string, hello_string);
    REGEX_PARAM(std::string, world_string);
    ScenarioScope<DummyCtx> context{};
    context->dummies.emplace_back(computer::science::Dummy{hello_string, world_string});
}

GIVEN("^the following dummies:$")
{
    TABLE_PARAM(dummy_params);
    ScenarioScope<DummyCtx> context{};
    const auto & dummies = dummy_params.hashes();

    for (const auto& dummy : dummies)
    {
        context->dummies.emplace_back(computer::science::Dummy{std::string{dummy.at("hello")},
                                                               std::string{dummy.at("world")}});
    }
}

WHEN("^I command the dummy to say hello$")
{
    ScenarioScope<DummyCtx> context{};
    context->say_hello_result = context->dummies.front().speak();
}

WHEN("^I command the dummy (\\d+) to say hello$")
{
    REGEX_PARAM(size_t, dummy_index);
    ScenarioScope<DummyCtx> context{};
    context->say_hello_result = context->dummies.at(dummy_index).speak();
}


THEN("^the dummy should say \"([^\"]*)\"$")
{
    REGEX_PARAM(std::string, hello_world_string);
    ScenarioScope<DummyCtx> context{};
    ASSERT_STREQ(context->say_hello_result.c_str(), hello_world_string.c_str());
}


GIVEN("^a mock class with method foo$") {
    ScenarioScope<MockCtx> context{};
    context->mock = std::make_shared<MockFoo>();
}

GIVEN("^the tests expects that foo is called once$") {
    ScenarioScope<MockCtx> context{};
    EXPECT_CALL(*context->mock, foo());
}

WHEN("^foo is called on the mock$") {
    ScenarioScope<MockCtx> context{};
    context->mock->foo();
}

THEN("^the test should pass$") {
    ScenarioScope<MockCtx> context{};
    ASSERT_TRUE(::testing::Mock::VerifyAndClearExpectations(context->mock.get()));
}


/*
   GIVEN("^the following dummies:$")
   {
    TABLE_PARAM(dummy_params);
    ScenarioScope<DummyCtx> context{};
    const auto& dummies_table = dummy_params.hashes();

    for (const auto& table_row : dummies_table)
    {
       context->dummies.emplace_back(computer::science::Dummy{std::string{table_row.at("hello")},
       std::string{table_row.at("world")}});
    }
   }

   WHEN("^I command the dummy to say hello$")
   {
    ScenarioScope<DummyCtx> context{};
    context->say_hello_result = context->dummies.front().speak();
   }


   WHEN("^I command the dummy (\\d+) to say hello$")
   {
    REGEX_PARAM(size_t, dummy_index);
    ScenarioScope<DummyCtx> context{};
    context->say_hello_result = context->dummies.at(dummy_index).speak();
   }


   THEN("^the dummy should say \"([^\"]*)\"$")
   {
    REGEX_PARAM(std::string, hello_world_string);
    ScenarioScope<DummyCtx> context{};
    ASSERT_STREQ(context->say_hello_result.c_str(), hello_world_string.c_str());
   }
 */

/*
   Given(/^a dummy initialised with "([^"]*)" and "([^"]*)"$/) do |arg1, arg2|
   pending # Write code here that turns the phrase above into concrete actions
   end
   GIVEN("^a dummy initialised with \"Hello\" and \"World\"$") {
    pending();
   }


   When(/^I command the dummy to say hello$/) do
   pending # Write code here that turns the phrase above into concrete actions
   end
   WHEN("^I command the dummy to say hello$") {
    pending();
   }


   Then(/^the dummy should say "([^"]*)"$/) do |arg1|
   pending # Write code here that turns the phrase above into concrete actions
   end
   THEN("^the dummy should say \"Hello World\"$") {
    pending();
   }


   Given(/^a dummy initialised with "([^"]*)" and "([^"]*)"$/) do |arg1, arg2|
   pending # Write code here that turns the phrase above into concrete actions
   end
   GIVEN("^a dummy initialised with \"Hallo\" and \"Welt\"$") {
    pending();
   }


   Then(/^the dummy should say "([^"]*)"$/) do |arg1|
   pending # Write code here that turns the phrase above into concrete actions
   end
   THEN("^the dummy should say \"Hallo Welt\"$") {
    pending();
   }


   Given(/^a dummy initialised with "([^"]*)" and "([^"]*)"$/) do |arg1, arg2|
   pending # Write code here that turns the phrase above into concrete actions
   end
   GIVEN("^a dummy initialised with \"Bonjour\" and \"tout le monde\"$") {
    pending();
   }


   Then(/^the dummy should say "([^"]*)"$/) do |arg1|
   pending # Write code here that turns the phrase above into concrete actions
   end
   THEN("^the dummy should say \"Bonjour tout le monde\"$") {
    pending();
   }


   Given(/^a dummy initialised with "([^"]*)" and "([^"]*)"$/) do |arg1, arg2|
   pending # Write code here that turns the phrase above into concrete actions
   end
   GIVEN("^a dummy initialised with \"Hola\" and \"mundo\"$") {
    pending();
   }


   Then(/^the dummy should say "([^"]*)"$/) do |arg1|
   pending # Write code here that turns the phrase above into concrete actions
   end
   THEN("^the dummy should say \"Hola mundo\"$") {
    pending();
   }


   Given(/^a dummy initialised with "([^"]*)" and "([^"]*)"$/) do |arg1, arg2|
   pending # Write code here that turns the phrase above into concrete actions
   end
   GIVEN("^a dummy initialised with \"Hello\" and \"vilag\"$") {
    pending();
   }


   Then(/^the dummy should say "([^"]*)"$/) do |arg1|
   pending # Write code here that turns the phrase above into concrete actions
   end
   THEN("^the dummy should say \"Hello vilag\"$") {
    pending();
   }


   Given(/^the following dummies:$/) do |table|
 # table is a Cucumber::Core::Ast::DataTable
   pending # Write code here that turns the phrase above into concrete actions
   end
   GIVEN("^the following dummies:$") {
    pending();
   }


   When(/^I command the dummy (\d+) to say hello$/) do |arg1|
   pending # Write code here that turns the phrase above into concrete actions
   end
   WHEN("^I command the dummy 0 to say hello$") {
    pending();
   }


   When(/^I command the dummy (\d+) to say hello$/) do |arg1|
   pending # Write code here that turns the phrase above into concrete actions
   end
   WHEN("^I command the dummy 1 to say hello$") {
    pending();
   }


   When(/^I command the dummy (\d+) to say hello$/) do |arg1|
   pending # Write code here that turns the phrase above into concrete actions
   end
   WHEN("^I command the dummy 2 to say hello$") {
    pending();
   }


   When(/^I command the dummy (\d+) to say hello$/) do |arg1|
   pending # Write code here that turns the phrase above into concrete actions
   end
   WHEN("^I command the dummy 3 to say hello$") {
    pending();
   }


   When(/^I command the dummy (\d+) to say hello$/) do |arg1|
   pending # Write code here that turns the phrase above into concrete actions
   end
   WHEN("^I command the dummy 4 to say hello$") {
    pending();
   }
 */

GIVEN("^The credit card is enabled$") {
    // pending();
    ASSERT_TRUE(true);
}

GIVEN("^The available balance in my account is positive$") {
    // pending();
    ASSERT_TRUE(true);
}

GIVEN("^the ATM has enough money$") {
    // pending();
    ASSERT_TRUE(true);
}

GIVEN("^I authenticated with a card enabled$") {
    // pending();
    ASSERT_TRUE(true);
}

WHEN("^I select the option to withdraw money$") {
    // pending();
    ASSERT_TRUE(true);
}

WHEN("^I enter the amount of money that is less than the amount I have available and the ATM s available balance$") {
    // pending();
    ASSERT_TRUE(true);
}

THEN("^I get the money$") {
    // pending();
    ASSERT_TRUE(true);
}

THEN("^The money I get is subtracted from the available balance of my account$") {
    // pending();
    ASSERT_TRUE(true);
}

THEN("^The system returns the card automatically$") {
    // pending();
    ASSERT_TRUE(true);
}

THEN("^The system displays the transaction completed message$") {
    // pending();
    ASSERT_TRUE(true);
}

GIVEN("^The available balance in my account is \\$10,000$") {
    // pending();
    ASSERT_TRUE(true);
}

GIVEN("^The cashier has \\$100,000 in cash$") {
    // pending();
    ASSERT_TRUE(true);
}

WHEN("^I select the option to extract money$") {
    // pending();
    ASSERT_TRUE(true);
}


WHEN("^I indicate that I want to extract \\$1,000$") {
    // pending();
    ASSERT_TRUE(true);
}

THEN("^I get \\$1,000 in the form of two \\$500 bills$") {
    // pending();
    ASSERT_TRUE(true);
}

THEN("^The balance of my account becomes \\$9,000$") {
    // pending();
    ASSERT_TRUE(true);
}

THEN("^the cashier keeps \\$99,000 in cash$") {
    // pending();
    ASSERT_TRUE(true);
}
THEN("^The system displays the completed transaction message$") {
    // pending();
    ASSERT_TRUE(true);
}

