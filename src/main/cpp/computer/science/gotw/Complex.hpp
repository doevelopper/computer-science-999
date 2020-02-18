
#ifndef CPPBDD101_LECTURES_GOTW_COMPLEX_HPP
#define CPPBDD101_LECTURES_GOTW_COMPLEX_HPP

#include <log4cxx/logger.h>

class Complex 
{
public:
    Complex();
    explicit Complex(double real, double imaginary = .0);
    
    const Complex& operator+=(const Complex& other) 
    {
        m_real = m_real + other.m_real;
        m_imaginary = m_imaginary + other.m_imaginary;
        return *this;
    }

    Complex& operator++() 
    {
        ++m_real;
        return *this;
    }

    const Complex operator++( int ) 
    {
        Complex cpl = *this;
        ++m_real;
        return cpl;
    }

    virtual ~Complex();
    double real() const;
    double imaginary() const;
    friend const Complex operator+(const Complex& lhs, const Complex& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Complex&); 
private:
    double m_real;
    double m_imaginary;
    /*!
     * @brief Class logger. 
     */
    static log4cxx::LoggerPtr logger;
};
/*
std::ostream & operator<<(std::ostream & os, const Complex & complex) 
{
	return os << "(" << complex.m_real << "," << complex.m_imaginary << ")";
}

const Complex operator+(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.m_real + rhs.m_real, lhs.m_imaginary + rhs.m_imaginary);
}
*/
#endif
