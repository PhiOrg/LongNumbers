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
        LongInteger(int);
        LongInteger(long);
        LongInteger(long long);
        LongInteger(unsigned);
        LongInteger(unsigned long);
        LongInteger(unsigned long long);
        LongInteger(const LongInteger&);
        LongInteger(const std::string&);
        LongInteger(const std::string&&);

        LongInteger& operator=(const LongInteger&);
        bool operator==(const LongInteger&) const;
        bool operator!=(const LongInteger&) const;
        bool operator>(const LongInteger&) const;
        bool operator<(const LongInteger&) const;
        bool operator>=(const LongInteger&) const;

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
        bool GetSign() const;
        const std::string& GetDigits() const;

    friend class LongDouble;

    private:
        std::string digits;
        bool sign; //true for positive, false for negative
};

#endif

