

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_MOVIEDATAFACTORY_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_MOVIEDATAFACTORY_HPP

#include <memory>
#include <computer/science/pluralsight/mocking/MovieData.hpp>
#include <computer/science/LoggingService.hpp>
namespace computer::science::pluralsight::mocking
{
    class MovieDataFactory
    {
        public:

            virtual ~MovieDataFactory() = default;
            virtual std::shared_ptr<MovieData> createFromJson(const std::string& jsonString) const = 0;
    };
}
#endif

