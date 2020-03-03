

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_FAKEMOVIEMETADATAREPOSITORY_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_FAKEMOVIEMETADATAREPOSITORY_HPP

#include <gmock/gmock.h>
#include <computer/science/pluralsight/mocking/MovieMetaDataRepository.hpp>

namespace computer::science::pluralsight::mocking
{
    class FakeMovieMetaDataRepository : public MovieMetaDataRepository
    {
        public:

            MOCK_METHOD1(findMovieData, std::shared_ptr<MovieData>(const std::string& movieName));
    };
}

#endif

