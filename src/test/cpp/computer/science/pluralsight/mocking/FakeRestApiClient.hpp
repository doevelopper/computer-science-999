

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_FAKERESTAPICLIENT_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_FAKERESTAPICLIENT_HPP

#include <gmock/gmock.h>
#include <computer/science/pluralsight/mocking/RestApiClient.hpp>

namespace computer::science::pluralsight::mocking
{
    class FakeRestApiClient : public RestApiClient
    {
        public:

            MOCK_METHOD1(httpGet, std::string(std::string&));
    };
}

#endif

