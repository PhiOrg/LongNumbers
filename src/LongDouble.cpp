#include "LongDouble.h"

using namespace std;

namespace LongNumber
{

bool LongDouble::GetSign() const
{
    return sign;
}

const string& LongDouble::GetDigits() const
{
    return digits;
}

const string& LongDouble::GetDecimals() const
{
    return decimals;
}

unsigned short int LongDouble::GetDecimalsNumber() const
{
    return decimalsNumber;
}

void SplitNumber(string& digits, string& decimals, string number)
{
    bool ok = false;
    size_t size = number.size(), i;
    for (i = 0; i < size && number[i] != '.'; i++)
        digits.push_back(number[i]);
    i++;
    for (; i < size; i++)
        decimals.push_back(number[i]);
}

LongDouble::LongDouble(const long double number, unsigned short int decimals)
{
    long double x = number;
    if (number < 0)
    {
        sign = false;
        x *= -1;
    }
    else
        sign = true;

    decimalsNumber = decimals;
    SplitNumber(digits, this->decimals, to_string(x));

    if (decimalsNumber < this->decimals.size())
    {
        decimalsNumber = this->decimals.size();
    }
    else
    {
        for (size_t i = this->decimals.size(); i < decimalsNumber; i++)
            this->decimals.push_back('0');
    }
}

LongDouble::LongDouble(const LongInteger& number, unsigned short int decimals)
{
    digits = number.GetDigits();
    sign = number.GetSign();
    decimalsNumber = decimals;
    for (size_t i = 0; i < decimals; i++)
        this->decimals.push_back('0');
}

LongDouble::operator LongInteger() const
{
    LongInteger number(digits);
    number.SetSign(sign);

    return number;
}

} //end namespace

