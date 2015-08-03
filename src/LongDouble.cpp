#include "LongDouble.h"

using namespace std;

LongDouble::LongDouble(long double number, unsigned short int decimals)
{
    if (number < 0)
    {
        sign = false;
        number *= -1;
    }
    else
        sign = true;

    this->decimals = decimals;
    digits = to_string(number);
}

LongDouble::LongDouble(const LongInteger& number)
{
    digits = number.GetDigits() + ".0";
    sign = number.GetSign();
    decimals = 6;
}

