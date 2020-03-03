

#ifndef COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_SETTABLEMOVIEDATA_HPP
#define COMPUTER_SCIENCE_PLURALSIGHT_MOCKING_SETTABLEMOVIEDATA_HPP

#include <computer/science/pluralsight/mocking/MovieData.hpp>
#include <computer/science/LoggingService.hpp>
namespace computer::science::pluralsight::mocking
{
    class SettableMovieData : public MovieData
    {
        public:

            void setImdbId(std::string id) override;
            void setTitle(std::string title) override;
            void setLengthMin(unsigned length) override;
            void setActors(std::vector<std::string> actors) override;
            void setPlot(std::string plot) override;

        protected:

        private:

            static log4cxx::LoggerPtr logger;
    };
}
#endif

