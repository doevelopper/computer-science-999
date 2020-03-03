

#include <gtest/gtest.h>
#include <computer/science/pluralsight/mocking/TheMovieDbDataFactory.hpp>

using namespace computer::science::pluralsight::mocking;

TEST(TheMovieDbDataFactoryTests, CreateFromJson_PassEmptyString_ReturnEmptyClass)
{
    TheMovieDbDataFactory factory;

    auto result = factory.createFromJson("");

    EXPECT_EQ(result->getTitle(), "");
    EXPECT_EQ(result->getActors().size(), 0);
    EXPECT_EQ(result->getImdbId(), "");
    EXPECT_EQ(result->getLengthMin(), 0);
    EXPECT_EQ(result->getPlot(), "");
}

TEST(TheMovieDbDataFactoryTests, CreateFromJson_PassValidString_ReturnMovieDetails)
{
    std::string input =
        "{\"id\":284052,\"imdb_id\":\"tt1211837\",\"overview\":\"The movie's plot\",\"title\":\"a movie\",\"runtime\":115}";

    TheMovieDbDataFactory factory;

    auto result = factory.createFromJson(input);

    EXPECT_EQ(result->getImdbId(), "tt1211837");
    EXPECT_EQ(result->getTitle(), "a movie123");
    EXPECT_EQ(result->getPlot(), "The movie's plot is wrong");
    EXPECT_EQ(result->getLengthMin(), 115);
}

