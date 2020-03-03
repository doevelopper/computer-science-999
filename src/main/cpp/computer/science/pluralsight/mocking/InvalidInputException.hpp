

#ifndef COMPUTER_SCIENCE_INVALIDINPUTEXCEPTION_HPP
#define COMPUTER_SCIENCE_INVALIDINPUTEXCEPTION_HPP

#include <exception>

namespace computer::science::pluralsight::mocking
{
    class InvalidInputException : public std::exception
    {
        public:

            InvalidInputException()
            {
            }

        //virtual char const * what() const
        //{
        //    return m_wronInput.c_str();
        //}

        private:

            std::string m_wronInput;
    };
}

#endif

