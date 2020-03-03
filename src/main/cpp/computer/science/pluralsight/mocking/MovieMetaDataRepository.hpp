

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_MOVIEMETADATAPOSITORY_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_MOVIEMETADATAPOSITORY_HPP

#include <memory>
#include <computer/science/pluralsight/mocking/MovieData.hpp>
namespace computer::science::pluralsight::mocking
{
    class MovieMetaDataRepository
    {
        public:

            MovieMetaDataRepository(){
            }

            virtual ~MovieMetaDataRepository(){
            };

            virtual std::shared_ptr<MovieData> findMovieData(const std::string& movieName) = 0;
    };
}

#endif

