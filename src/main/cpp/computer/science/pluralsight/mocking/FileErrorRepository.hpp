

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_FILEERRORREPOSITORY_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_FILEERRORREPOSITORY_HPP

#include <string>
#include <computer/science/LoggingService.hpp>
#include <computer/science/pluralsight/mocking/ErrorRepository.hpp>

namespace computer::science::pluralsight::mocking
{
    class FileErrorRepository : public ErrorRepository
    {
        public:

            FileErrorRepository(std::string fileName);


            void logBadMovie(std::string movieName)override;

        protected:

        private:

            std::string               m_fileName;
            static log4cxx::LoggerPtr logger;
    };
}

#endif

