

#ifndef CPPBDD101_LECTURES_GGLTEST_SIMPLETEST_HPP
#define CPPBDD101_LECTURES_GGLTEST_SIMPLETEST_HPP

#include <string>
#include <log4cxx/logger.h>

class Simple
{
    public:

        Simple();
        virtual ~Simple();
        /*!
         * @brief Adds value to given value.
         * @param aValue Value to which 10 will be added.
         * @return Return value.
         */
        int add(int aValue);

        /*!
         * @brief Multiplies given value by 12.3.
         * @param aValue Value that will be multiplied by 12.3.
         * @return Result.
         */
        double multiply(double aValue);
        /*!
         * @brief Adds given prefix to given text.
         * @param aPrefix Prefix.
         * @param aTxt Text.
         * @return Result - text with prefix.
         */
        std::string addPrefix(const char* aPrefix, const char* aTxt);
        /*!
         * @brief Returns a C-style string.
         * @return C-style string: abc.
         */
        const char* getCStyleString();

    private:

        /*!
         * @brief Class logger.
         */
        static log4cxx::LoggerPtr logger;
};

#endif

