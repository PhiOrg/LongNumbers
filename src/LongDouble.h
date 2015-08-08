#ifndef _LONGDOUBLE_H__
#define _LONGDOUBLE_H__

#include <string.h>
#include <iostream>

class LongDouble;

#ifndef _LONGINTEGER_H__
#include "LongInteger.h"
#endif

class LongDouble
{
    public:
        explicit LongDouble(const long double, unsigned short int = 6);
        explicit LongDouble(const LongInteger&, unsigned short int = 6);

        explicit operator LongInteger() const;

        bool GetSign() const;
        const std::string& GetDigits() const;
        const std::string& GetDecimals() const;
        unsigned short int GetDecimalsNumber() const;

    private:
        unsigned short int decimalsNumber;
        bool sign; //true for positive, false for negative
        std::string digits, decimals;
};

#endif

