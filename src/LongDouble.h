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
        LongDouble(const long double);
        LongDouble(const double);
        LongDouble(const float);
        LongDouble(const int);
        LongDouble(const long);
        LongDouble(const long long);
        LongDouble(const unsigned);
        LongDouble(const unsigned long);
        LongDouble(const unsigned long long);
        LongDouble(const LongInteger&);
        LongDouble(const char*);
        LongDouble(const std::string&);
        LongDouble(const LongDouble&);

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

        friend bool operator==(const LongDouble&, const LongDouble&);
        friend bool operator!=(const LongDouble&, const LongDouble&);
        friend bool operator> (const LongDouble&, const LongDouble&);
        friend bool operator< (const LongDouble&, const LongDouble&);
        friend bool operator>=(const LongDouble&, const LongDouble&);
        friend bool operator<=(const LongDouble&, const LongDouble&);

        friend LongDouble operator+(const LongDouble&, const LongDouble&);
        friend LongDouble operator-(const LongDouble&, const LongDouble&);
        friend LongDouble operator*(const LongDouble&, const LongDouble&);

        LongDouble& operator+=(const LongDouble&);

        friend std::ostream& operator<<(std::ostream& os, const LongDouble& a)
        {
            if (!a.sign)
                os << '-';
            os << a.digits << '.' << a.decimals;

            return os;
        }

        friend std::istream& operator>>(std::istream& is, LongDouble& a)
        {
            std::string str;
            is >> str;
            a = str;

            return is;
        }

        friend void LongDoubleDivisionBy10(LongDouble&, size_t);

        bool GetSign() const;
        const std::string& GetDigits() const;
        const std::string& GetDecimals() const;
        size_t GetPrecision() const;

    protected:
        void SetSign(bool value);
        void SetDigits(const std::string&);
        void SetDecimals(const std::string&);
        void SetDecimalsNumber(size_t);

    private:
        size_t precision;
        bool sign; //true for positive, false for negative
        std::string digits, decimals;
};

} // end namespace

#endif

