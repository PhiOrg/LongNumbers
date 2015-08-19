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
                        decimalsNumber = 6; \
                        SplitNumber(digits, decimals, to_string(x)); \
\
                        if (decimalsNumber < decimals.size()) \
                        { \
                            decimals.erase(decimalsNumber); \
                        } \
                        if (decimalsNumber > decimals.size()) \
                        { \
                            for (size_t i = decimals.size(); i < 6; i++) \
                                decimals.push_back('0'); \
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

size_t LongDouble::GetDecimalsNumber() const
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

LongDouble::LongDouble(const long double number)
{
    long double x = number;
    CreateNumber
}

LongDouble::LongDouble(const double number)
{
    double x = number;
    CreateNumber
}

LongDouble::LongDouble(const float number)
{
    float x = number;
    CreateNumber
}

LongDouble::LongDouble(const int number)
{
    int x = number;
    CreateNumber
}

LongDouble::LongDouble(const long number)
{
    long x = number;
    CreateNumber
}

LongDouble::LongDouble(const long long number)
{
    long long x = number;
    CreateNumber
}

LongDouble::LongDouble(const unsigned number)
{
    unsigned x = number;
    CreateNumber
}

LongDouble::LongDouble(const unsigned long number)
{
    unsigned long x = number;
    CreateNumber
}

LongDouble::LongDouble(const unsigned long long number)
{
    unsigned long long x = number;
    CreateNumber
}

LongDouble::LongDouble()
{
    int x = 0;
    CreateNumber
}

LongDouble::LongDouble(const LongInteger& number)
{
    digits = number.GetDigits();
    sign = number.GetSign();
    decimalsNumber = 6;
    for (size_t i = 0; i < 6; i++)
        this->decimals.push_back('0');
}

LongDouble::LongDouble(const char* x)
{
    string number = x;
    decimalsNumber = 6;
    size_t i = 0, size = number.size();
    sign = true;

    if (size == 0)
    {
        digits = "0";
        for (size_t i = 0; i < decimalsNumber; i++)
            decimals.push_back('0');
        return;
    }

    if (number[0] == '-' || number[0] == '+')
    {
        if (number.size() == 1)
        {
            digits = "0";
            for (size_t i = 0; i < decimalsNumber; i++)
                decimals.push_back('0');
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
        for (size_t j = 0; j < decimalsNumber; j++)
            decimals.push_back('0');
    }
    else
    {
        SplitNumber(digits, decimals, number);

        if (digits[0] == '-' || digits[0] == '+')
            digits.erase(digits.begin(), digits.begin() + 1);

        decimalsNumber = decimals.size();
        if (decimalsNumber < 6)
        {
            for (size_t j = decimalsNumber; j < 6; j++)
                decimals.push_back('0');
            decimalsNumber = 6;
        }
    }
}

LongDouble::LongDouble(const string& number)
{
    decimalsNumber = 6;
    size_t i = 0, size = number.size();
    sign = true;

    if (size == 0)
    {
        digits = "0";
        for (size_t i = 0; i < decimalsNumber; i++)
            decimals.push_back('0');
        return;
    }

    if (number[0] == '-' || number[0] == '+')
    {
        if (number.size() == 1)
        {
            digits = "0";
            for (size_t i = 0; i < decimalsNumber; i++)
                decimals.push_back('0');
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
        for (size_t j = 0; j < decimalsNumber; j++)
            decimals.push_back('0');
    }
    else
    {
        SplitNumber(digits, decimals, number);

        if (digits[0] == '-' || digits[0] == '+')
            digits.erase(digits.begin(), digits.begin() + 1);

        decimalsNumber = decimals.size();
        if (decimalsNumber < 6)
        {
            for (size_t j = decimalsNumber; j < 6; j++)
                decimals.push_back('0');
            decimalsNumber = 6;
        }
    }
}

LongDouble::LongDouble(const LongDouble& number)
{
    sign = number.GetSign();
    digits = number.GetDigits();
    decimals = number.GetDecimals();
    decimalsNumber = number.GetDecimalsNumber();
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

bool operator==(const LongDouble& a, const LongDouble& b)
{
    if (a.sign != b.sign)
        return false;

    if (a.digits.size() != b.digits.size())
        return false;

    size_t size = a.digits.size();
    for (size_t i = 0; i < size; i++)
        if (a.digits[i] != b.digits[i])
            return false;

    size_t min, max;
    if (a.decimals.size() < b.decimals.size())
    {
        min = a.decimals.size();
        max = b.decimals.size();
    }
    else
    {
        min = b.decimals.size();
        max = a.decimals.size();
    }

    for (size_t i = 0; i < min; i++)
        if (a.decimals[i] != b.decimals[i])
            return false;

    if (min != max)
    {
        if (max == a.decimals.size())
            return !CheckIfStringNotEqualWithZero(a.decimals.c_str() + min,
                                                  max - min);
        else
            return !CheckIfStringNotEqualWithZero(b.decimals.c_str() + min,
                                                  max - min);
    }

    return true;
}

bool operator!=(const LongDouble& a, const LongDouble& b)
{
    return !(a == b);
}

bool operator>(const LongDouble& a, const LongDouble& b)
{
    if (a.sign && !b.sign)
        return true;
    if (!a.sign && b.sign)
        return false;

    if (a.digits.size() > b.digits.size())
    {
        if (a.sign)
            return true;
        else
            return false;
    }

    if (a.digits.size() < b.digits.size())
    {
        if (a.sign)
            return false;
        else
            return true;
    }

    size_t size = a.digits.size();
    for (size_t i = 0; i < size; ++i)
        if (a.digits[i] != b.digits[i])
        {
            if (a.digits[i] > b.digits[i])
                if (a.sign)
                    return true;
                else
                    return false;
            else
                if (a.sign)
                    return false;
                else
                    return true;
        }

    size_t min, max;
    if (a.decimals.size() < b.decimals.size())
    {
        min = a.decimals.size();
        max = b.decimals.size();
    }
    else
    {
        min = b.decimals.size();
        max = a.decimals.size();
    }

    for (size_t i = 0; i < min; i++)
        if (a.decimals[i] != b.decimals[i])
        {
            if (a.decimals[i] > b.decimals[i])
                if (a.sign)
                    return true;
                else
                    return false;
            else
                if (a.sign)
                    return false;
                else
                    return true;
        }

    if (min != max)
    {
        if (max == a.decimals.size())
            return CheckIfStringNotEqualWithZero(a.decimals.c_str() + min,
                                                 max - min);
    }

    return false;
}

bool operator<(const LongDouble& a, const LongDouble& b)
{
    if (a.sign && !b.sign)
        return false;
    if (!a.sign && b.sign)
        return true;

    if (a.digits.size() > b.digits.size())
    {
        if (a.sign)
            return false;
        else
            return true;
    }

    if (a.digits.size() < b.digits.size())
    {
        if (a.sign)
            return true;
        else
            return false;
    }

    size_t size = a.digits.size();
    for (size_t i = 0; i < size; ++i)
        if (a.digits[i] != b.digits[i])
        {
            if (a.digits[i] < b.digits[i])
                if (a.sign)
                    return true;
                else
                    return false;
            else
                if (a.sign)
                    return false;
                else
                    return true;
        }

    size_t min, max;
    if (a.decimals.size() < b.decimals.size())
    {
        min = a.decimals.size();
        max = b.decimals.size();
    }
    else
    {
        min = b.decimals.size();
        max = a.decimals.size();
    }

    for (size_t i = 0; i < min; i++)
        if (a.decimals[i] != b.decimals[i])
        {
            if (a.decimals[i] < b.decimals[i])
                if (a.sign)
                    return true;
                else
                    return false;
            else
                if (a.sign)
                    return false;
                else
                    return true;
        }

    if (min != max)
    {
        if (max == b.decimals.size())
            return CheckIfStringNotEqualWithZero(b.decimals.c_str() + min,
                                                 max - min);
    }

    return false;
}

bool operator>=(const LongDouble& a, const LongDouble& b)
{
    if (a.sign && !b.sign)
        return true;
    if (!a.sign && b.sign)
        return false;

    if (a.digits.size() > b.digits.size())
    {
        if (a.sign)
            return true;
        else
            return false;
    }

    if (a.digits.size() < b.digits.size())
    {
        if (a.sign)
            return false;
        else
            return true;
    }

    size_t size = a.digits.size();
    for (size_t i = 0; i < size; ++i)
        if (a.digits[i] != b.digits[i])
        {
            if (a.digits[i] > b.digits[i])
                if (a.sign)
                    return true;
                else
                    return false;
            else
                if (a.sign)
                    return false;
                else
                    return true;
        }

    size_t min, max;
    if (a.decimals.size() < b.decimals.size())
    {
        min = a.decimals.size();
        max = b.decimals.size();
    }
    else
    {
        min = b.decimals.size();
        max = a.decimals.size();
    }

    for (size_t i = 0; i < min; i++)
        if (a.decimals[i] != b.decimals[i])
        {
            if (a.decimals[i] > b.decimals[i])
                if (a.sign)
                    return true;
                else
                    return false;
            else
                if (a.sign)
                    return false;
                else
                    return true;
        }

    if (min != max)
    {
        if (max == b.decimals.size())
            return !CheckIfStringNotEqualWithZero(b.decimals.c_str() + min,
                                                  max - min);
    }

    return true;
}

bool operator<=(const LongDouble& a, const LongDouble& b)
{
    if (a.sign && !b.sign)
        return false;
    if (!a.sign && b.sign)
        return true;

    if (a.digits.size() < b.digits.size())
    {
        if (a.sign)
            return true;
        else
            return false;
    }

    if (a.digits.size() > b.digits.size())
    {
        if (a.sign)
            return false;
        else
            return true;
    }

    size_t size = a.digits.size();
    for (size_t i = 0; i < size; ++i)
        if (a.digits[i] != b.digits[i])
        {
            if (a.digits[i] < b.digits[i])
                if (a.sign)
                    return true;
                else
                    return false;
            else
                if (a.sign)
                    return false;
                else
                    return true;
        }

    size_t min, max;
    if (a.decimals.size() < b.decimals.size())
    {
        min = a.decimals.size();
        max = b.decimals.size();
    }
    else
    {
        min = b.decimals.size();
        max = a.decimals.size();
    }

    for (size_t i = 0; i < min; i++)
        if (a.decimals[i] != b.decimals[i])
        {
            if (a.decimals[i] < b.decimals[i])
                if (a.sign)
                    return true;
                else
                    return false;
            else
                if (a.sign)
                    return false;
                else
                    return true;
        }

    if (min != max)
    {
        if (max == a.decimals.size())
            return !CheckIfStringNotEqualWithZero(a.decimals.c_str() + min,
                                                  max - min);
    }

    return true;
}

} //end namespace

