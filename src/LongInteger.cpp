#include "LongInteger.h"

using namespace std;

#ifdef TEST 

bool LongInteger::GetSignForTests() const
{
    return sign;
}

string& LongInteger::GetDigitsForTests()
{
    return digits;
}

#endif

LongInteger::LongInteger(int number)
{
    if (number < 0)
    {
        sign = false;
        number *= -1;
    }
    else
        sign = true;

    digits = to_string(number);
}

LongInteger::LongInteger(long number)
{
    if (number < 0)
    {
        sign = false;
        number *= -1;
    }
    else
        sign = true;

    digits = to_string(number);
}

LongInteger::LongInteger(long long number)
{
    if (number < 0)
    {
        sign = false;
        number *= -1;
    }
    else
        sign = true;

    digits = to_string(number);
}

LongInteger::LongInteger(unsigned number)
{
    sign = true;
    digits = to_string(number);
}

LongInteger::LongInteger(unsigned long number)
{
    sign = true;
    digits = to_string(number);
}

LongInteger::LongInteger(unsigned long long number)
{
    sign = true;
    digits = to_string(number);
}

LongInteger::LongInteger(const LongInteger& number)
{
    digits = number.GetDigits();
    sign = number.GetSign();
}

string LongInteger::GetDigits() const
{
    return digits;
}

string& LongInteger::GetDigits()
{
    return digits;
}

bool LongInteger::GetSign() const
{
    return sign;
}

