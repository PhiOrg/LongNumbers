#ifndef _LONGINTEGER_H__
#define _LONGINTEGER_H__

#include <string>
#include <iostream>

#include "Exception.h"

class LongInteger;

#ifndef _LONGDOUBLE_H__
#include "LongDouble.h"
#endif

class LongInteger
{
    public:
        LongInteger();
        LongInteger(const int);
        LongInteger(const long);
        LongInteger(const long long);
        LongInteger(const unsigned);
        LongInteger(const unsigned long);
        LongInteger(const unsigned long long);
        LongInteger(const LongInteger&);
        LongInteger(const std::string&);
        LongInteger(const char*);
        explicit LongInteger(const LongDouble&);

        LongInteger& operator=(const LongDouble&);
        LongInteger& operator=(const LongInteger&);
        LongInteger operator-() const;
        explicit operator bool() const;
        bool operator!() const;
        friend bool operator==(const LongInteger&, const LongInteger&);
        friend bool operator!=(const LongInteger&, const LongInteger&);
        friend bool operator> (const LongInteger&, const LongInteger&);
        friend bool operator< (const LongInteger&, const LongInteger&);
        friend bool operator>=(const LongInteger&, const LongInteger&);
        friend bool operator<=(const LongInteger&, const LongInteger&);

        LongInteger& operator++();
        LongInteger& operator--();
        LongInteger operator++(int);
        LongInteger operator--(int);

        friend LongInteger operator+(const LongInteger&, const LongInteger&);
        friend LongInteger operator-(const LongInteger&, const LongInteger&);
        friend LongInteger operator*(const LongInteger&, const LongInteger&);
        friend LongInteger operator/(const LongInteger&, const LongInteger&);
        friend LongInteger operator%(const LongInteger&, const LongInteger&);
        LongInteger& operator+=(const LongInteger&);
        LongInteger& operator-=(const LongInteger&);
        LongInteger& operator*=(const LongInteger&);
        LongInteger& operator/=(const LongInteger&);
        LongInteger& operator%=(const LongInteger&);

        friend std::ostream& operator<<(std::ostream& os,
                                        const LongInteger& number)
        {
            if (!number.GetSign())
                os << '-';
            os << number.GetDigits();
        }

        friend std::istream& operator>>(std::istream& is, LongInteger& number)
        {
            std::string str;
            is >> str;
            LongInteger a(str);
            number = a;

            return is;
        }

        bool GetSign() const;
        const std::string& GetDigits() const;

    protected:
        void SetSign(bool value);
        void SetDigits(const std::string&);

    friend class LongDouble;
    friend void MultiplyBy10(LongInteger&, size_t);
    friend void DivisionBy10(LongInteger&, size_t);
    friend LongInteger _abs(const LongInteger&);

    private:
        std::string digits;
        bool sign; //true for positive, false for negative
};

#endif

