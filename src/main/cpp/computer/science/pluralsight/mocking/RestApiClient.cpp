

#include <curl/curl.h>
#include <computer/science/pluralsight/mocking/RestApiClient.hpp>

using namespace computer::science::pluralsight::mocking;

log4cxx::LoggerPtr RestApiClient::logger = log4cxx::Logger::getLogger(std::string(
                                                                          "computer.science.pluralsight.mocking.RestApiClient"));

RestApiClient::RestApiClient()
    : m_buffer()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

RestApiClient::~RestApiClient()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

/*
   std::size_t curl_write(void *ptr, std::size_t size, std::size_t nmemb, void *stream)
   {
    m_buffer.append(static_cast<char*>(ptr), size*nmemb);
    return size*nmemb;
   }
 */
std::string RestApiClient::httpGet(std::string& url)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    /*
        CURL *curl = curl_easy_init();
        if (!curl)
        {
            // TODO: handle error

            return "";
        }

        m_buffer.clear();
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        //string buffer;

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{}");
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK)
        {
            // TODO: handle error

            return "";
        }
     */
    return m_buffer;
}

