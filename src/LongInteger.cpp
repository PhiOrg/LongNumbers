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

LongInteger::LongInteger()
{
    sign = true;
    digits = "0";
}

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

LongInteger::LongInteger(const string&& number)
{
    if (number.size() == 0)
    {
        sign = true;
        digits = "0";
    }
    else
    {
        sign = true;
        digits = number;
        if (number[0] == '+' || number[0] == '-')
        {
            if (number.size() == 1)
            {
                digits = "0";
                return;
            }

            if (number[0] == '-')
                sign = false;

            digits.erase(digits.begin());
        }

        unsigned int size = digits.size();
        for (unsigned int i = 0; i < size; i++)
            if (digits[i] < '0' || digits[i] > '9')
            {
                sign = true;
                digits = "0";
                return;
            }

        unsigned i = 0, zerosNumber = 0;
        while (i < size)
        {
            if (digits[i] != '0')
                break;
            i++;
            zerosNumber++;
        }

        if (zerosNumber != 0)
        {
            if (zerosNumber == size)
            {
                digits.erase(0, zerosNumber - 1);
                sign = true;
            }
            else
                digits.erase(0, zerosNumber);
        }
    }
}

LongInteger::LongInteger(const string& number)
{
    if (number.size() == 0)
    {
        sign = true;
        digits = "0";
    }
    else
    {
        sign = true;
        digits = number;
        if (number[0] == '+' || number[0] == '-')
        {
            if (number.size() == 1)
            {
                digits = "0";
                return;
            }

            if (number[0] == '-')
                sign = false;

            digits.erase(digits.begin());
        }

        unsigned int size = digits.size();
        for (unsigned int i = 0; i < size; i++)
            if (digits[i] < '0' || digits[i] > '9')
            {
                sign = true;
                digits = "0";
                return;
            }

        unsigned i = 0, zerosNumber = 0;
        while (i < size)
        {
            if (digits[i] != '0')
                break;
            i++;
            zerosNumber++;
        }

        if (zerosNumber != 0)
        {
            if (zerosNumber == size)
            {
                digits.erase(0, zerosNumber - 1);
                sign = true;
            }
            else
                digits.erase(0, zerosNumber);
        }
    }
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

void LongInteger::operator=(const LongInteger& number)
{
    this->digits = number.GetDigits();
    this->sign = number.GetSign();
}

bool LongInteger::operator==(const LongInteger& number) const
{
    if (sign != number.GetSign())
        return false;

    if (digits.size() != number.GetDigits().size())
        return false;

    unsigned int size = digits.size();
    string& d = number.GetDigits();
    for (unsigned int i = 0; i < size; i++)
        if (digits[i] != d[i])
            return false;

    return true;
}

