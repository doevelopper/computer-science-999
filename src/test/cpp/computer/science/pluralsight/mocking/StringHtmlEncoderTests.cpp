

#include <gtest/gtest.h>
#include <computer/science/pluralsight/mocking/StringHtmlEncoder.hpp>
#include <computer/science/LoggingService.hpp>
using namespace computer::science::pluralsight::mocking;

static log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger(std::string(
                                                                  "computer.science.pluralsight.mocking.StringHtmlEncoderTests"));

TEST(StringHtmlEncoderTests, Encode_StringWithoutSpaces_ReturnSameString)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto result = StringHtmlEncoder::encode("1234");

    ASSERT_EQ(result, "1234");
}

TEST(StringHtmlEncoderTests, Encode_StringWithOneSpace_ReplaceSpaceWithEncoding)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto result = StringHtmlEncoder::encode("A B");

    ASSERT_EQ("A%2fB", result);
}

TEST(StringHtmlEncoderTests, Encode_StringWithMultipleSpaces_ReplaceSpacesWithEncoding)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto result = StringHtmlEncoder::encode("A B C D");

    ASSERT_EQ("A%2fB%2fC%2fD", result);
}


struct EncoderTestRow
{
    EncoderTestRow(std::string in, std::string exp)
        : input(in)
        , expected(exp)
    {
    }

    std::string input;
    std::string expected;
};

::std::ostream& operator<<(::std::ostream& os, const EncoderTestRow& row) {
    return os << "input:" << row.input << " expected result: " << row.expected;
}

class StringHtmlEncoderTests : public ::testing::TestWithParam<EncoderTestRow>
{
};

TEST_P(StringHtmlEncoderTests, EncodeStringToHtml)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    auto row = GetParam();

    auto result = StringHtmlEncoder::encode(row.input);

    ASSERT_EQ(row.expected, result);
}

INSTANTIATE_TEST_CASE_P(WhiteSpaceEncoding, StringHtmlEncoderTests, ::testing::Values(
                            EncoderTestRow("A", "A"),
                            EncoderTestRow("A B", "A%2fB"),
                            EncoderTestRow("A B C D", "A%2fB%2fC%2fD")
                            ));

