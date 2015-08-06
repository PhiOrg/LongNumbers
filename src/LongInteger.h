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
        LongInteger();
        LongInteger(const int);
        LongInteger(const long);
        LongInteger(const long long);
        LongInteger(const unsigned);
        LongInteger(const unsigned long);
        LongInteger(const unsigned long long);
        LongInteger(const LongInteger&);
        LongInteger(const std::string&);
        LongInteger(const std::string&&);

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
        LongInteger& operator+=(const LongInteger&);
        LongInteger& operator-=(const LongInteger&);

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

#ifdef TEST 
        bool GetSignForTests() const;
        std::string& GetDigitsForTests();
#endif

    protected:
        void SetSign(bool value);
        void SetDigits(const std::string&);
        bool GetSign() const;
        const std::string& GetDigits() const;

    friend class LongDouble;

    private:
        std::string digits;
        bool sign; //true for positive, false for negative
};

#endif

