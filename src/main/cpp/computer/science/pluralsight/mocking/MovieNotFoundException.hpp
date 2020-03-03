

#ifndef COMPUTER_SCIENCE_MOVIENOTFOUNDEXCEPTION_HPP
#define COMPUTER_SCIENCE_MOVIENOTFOUNDEXCEPTION_HPP

#include <exception>

namespace computer::science::pluralsight::mocking
{
    class MovieNotFoundException : public std::exception
    {
        public:

            MovieNotFoundException(const std::string& movieName)
                : m_movieName(movieName)
            {
            }

            std::string getMovieName() const
            {
                return m_movieName;
            }

        protected:

        private:

            const std::string m_movieName;
    };
}

#endif

