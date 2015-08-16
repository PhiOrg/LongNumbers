#include "LongDouble.h"
#include "Utilities.h"

using namespace std;

#define CreateNumber    if (x < 0) \
                        { \
                            sign = false; \
                            x *= -1; \
                        } \
                        else \
                            sign = true; \
\
                        decimalsNumber = decimals; \
                        SplitNumber(digits, this->decimals, to_string(x)); \
\
                        if (decimalsNumber < this->decimals.size()) \
                        { \
                            this->decimals.erase(decimalsNumber); \
                        } \
                        if (decimalsNumber > this->decimals.size()) \
                        { \
                            for (size_t i = this->decimals.size(); \
                                 i < decimalsNumber; i++) \
                                this->decimals.push_back('0'); \
                        }

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
    CreateNumber
}

LongDouble::LongDouble(const double number, unsigned short int decimals)
{
    double x = number;
    CreateNumber
}

LongDouble::LongDouble(const float number, unsigned short int decimals)
{
    float x = number;
    CreateNumber
}

LongDouble::LongDouble(const int number, unsigned short int decimals)
{
    int x = number;
    CreateNumber
}

LongDouble::LongDouble(const long number, unsigned short int decimals)
{
    long x = number;
    CreateNumber
}

LongDouble::LongDouble(const long long number, unsigned short int decimals)
{
    long long x = number;
    CreateNumber
}

LongDouble::LongDouble(const unsigned number, unsigned short int decimals)
{
    unsigned x = number;
    CreateNumber
}

LongDouble::LongDouble(const unsigned long number, unsigned short int decimals)
{
    unsigned long x = number;
    CreateNumber
}

LongDouble::LongDouble(const unsigned long long number,
                       unsigned short int decimals)
{
    unsigned long long x = number;
    CreateNumber
}

LongDouble::LongDouble()
{
    int x = 0;
    unsigned short int decimals = 6;
    CreateNumber
}

LongDouble::LongDouble(const LongInteger& number, unsigned short int decimals)
{
    digits = number.GetDigits();
    sign = number.GetSign();
    decimalsNumber = decimals;
    for (size_t i = 0; i < decimals; i++)
        this->decimals.push_back('0');
}

LongDouble::LongDouble(const char* x, unsigned short int decimals)
{
    string number = x;
    decimalsNumber = decimals;
    size_t i = 0, size = number.size();
    sign = true;

    if (size == 0)
    {
        digits = "0";
        for (unsigned short int i = 0; i < decimals; i++)
            this->decimals.push_back('0');
        return;
    }

    if (number[0] == '-' || number[0] == '+')
    {
        if (number.size() == 1)
        {
            digits = "0";
            for (unsigned short int i = 0; i < decimals; i++)
                this->decimals.push_back('0');
            return;
        }

        i++;
        if (number[0] == '-')
            sign = false;
    }

    size_t dots = 0;
    bool incorrect = false;
    for (; i < size; i++)
    {
        if (number[i] == '.')
        {
            dots++;
            continue;
        }
        if (number[i] < '0' || number[i] > '9')
        {
            incorrect = true;
            break;
        }
    }

    if (dots > 1)
        incorrect = true;

    if (incorrect)
    {
        digits = "0";
        sign = true;
        for (unsigned short int j = 0; j < decimals; j++)
            this->decimals.push_back('0');
    }
    else
    {
        SplitNumber(digits, this->decimals, number);

        if (digits[0] == '-' || digits[0] == '+')
            digits.erase(digits.begin(), digits.begin() + 1);

        if (decimalsNumber > this->decimals.size())
            for (unsigned short int j = this->decimals.size();
                 j < decimalsNumber; j++)
                this->decimals.push_back('0');

        if (decimalsNumber < this->decimals.size())
            this->decimals.erase(decimalsNumber);
    }
}

LongDouble::LongDouble(const string& number, unsigned short int decimals)
{
    decimalsNumber = decimals;
    size_t i = 0, size = number.size();
    sign = true;

    if (size == 0)
    {
        digits = "0";
        for (unsigned short int i = 0; i < decimals; i++)
            this->decimals.push_back('0');
        return;
    }

    if (number[0] == '-' || number[0] == '+')
    {
        if (number.size() == 1)
        {
            digits = "0";
            for (unsigned short int i = 0; i < decimals; i++)
                this->decimals.push_back('0');
            return;
        }

        i++;
        if (number[0] == '-')
            sign = false;
    }

    size_t dots = 0;
    bool incorrect = false;
    for (; i < size; i++)
    {
        if (number[i] == '.')
        {
            dots++;
            continue;
        }
        if (number[i] < '0' || number[i] > '9')
        {
            incorrect = true;
            break;
        }
    }

    if (dots > 1)
        incorrect = true;

    if (incorrect)
    {
        digits = "0";
        sign = true;
        for (unsigned short int j = 0; j < decimals; j++)
            this->decimals.push_back('0');
    }
    else
    {
        SplitNumber(digits, this->decimals, number);

        if (digits[0] == '-' || digits[0] == '+')
            digits.erase(digits.begin(), digits.begin() + 1);

        if (decimalsNumber > this->decimals.size())
            for (unsigned short int j = this->decimals.size();
                 j < decimalsNumber; j++)
                this->decimals.push_back('0');

        if (decimalsNumber < this->decimals.size())
            this->decimals.erase(decimalsNumber);
    }
}

LongDouble::LongDouble(const LongDouble& number, unsigned short int decimals)
{
    sign = number.GetSign();
    digits = number.GetDigits();
    this->decimals = number.GetDecimals();
    decimalsNumber = decimals;

    if (decimalsNumber > this->decimals.size())
        for (unsigned short int i = this->decimals.size(); i < decimals; i++)
            this->decimals.push_back('0');

    if (decimalsNumber < this->decimals.size())
        this->decimals.erase(decimalsNumber);
}

LongDouble& LongDouble::operator=(const LongDouble& number)
{
    decimalsNumber = number.GetDecimalsNumber();
    sign = number.GetSign();
    digits = number.GetDigits();
    decimals = number.GetDecimals();

    return *this;
}

LongDouble& LongDouble::operator=(const LongInteger& number)
{
    decimalsNumber = 6;
    sign = number.GetSign();
    digits = number.GetDigits();
    decimals = "000000";

    return *this;
}

LongDouble LongDouble::operator-() const
{
    LongDouble result;
    result = *this;
    result.SetSign(!sign);

    return result;
}

void LongDouble::SetSign(bool value)
{
    sign = value;
}

LongDouble::operator bool() const
{
    if (digits != "0")
        return true;

    if (CheckIfStringNotEqualWithZero(decimals.c_str(), decimals.size()))
        return true;

    return false;
}

bool LongDouble::operator!() const
{
    return !((bool) *this);
}

} //end namespace

