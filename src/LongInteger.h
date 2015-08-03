#ifndef _LONGINTEGER_H__
#define _LONGINTEGER_H__

#include <string>
#include <iostream>

class LongInteger;

#ifndef _LONGDOUBLE_H__
#include "LongDouble.h"
#endif

class LongInteger
{
    public:
        LongInteger(int);
        LongInteger(long);
        LongInteger(long long);
        LongInteger(unsigned);
        LongInteger(unsigned long);
        LongInteger(unsigned long long);
        LongInteger(const LongInteger&);

#ifdef TEST 
        bool GetSignForTests() const;
        std::string& GetDigitsForTests();
#endif

    protected:
        bool GetSign() const;
        std::string GetDigits() const;
        std::string& GetDigits();

    friend class LongDouble;

    private:
        std::string digits;
        bool sign; //true for positive, false for negative
};

#endif

