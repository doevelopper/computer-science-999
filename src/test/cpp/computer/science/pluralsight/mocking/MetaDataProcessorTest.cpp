

#include <computer/science/pluralsight/mocking/APIKEy.hpp>
#include <computer/science/pluralsight/mocking/MetaDataProcessorTest.hpp>

using namespace computer::science::pluralsight::mocking;
using namespace computer::science::pluralsight::mocking::test;

log4cxx::LoggerPtr MetaDataProcessorTests::logger = log4cxx::Logger::getLogger(std::string(
                                                                                   "computer.science.pluralsight.mocking.MetaDataProcessorTests"));

/*
 *
   R elevent for tes 1 only

   TEST(MetaDataProcessorTes,ProcessMovies_PassEmptyMovieList_ReturnEmptyResult)
   {
    MetaDataProcessor processor;
    Movies result;

    processor.processMovies({}, result);

    ASSERT_EQ(0, result.size());
   }
 */

MetaDataProcessorTests::MetaDataProcessorTests()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    repository = new TheMovieDbRepository(MY_API_KEY, dataFactory);
}

MetaDataProcessorTests::~MetaDataProcessorTests()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    delete repository;
}

void MetaDataProcessorTests::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    processor = new MetaDataProcessor(*repository);
}

void MetaDataProcessorTests::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    delete processor;
}

TEST_F(MetaDataProcessorTests, ProcessMovies_PassEmptyMovieList_ReturnEmptyResult)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Movies result;
    processor->processMovies({}, result);

    ASSERT_EQ(0, result.size());
}

TEST_F(MetaDataProcessorTests, DISABLED_ProcessMovies_PassValidMovie_ReturnMovieData)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Movies result;
    processor->processMovies({ "Batman Begins" }, result);

    EXPECT_EQ(1, result.size());
    EXPECT_EQ(result[0]->getTitle(), "Batman Begins");
}

TEST_F(MetaDataProcessorTests, DISABLED_ProcessMovies_PassValidMovies_ReturnAllMoviesData)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Movies result;
    processor->processMovies({ "Batman Begins", "Apocalypse Now", "Dumb and Dumber" }, result);

    EXPECT_EQ(3, result.size());
    EXPECT_EQ(result[0]->getTitle(), "Batman Begins");
    EXPECT_EQ(result[1]->getTitle(), "Apocalypse Now");
    EXPECT_EQ(result[2]->getTitle(), "Dumb and Dumber");
}

