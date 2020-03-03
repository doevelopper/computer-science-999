

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_RESTAPICLIENT_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_RESTAPICLIENT_HPP

#include <string>
#include <computer/science/LoggingService.hpp>

namespace computer::science::pluralsight::mocking
{
    class RestApiClient
    {
        public:

            RestApiClient();
            ~RestApiClient();

            std::string httpGet(std::string& url);

        protected:

        private:

            std::string               m_buffer;
            static log4cxx::LoggerPtr logger;
    };
}

#endif

