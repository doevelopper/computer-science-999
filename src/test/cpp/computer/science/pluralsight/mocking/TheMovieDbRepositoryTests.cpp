

#include <gtest/gtest.h>

#include <computer/science/pluralsight/mocking/FakeRestApiClient.hpp>
#include <computer/science/pluralsight/mocking/TheMovieDbRepository.hpp>
#include <computer/science/pluralsight/mocking/TheMovieDbDataFactory.hpp>
#include <computer/science/pluralsight/mocking/MovieNotFoundException.hpp>

using namespace computer::science::pluralsight::mocking;

TEST(TheMovieDbRepositoryTests, FindMovieData_ApiReturnsEmptyString_ThrowException)
{
    TheMovieDbDataFactory factory;
    FakeRestApiClient fakeClient;

    TheMovieDbRepository repository("api-key", factory, fakeClient);

    ASSERT_THROW(
        repository.findMovieData("movie name"), MovieNotFoundException);
}

TEST(TheMovieDbRepositoryTests, FindMovieData_ApiReturnsStringWithoutMovie_ThrowException)
{
    TheMovieDbDataFactory factory;
    FakeRestApiClient fakeClient;

    TheMovieDbRepository repository("api-key", factory, fakeClient);

    ASSERT_THROW(
        repository.findMovieData("movie name"), MovieNotFoundException);
}

