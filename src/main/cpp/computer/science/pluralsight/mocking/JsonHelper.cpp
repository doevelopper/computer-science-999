

#include <computer/science/pluralsight/mocking//JsonHelper.hpp>
#include <computer/science/pluralsight/mocking/MovieNotFoundException.hpp>
#include <computer/science/pluralsight/mocking/InvalidInputException.hpp>

using namespace computer::science::pluralsight::mocking;

log4cxx::LoggerPtr JsonHelper::logger = log4cxx::Logger::getLogger(std::string(
                                                                       "computer.science.pluralsight.mocking.JsonHelper"));


const rapidjson::Value&
JsonHelper::findMovieByTitle(const std::string& title, rapidjson::GenericValue<rapidjson::UTF8<> >::Array results)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    size_t selectedIndex = 0;
    if(results.Size() > 1)
    {
        for (size_t i = 0; i < results.Size(); ++i)
        {
            auto movieTitle = results[i]["title"].GetString();
            if(std::strcmp(movieTitle, title.c_str()) == 0)
            {
                selectedIndex = i;
                break;
            }
        }
    }

    return results[selectedIndex];
}

std::string
JsonHelper::getMatchingTitleIdFromMovieList(const std::string& title, const std::string& jsonString)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    rapidjson::Document jsonDocument;
    jsonDocument.Parse(jsonString.c_str());

    if (!jsonDocument.IsObject())
    {
        throw InvalidInputException();
    }

    auto results = jsonDocument["results"].GetArray();
    if(results.Size() == 0)
    {
        throw MovieNotFoundException(title);
    }
    const rapidjson::Value& result = findMovieByTitle(title, results);
    auto id = result["id"].GetInt();

    return (std::to_string(id));
}

