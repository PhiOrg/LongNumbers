#ifndef _LONGDOUBLE_H__
#define _LONGDOUBLE_H__

#include <string>
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
        LongDouble();
        LongDouble(const long double, unsigned short int = 6);
        LongDouble(const double, unsigned short int = 6);
        LongDouble(const float, unsigned short int = 6);
        LongDouble(const int, unsigned short int = 6);
        LongDouble(const long, unsigned short int = 6);
        LongDouble(const long long, unsigned short int = 6);
        LongDouble(const unsigned, unsigned short int = 6);
        LongDouble(const unsigned long, unsigned short int = 6);
        LongDouble(const unsigned long long, unsigned short int = 6);
        LongDouble(const LongInteger&, unsigned short int = 6);
        LongDouble(const char*, unsigned short int = 6);
        LongDouble(const std::string&, unsigned short int = 6);
        LongDouble(const LongDouble&, unsigned short int = 6);

        LongDouble& operator=(const LongDouble&);
        LongDouble& operator=(const LongInteger&);
        template<typename T>
        LongDouble& operator=(const T& t)
        {
            LongDouble x(t);
            *this = x;

            return *this;
        }

        LongDouble operator-() const;

        explicit operator bool() const;
        bool operator!() const;

        bool GetSign() const;
        const std::string& GetDigits() const;
        const std::string& GetDecimals() const;
        unsigned short int GetDecimalsNumber() const;

    protected:
        void SetSign(bool value);

    private:
        unsigned short int decimalsNumber;
        bool sign; //true for positive, false for negative
        std::string digits, decimals;
};

} // end namespace

#endif

