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

LongDouble::LongDouble(const LongInteger& number, unsigned short int decimals)
{
    digits = number.GetDigits() + ".0";
    sign = number.GetSign();
    this->decimals = decimals;
}

LongDouble::operator LongInteger() const
{
    LongInteger number;
    string d = digits;
    size_t size = digits.size(), i;

    for (i = 0; i < size; i++)
        if (d[i] == '.')
            break;
    d.erase(i);

    number.SetSign(sign);
    number.SetDigits(d);

    return number;
}

