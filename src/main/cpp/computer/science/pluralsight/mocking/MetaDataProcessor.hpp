

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_METADATAPROCESSOR_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_METADATAPROCESSOR_HPP

#include <vector>
#include <string>
#include <memory>
#include <computer/science/LoggingService.hpp>
#include <computer/science/pluralsight/mocking/MovieMetaDataRepository.hpp>

namespace computer::science::pluralsight::mocking
{
    class MovieData;
    using Movies = std::vector<std::shared_ptr<MovieData> >;
    class MetaDataProcessor
    {
        public:

            MetaDataProcessor() = default;
            MetaDataProcessor(const MetaDataProcessor&) = default;
            MetaDataProcessor(MetaDataProcessor&&) = default;
            MetaDataProcessor& operator=(const MetaDataProcessor&) = default;
            MetaDataProcessor& operator=(MetaDataProcessor&&) = default;
            virtual ~MetaDataProcessor() = default;
            MetaDataProcessor(computer::science::pluralsight::mocking::MovieMetaDataRepository & respository);

            void processMovies(const std::vector<std::string>& fileNames, Movies& result);

        protected:

        private:

            computer::science::pluralsight::mocking::MovieMetaDataRepository& m_repository;
            static log4cxx::LoggerPtr                                         logger;
    };
}

#endif

