

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_MOVIEDATA_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_MOVIEDATA_HPP

#include <string>
#include <vector>
#include <computer/science/LoggingService.hpp>
namespace computer::science::pluralsight::mocking
{
    class MovieData
    {
        public:

            MovieData();
            MovieData(const MovieData&) = default;
            MovieData(MovieData&&) = default;
            MovieData& operator=(const MovieData&) = default;
            MovieData& operator=(MovieData&&) = default;
            virtual ~MovieData();

            std::string getImdbId()const;
            std::string getTitle()const;
            unsigned getLengthMin()const;
            std::vector<std::string> getActors()const;
            std::string getPlot()const;

        protected:

            virtual void setImdbId(std::string id);
            virtual void setTitle(std::string title);
            virtual void setLengthMin(unsigned length);
            virtual void setActors(std::vector<std::string> actors);
            virtual void setPlot(std::string plot);

        private:

            std::string               m_id;
            std::string               m_title;
            std::string               m_posterUrl;
            unsigned                  m_length;
            std::vector<std::string>  m_actors;
            std::string               m_plot;
            static log4cxx::LoggerPtr logger;
    };
}

#endif

