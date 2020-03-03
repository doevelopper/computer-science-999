

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_JSONHELPER_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_JSONHELPER_HPP

#include <string>
#include <computer/science/LoggingService.hpp>
#include <rapidjson/document.h>

namespace computer::science::pluralsight::mocking
{
    class JsonHelper
    {
        public:

            JsonHelper() = default;
            JsonHelper(const JsonHelper&) = default;
            JsonHelper(JsonHelper&&) = default;
            JsonHelper& operator=(const JsonHelper&) = default;
            JsonHelper& operator=(JsonHelper&&) = default;
            virtual ~JsonHelper() = default;

            static std::string getMatchingTitleIdFromMovieList(const std::string& title, const std::string& jsonString);

        protected:

        private:

            static const rapidjson::Value& findMovieByTitle(const std::string& title,
                                                            rapidjson::GenericValue<rapidjson::UTF8<> >::Array results);
            static log4cxx::LoggerPtr logger;
    };
}
#endif

