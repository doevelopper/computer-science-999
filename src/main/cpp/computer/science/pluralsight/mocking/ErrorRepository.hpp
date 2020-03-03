

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_ERRORREPOSITORY_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_ERRORREPOSITORY_HPP

#include <string>

namespace computer::science::pluralsight::mocking
{
    class ErrorRepository
    {
        public:

            virtual ~ErrorRepository() = default;

            virtual void logBadMovie(std::string movieName) = 0;
    };
}

#endif

