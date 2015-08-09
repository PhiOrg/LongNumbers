#ifndef _LONGDOUBLE_H__
#define _LONGDOUBLE_H__

#include <string.h>
#include <iostream>

namespace LongNumber
{

class LongDouble;

}

#ifndef _LONGINTEGER_H__
#include "LongInteger.h"
#endif

namespace LongNumber
{

class LongDouble
{
    public:
        explicit LongDouble(const long double, unsigned short int = 6);
        explicit LongDouble(const double, unsigned short int = 6);
        explicit LongDouble(const float, unsigned short int = 6);
        explicit LongDouble(const int, unsigned short int = 6);
        explicit LongDouble(const long, unsigned short int = 6);
        explicit LongDouble(const long long, unsigned short int = 6);
        explicit LongDouble(const unsigned, unsigned short int = 6);
        explicit LongDouble(const unsigned long, unsigned short int = 6);
        explicit LongDouble(const unsigned long long, unsigned short int = 6);
        explicit LongDouble(const LongInteger&, unsigned short int = 6);

        bool GetSign() const;
        const std::string& GetDigits() const;
        const std::string& GetDecimals() const;
        unsigned short int GetDecimalsNumber() const;

    private:
        unsigned short int decimalsNumber;
        bool sign; //true for positive, false for negative
        std::string digits, decimals;
};

} // end namespace

#endif

