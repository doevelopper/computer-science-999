

#include <gtest/gtest.h>

#include <computer/science/pluralsight/mocking/JsonHelper.hpp>
#include <computer/science/pluralsight/mocking/MovieNotFoundException.hpp>
#include <computer/science/pluralsight/mocking/InvalidInputException.hpp>

using namespace computer::science::pluralsight::mocking;


/*!
   @note string sequence of '"\/...' should be escaped as '"\\/...' so as to compile
 */
TEST(JsonHelperTests, GetMatchingTitleIdFromMovieList_PassOnlyOneMovieWithRightName_ReturnThatMovieId)
{
    std::string input =
        "{\"page\":1,\"results\":[{\"poster_path\":\"\\/xfWac8MTYDxujaxgPVcRD9yZaul.jpg\",\"adult\":false,\"overview\":\"After his career is destroyed, a brilliant but arrogant surgeon gets a new lease on life when a sorcerer takes him under his wing and trains him to defend the world against evil.\",\"release_date\":\"2016-10-25\",\"genre_ids\":[28,12,14,878],\"id\":284052,\"original_title\":\"Another Movie\",\"original_language\":\"en\",\"title\":\"Another Movie\",\"backdrop_path\":\"\\/tFI8VLMgSTTU38i8TIsklfqS9Nl.jpg\",\"popularity\":26.528495,\"vote_count\":1967,\"video\":false,\"vote_average\":6.7}],\"total_results\":1,\"total_pages\":1}";

    auto result = JsonHelper::getMatchingTitleIdFromMovieList("Doctor Strange", input);

    ASSERT_EQ(result, "284052");
}

TEST(JsonHelperTests, GetMatchingTitleIdFromMovieList_PassOnlyOneMovieWithWrongName_ReturnThatMovieId)
{
    std::string input =
        "{\"page\":1,\"results\":[{\"poster_path\":\"\\/xfWac8MTYDxujaxgPVcRD9yZaul.jpg\",\"adult\":false,\"overview\":\"After his career is destroyed, a brilliant but arrogant surgeon gets a new lease on life when a sorcerer takes him under his wing and trains him to defend the world against evil.\",\"release_date\":\"2016-10-25\",\"genre_ids\":[28,12,14,878],\"id\":284052,\"original_title\":\"Doctor Strange\",\"original_language\":\"en\",\"title\":\"Doctor Strange\",\"backdrop_path\":\"\\/tFI8VLMgSTTU38i8TIsklfqS9Nl.jpg\",\"popularity\":26.528495,\"vote_count\":1967,\"video\":false,\"vote_average\":6.7}],\"total_results\":1,\"total_pages\":1}";

    auto result = JsonHelper::getMatchingTitleIdFromMovieList("Doctor Strange", input);

    ASSERT_EQ(result, "284052");
}

TEST(JsonHelperTests, GetMatchingTitleIdFromMovieList_PassMovieList_ReturnBestMatchingTitleId)
{
    std::string input =
        "{\"page\":1,\"results\":[{\"poster_path\":\"\\/xfWac8MTYDxujaxgPVcRD9yZaul.jpg\",\"adult\":false,\"overview\":\"After his career is destroyed, a brilliant but arrogant surgeon gets a new lease on life when a sorcerer takes him under his wing and trains him to defend the world against evil.\",\"release_date\":\"2016-10-25\",\"genre_ids\":[28,12,14,878],\"id\":284052,\"original_title\":\"Doctor Strange\",\"original_language\":\"en\",\"title\":\"Doctor Strange\",\"backdrop_path\":\"\\/tFI8VLMgSTTU38i8TIsklfqS9Nl.jpg\",\"popularity\":26.528495,\"vote_count\":1967,\"video\":false,\"vote_average\":6.7},{\"poster_path\":\"\\/3Me8mLOOizc3xElFi8jIoUpw1JM.jpg\",\"adult\":false,\"overview\":\"Dr. Stephen Strange embarks on a wondrous journey to the heights of a Tibetan mountain, where he seeks healing at the feet of the mysterious Ancient One.\",\"release_date\":\"2007-08-14\",\"genre_ids\":[28,16,10751,14,878],\"id\":14830,\"original_title\":\"Doctor Strange\",\"original_language\":\"en\",\"title\":\"Doctor Strange\",\"backdrop_path\":\"\\/xeEVkJ4bKo6JReO26Fc7Rcf7ytj.jpg\",\"popularity\":1.936725,\"vote_count\":45,\"video\":false,\"vote_average\":6.6},{\"poster_path\":\"\\/zRB1HFkStml6NPDdZPi7xQcoQVE.jpg\",\"adult\":false,\"overview\":\"Private eye Jerry Church is hired by a criminal defense lawyer after five mobsters he has gotten acquitted are apparently strangled by a serial killer.\",\"release_date\":\"1942-04-17\",\"genre_ids\":[9648,27],\"id\":84230,\"original_title\":\"The Strange Case of Doctor Rx\",\"original_language\":\"en\",\"title\":\"The Strange Case of Doctor Rx\",\"backdrop_path\":\"\\/iEfbguyj8JRRWDrIiA1Ecc7aDqG.jpg\",\"popularity\":1.000305,\"vote_count\":1,\"video\":false,\"vote_average\":5},{\"poster_path\":null,\"adult\":false,\"overview\":\"Doctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor StrangeDoctor Strange\",\"release_date\":\"\",\"genre_ids\":[],\"id\":426828,\"original_title\":\"Doctor Strangeerwa\",\"original_language\":\"en\",\"title\":\"Doctor Strangeerwa\",\"backdrop_path\":null,\"popularity\":1,\"vote_count\":0,\"video\":false,\"vote_average\":0},{\"poster_path\":\"\\/eAoBpBqW4vT6yOqzk8aZpqDX0Wi.jpg\",\"adult\":false,\"overview\":\"The Crime Doctor gets involved in the case of the poisoning of a wealthy industrialist.\",\"release_date\":\"1943-12-09\",\"genre_ids\":[80,18],\"id\":84650,\"original_title\":\"Crime Doctor’s Strangest Case\",\"original_language\":\"en\",\"title\":\"Crime Doctor’s Strangest Case\",\"backdrop_path\":\"\\/eHuMYoviQxG2YYGUATaRbMSoARq.jpg\",\"popularity\":1.0048,\"vote_count\":1,\"video\":false,\"vote_average\":6},{\"poster_path\":\"\\/oaytb4Z8IbyWoxpwsmvKYAaccn7.jpg\",\"adult\":false,\"overview\":\"A psychiatrist becomes the new Sorcerer Supreme of the Earth in order to battle an evil Sorceress from the past.\",\"release_date\":\"1978-09-06\",\"genre_ids\":[10770,28,12,14,878],\"id\":50468,\"original_title\":\"Dr. Strange\",\"original_language\":\"en\",\"title\":\"Dr. Strange\",\"backdrop_path\":\"\\/qqc17N6y2oGI6jhIERxzIHLMv6z.jpg\",\"popularity\":1.740285,\"vote_count\":5,\"video\":false,\"vote_average\":4},{\"poster_path\":\"\\/nm2e7E8YXbwStcKeT1LG1bOIguU.jpg\",\"adult\":false,\"overview\":\"Doctor Fausto is observed by unknown creatures in outer space. All of a sudden, a strange woman appears in his life. Her strange behavior leads his life down the path to insanity.\",\"release_date\":\"1969-12-27\",\"genre_ids\":[18,14],\"id\":258069,\"original_title\":\"El extraño caso del doctor Fausto\",\"original_language\":\"en\",\"title\":\"El extraño caso del doctor Fausto\",\"backdrop_path\":null,\"popularity\":1.000306,\"vote_count\":0,\"video\":false,\"vote_average\":0},{\"poster_path\":\"\\/cmQqH13qomKapTO5tlXCN1H9JFg.jpg\",\"adult\":false,\"overview\":\"It's the engagement party for brilliant young Dr. Henry Jekyll and his fiancée, the beautiful Fanny Osbourne, attended by various pillars of Victorian society. But when people are found raped and murdered outside and ultimately inside the house, it becomes clear that a madman has broken in to disrupt the festivities - but who is he? And why does Dr. Jekyll keep sneaking off to his laboratory?\",\"release_date\":\"1981-06-17\",\"genre_ids\":[27],\"id\":64534,\"original_title\":\"Docteur Jekyll et les femmes\",\"original_language\":\"fr\",\"title\":\"The Strange Case of Dr. Jekyll and Miss Osbourne\",\"backdrop_path\":null,\"popularity\":1.060633,\"vote_count\":2,\"video\":false,\"vote_average\":6.3}],\"total_results\":8,\"total_pages\":1}";

    auto result = JsonHelper::getMatchingTitleIdFromMovieList("Doctor Strange", input);

    ASSERT_EQ(result, "284052");
}

TEST(JsonHelperTests, GetMatchingTitleIdFromMovieList_PassMovieListSimilarNameNotFirst_ReturnBestMatchingTitleId)
{
    std::string input =
        "{\"page\":1,\"results\":[{\"poster_path\":\"\\/xfWac8MTYDxujaxgPVcRD9yZaul.jpg\",\"adult\":false,\"overview\":\"After his career is destroyed, a brilliant but arrogant surgeon gets a new lease on life when a sorcerer takes him under his wing and trains him to defend the world against evil.\",\"release_date\":\"2016-10-25\",\"genre_ids\":[28,12,14,878],\"id\":284052,\"original_title\":\"Doctor Strange 2\",\"original_language\":\"en\",\"title\":\"Doctor Strange 2\",\"backdrop_path\":\"\\/tFI8VLMgSTTU38i8TIsklfqS9Nl.jpg\",\"popularity\":26.528495,\"vote_count\":1967,\"video\":false,\"vote_average\":6.7},{\"poster_path\":\"\\/3Me8mLOOizc3xElFi8jIoUpw1JM.jpg\",\"adult\":false,\"overview\":\"Dr. Stephen Strange embarks on a wondrous journey to the heights of a Tibetan mountain, where he seeks healing at the feet of the mysterious Ancient One.\",\"release_date\":\"2007-08-14\",\"genre_ids\":[28,16,10751,14,878],\"id\":14830,\"original_title\":\"Doctor Strange\",\"original_language\":\"en\",\"title\":\"Doctor Strange\",\"backdrop_path\":\"\\/xeEVkJ4bKo6JReO26Fc7Rcf7ytj.jpg\",\"popularity\":1.936725,\"vote_count\":45,\"video\":false,\"vote_average\":6.6}],\"total_results\":2,\"total_pages\":1}";

    auto result = JsonHelper::getMatchingTitleIdFromMovieList("Doctor Strange", input);

    ASSERT_EQ(result, "14830");
}

TEST(JsonHelperTests, GetMatchingTitleIdFromMovieList_PassEmptyJsonString_ThrowInvalidInputException)
{
    std::string input = "";

    ASSERT_THROW(JsonHelper::getMatchingTitleIdFromMovieList("Doctor Strange", input), InvalidInputException);
}

TEST(JsonHelperTests, GetMatchingTitleIdFromMovieList_PassEmptyList_ThrowMovieNotFoundException)
{
    std::string input = "{\"page\":1,\"results\":[],\"total_results\":0,\"total_pages\":1}";

    ASSERT_THROW(JsonHelper::getMatchingTitleIdFromMovieList("Doctor Strange", input), MovieNotFoundException);
}

