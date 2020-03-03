

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_THEMOVIEDBREPOSITORY_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_THEMOVIEDBREPOSITORY_HPP

#include <computer/science/pluralsight/mocking/MovieDataFactory.hpp>
#include <computer/science/pluralsight/mocking/MovieMetaDataRepository.hpp>
#include <computer/science/pluralsight/mocking/RestApiClient.hpp>
#include <computer/science/LoggingService.hpp>
namespace computer::science::pluralsight::mocking
{
    class TheMovieDbRepository : public MovieMetaDataRepository
    {
        public:

            TheMovieDbRepository(const std::string& apiKey, const MovieDataFactory& movieDataFactory);
            TheMovieDbRepository(const std::string& apiKey, const MovieDataFactory& movieDataFactory,
                                 RestApiClient& client);
            ~TheMovieDbRepository();

            std::shared_ptr<MovieData> findMovieData(const std::string& movieName) override;

        protected:

        private:

            RestApiClient             m_client;
            const std::string&        m_apiKey;
            const MovieDataFactory&   m_movieDataFactory;
            static log4cxx::LoggerPtr logger;
    };
}

#endif

