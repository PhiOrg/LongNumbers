#ifndef _LongNumber_EXCEPTION_H__
#define _LongNumber_EXCEPTION_H__

#include <exception>

class DivisionByZero : public std::exception
{
    const char* what() const throw()
    {
        return "Division by zero!";
    }

};

#endif

