
#include <cppbdd101/lectures/ggltest/SimpleTest.hpp>
log4cxx::LoggerPtr SimpleTest::logger = log4cxx::Logger::getLogger(std::string("cppbdd101.lectures.ggltest.SimpleTest"));
SimpleTest::SimpleTest() 
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

SimpleTest::~SimpleTest() 
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void SimpleTest::SetUp ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
//    objectUnderTest = new Simple();
}

void SimpleTest::TearDown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
//    delete objectUnderTest;
}

TEST_F(SimpleTest, testCase_fatal_fail_FAIL)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    LOG4CXX_WARN(logger , "The fatal error stops executing a test.");
    FAIL()<< "This is a optional description for the fatal error";
    LOG4CXX_FATAL(logger , "This will not be displayed, because the fatal error was before.");
}

TEST_F(SimpleTest, testCase_nonfatal_fail_FAIL)
{
  LOG4CXX_WARN(logger , "The non fatal error doesn't stop executing test.");
  ADD_FAILURE()<< "This is a optional description for the nonfatal error";
  LOG4CXX_WARN(logger , "This will be displayed, because there wasn't be a fatal error before.");
}

TEST_F(SimpleTest, testCase_ASSERT_simple)
{
    LOG4CXX_INFO(logger , "GTest has several types of asserts: ASSERT_xxx and EXPECT_xxx.");    
    LOG4CXX_INFO(logger , "ASSERT_xxx - if assert is failing, the test will stop with failure immediately - there will be a fatal error."); 
    LOG4CXX_INFO(logger , "EXPECT_xxx - if assert is failing, the test will fail, but not immediately - there will be a nonfatal error.");
    const int expectedResult = 15;
    const int actualResult = 42;//objectUnderTest.add(5);
    ASSERT_EQ(expectedResult, actualResult);// << "The optional description that will be displayed if this test failed";
    ASSERT_EQ(expectedResult, actualResult);
    ASSERT_GT(20, actualResult); //<< "ASSERT_GT is: 20 > actualResult";
    LOG4CXX_TRACE(logger ,"ASSERT_GE is: 20 >= actualResult.");
    ASSERT_GE(20, actualResult);
    ASSERT_GE(expectedResult, actualResult);

    LOG4CXX_TRACE(logger ,"ASSERT_LT is: 0 < actualResult");
    ASSERT_LT(0, actualResult);

    LOG4CXX_TRACE(logger ,"ASSERT_LE is: 0 <= actualResult");
    ASSERT_LE(0, actualResult);
    ASSERT_LE(expectedResult, actualResult);

    LOG4CXX_TRACE(logger ,"Test if the value in bracket is true.");
    ASSERT_TRUE(expectedResult == actualResult);

    LOG4CXX_TRACE(logger ,"Test if the value in bracket is false.");
    ASSERT_FALSE(expectedResult != actualResult);

    const int nearExpectedResult = 13;
    const int near = 2;
    LOG4CXX_TRACE(logger ,"you can also provide interval: (nearExpectedResult - near) <= actualResult <= (nearExpectedResult + near)");
    ASSERT_NEAR(nearExpectedResult, actualResult, near);
}

TEST_F(SimpleTest, testCase_ASSERT_string)
{
  LOG4CXX_TRACE(logger ,"simple assert for string");
  const char* expectedResult = "abc";
  const char* actualResult = "remove";//objectUnderTest.getCStyleString();

  LOG4CXX_TRACE(logger ,"Compares C-style strings (case sensitivity)");
  ASSERT_STREQ(expectedResult, actualResult);

  const char* notExpectedResult = "def";
  LOG4CXX_TRACE(logger ,"Compares C-style strings - if there are NOT equal. (case sensitivity)");
  ASSERT_STRNE(notExpectedResult, actualResult);

  const char* caseIndependentExpectedResult = "AbC";
  LOG4CXX_TRACE(logger ,"Compares C-style strings (case insensitivity)");
  ASSERT_STRCASEEQ(caseIndependentExpectedResult, actualResult);

  const char* notCaseIndependentExpectedResult = "DeF";
  LOG4CXX_TRACE(logger ,"Compares C-style strings - if there are NOT equal. (case insensitivity)");
  ASSERT_STRCASENE(notCaseIndependentExpectedResult, actualResult);
}

TEST_F(SimpleTest, testCase_ASSERT_doubles)
{
    LOG4CXX_TRACE(logger ,"simple assert for double");
    const double expectedResult = 1;
    LOG4CXX_TRACE(logger ,"sum of 0.1 is not equal 1, because of binary representation of double and float.");
    double actualResult = 0;
    for (int i = 0; i < 10; ++i)
    {
        actualResult += 0.1;
    }
    LOG4CXX_TRACE(logger ,"Checks if 10 * 0.1 != 1.");
    ASSERT_NE(expectedResult, actualResult);
    LOG4CXX_TRACE(logger ,"It should be ASSERT_DOUBLE_EQ used instead of ASSERT_EQ.");
    ASSERT_DOUBLE_EQ(expectedResult, actualResult);
    LOG4CXX_TRACE(logger ,"There is also ASSERT_DOUBLE_NE - to check if is not equal."); 
    LOG4CXX_TRACE(logger ,"For float type, you should use ASSERT_FLOAT_EQ, ASSERT_FLOAT_NE.");
}

TEST_F(SimpleTest, DISABLED_testCase_ASSERT_doubles) 
{
    // this test will not run. However it will be shown: YOU HAVE 1 DISABLED TEST
    LOG4CXX_FATAL(logger ,"Disabled test");
    FAIL();
}
