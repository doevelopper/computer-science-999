

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_STRINGHTMLENCODER_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_STRINGHTMLENCODER_HPP
#include <string>
#include <computer/science/LoggingService.hpp>
namespace computer::science::pluralsight::mocking
{
    class StringHtmlEncoder
    {
        public:

            static std::string encode(const std::string& input);

        protected:

        private:

            static log4cxx::LoggerPtr logger;
    };
}

#endif

