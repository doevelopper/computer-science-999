

#include <computer/science/pluralsight/mocking/StringHtmlEncoder.hpp>

using  namespace computer::science::pluralsight::mocking;

log4cxx::LoggerPtr StringHtmlEncoder::logger = log4cxx::Logger::getLogger(std::string(
                                                                              "computer.science.pluralsight.mocking.StringHtmlEncoder"));

std::string StringHtmlEncoder::encode(const std::string& input)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::string encodedResult;

    int start = 0;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            encodedResult.append(input, start, i - start);
            encodedResult += "%2f";
            start = i + 1;
        }
    }

    encodedResult.append(input, start, input.length());

    return encodedResult;
}

