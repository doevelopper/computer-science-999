

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_METADATAPROCESSORTESTS_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_METADATAPROCESSORTESTS_HPP

#include <gtest/gtest.h>
#include <vector>
#include <computer/science/LoggingService.hpp>
#include <computer/science/pluralsight/mocking/MetaDataProcessor.hpp>
#include <computer/science/pluralsight/mocking/MovieData.hpp>
#include <computer/science/pluralsight/mocking/TheMovieDbDataFactory.hpp>
#include <computer/science/pluralsight/mocking/TheMovieDbRepository.hpp>

namespace computer::science::pluralsight::mocking::test
{
    class MetaDataProcessorTests : public ::testing::Test
    {
        public:

            MetaDataProcessorTests();
            MetaDataProcessorTests(const MetaDataProcessorTests&) = default;
            MetaDataProcessorTests(MetaDataProcessorTests&&) = default;
            MetaDataProcessorTests& operator=(const MetaDataProcessorTests&) = default;
            MetaDataProcessorTests& operator=(MetaDataProcessorTests&&) = default;
            virtual ~MetaDataProcessorTests();

        protected:

            MetaDataProcessor* processor;

            virtual void SetUp() override;

            virtual void TearDown() override;
            static log4cxx::LoggerPtr logger;

        private:

            TheMovieDbDataFactory dataFactory;
            TheMovieDbRepository* repository;
    };
}

#endif

