#ifndef _LongNumber_EXCEPTION_H__
#define _LongNumber_EXCEPTION_H__

#include <exception>

namespace LongNumber
{

class DivisionByZero : public std::exception
{
    const char* what() const throw()
    {
        return "Division by zero!";
    }

};

class ModuloByZero : public std::exception
{
    const char* what() const throw()
    {
        return "Modulo by zero!\n";
    }
};

class LnNegativeNumber : public std::exception
{
    const char* what() const throw()
    {
        return "Cannot take the natural logarithm of a negative number.";
    }
};

class LnZero : public std::exception
{
    const char* what() const throw()
    {
        return "Cannot take the natural logarithm from 0.";
    }
};

} //end namespace

#endif

