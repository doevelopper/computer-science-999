

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_THEMOVIEDBDATAFACTORY_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_THEMOVIEDBDATAFACTORY_HPP

#include <computer/science/pluralsight/mocking/MovieDataFactory.hpp>
#include <computer/science/LoggingService.hpp>
namespace computer::science::pluralsight::mocking
{
    class TheMovieDbDataFactory : public MovieDataFactory
    {
        public:

            TheMovieDbDataFactory();
            ~TheMovieDbDataFactory();

            std::shared_ptr<MovieData> createFromJson(const std::string& jsonString) const override;

        protected:

        private:

            static log4cxx::LoggerPtr logger;
    };
}

#endif

