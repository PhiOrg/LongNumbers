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
                        precision = 6; \
                        SplitNumber(digits, decimals, to_string(x)); \
\
                        if (precision < decimals.size()) \
                        { \
                            decimals.erase(precision); \
                        } \
                        if (precision > decimals.size()) \
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

size_t LongDouble::GetPrecision() const
{
    return precision;
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
    precision = 6;
    for (size_t i = 0; i < 6; i++)
        this->decimals.push_back('0');
}

LongDouble::LongDouble(const char* x)
{
    string number = x;
    precision = 6;
    size_t i = 0, size = number.size();
    sign = true;

    if (size == 0)
    {
        digits = "0";
        for (size_t i = 0; i < precision; i++)
            decimals.push_back('0');
        return;
    }

    if (number[0] == '-' || number[0] == '+')
    {
        if (number.size() == 1)
        {
            digits = "0";
            for (size_t i = 0; i < precision; i++)
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
        for (size_t j = 0; j < precision; j++)
            decimals.push_back('0');
    }
    else
    {
        SplitNumber(digits, decimals, number);

        if (digits[0] == '-' || digits[0] == '+')
            digits.erase(digits.begin(), digits.begin() + 1);

        precision = decimals.size();
        if (precision < 6)
        {
            for (size_t j = precision; j < 6; j++)
                decimals.push_back('0');
            precision = 6;
        }
    }
}

LongDouble::LongDouble(const string& number)
{
    precision = 6;
    size_t i = 0, size = number.size();
    sign = true;

    if (size == 0)
    {
        digits = "0";
        for (size_t i = 0; i < precision; i++)
            decimals.push_back('0');
        return;
    }

    if (number[0] == '-' || number[0] == '+')
    {
        if (number.size() == 1)
        {
            digits = "0";
            for (size_t i = 0; i < precision; i++)
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
        for (size_t j = 0; j < precision; j++)
            decimals.push_back('0');
    }
    else
    {
        SplitNumber(digits, decimals, number);

        if (digits[0] == '-' || digits[0] == '+')
            digits.erase(digits.begin(), digits.begin() + 1);

        precision = decimals.size();
        if (precision < 6)
        {
            for (size_t j = precision; j < 6; j++)
                decimals.push_back('0');
            precision = 6;
        }
    }
}

LongDouble::LongDouble(const LongDouble& number)
{
    sign = number.GetSign();
    digits = number.GetDigits();
    decimals = number.GetDecimals();
    precision = number.GetPrecision();
}

LongDouble& LongDouble::operator=(const LongDouble& number)
{
    precision = number.GetPrecision();
    sign = number.GetSign();
    digits = number.GetDigits();
    decimals = number.GetDecimals();

    return *this;
}

LongDouble& LongDouble::operator=(const LongInteger& number)
{
    precision = 6;
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

void LongDouble::SetDigits(const string& d)
{
    digits = d;
}

void LongDouble::SetDecimals(const string& d)
{
    decimals = d;
}

LongDouble operator+(const LongDouble& a, const LongDouble& b)
{
    LongDouble result;

    if (a.sign == b.sign)
    {
        bool add;
        result.sign = a.sign;
        if (a.decimals.size() > b.decimals.size())
            result.decimals = GathersDecimals(a.decimals, b.decimals, add);
        else
            result.decimals = GathersDecimals(b.decimals, a.decimals, add);

        if (a.digits.size() > b.digits.size())
            result.digits = GathersNumbers(a.digits, b.digits);
        else
            result.digits = GathersNumbers(b.digits, a.digits);

        if (add)
            Increment(result.digits);
    }
    else
    {
        if (a == -b)
            return 0;

        bool decreases = false;
        if (a.sign)
        {
            if (a > -b)
            {
                result.sign = true;
                result.decimals = DecreasesDecimals(a.decimals, b.decimals,
                                                    decreases);
                result.digits = DecreasesNumbers(a.digits, b.digits);
                if (decreases)
                    Decrement(result.digits);
            }
            else
            {
                result.sign = false;
                result.decimals = DecreasesDecimals(b.decimals, a.decimals,
                                                    decreases);
                result.digits = DecreasesNumbers(b.digits, a.digits);
                if (decreases)
                    Decrement(result.digits);
            }
        }
        else
        {
            if (a < -b)
            {
                result.sign = false;
                result.decimals = DecreasesDecimals(a.decimals, b.decimals,
                                                    decreases);
                result.digits = DecreasesNumbers(a.digits, b.digits);
                if (decreases)
                    Decrement(result.digits);
            }
            else
            {
                result.sign = true;
                result.decimals = DecreasesDecimals(b.decimals, a.decimals,
                                                    decreases);
                result.digits = DecreasesNumbers(b.digits, a.digits);
                if (decreases)
                    Decrement(result.digits);
            }
        }
    }

    result.precision = result.decimals.size();

    return result;
}

LongDouble operator-(const LongDouble& a, const LongDouble& b)
{
    return a + -b;
}

void LongDouble::DivisionBy10(size_t power)
{
    if (power == 0)
        return;

    size_t size = digits.size();

    if (size < power)
    {
        decimals.insert(0, digits);
        decimals.insert(0, power - size, '0');
        digits = "0";
    }
    else
    {
        if (size == power)
        {
            decimals.insert(0, digits);
            digits = "0";
        }
        else
        {
            decimals.insert(0, digits, size - power, power);
            digits.erase(size - power);
        }
    }

    precision += power;
}

void LongDouble::MultiplyBy10(size_t power)
{
    if (power == 0)
        return;

    if (precision < power)
    {
        digits.append(decimals);
        digits.append(power - precision, '0');
        for (size_t i = 0; i < precision; i++)
            decimals[i] = '0';
    }
    else
    {
        if (precision == power)
        {
            digits.append(decimals);
            for (size_t i = 0; i < precision; i++)
                decimals[i] = '0';
        }
        else
        {
            digits.append(decimals, 0, power);

            size_t j = 0;
            for (size_t i = power; i < precision; i++, j++)
                decimals[j] = decimals[i];
            for (; j < precision; j++)
                decimals[j] = '0';
        }
    }
}

LongDouble operator*(const LongDouble& a, const LongDouble& b)
{
    LongInteger x(a.digits + a.decimals), y(b.digits + b.decimals);
    LongDouble result = x * y;
    result.sign = a.sign && b.sign;

    size_t position = a.precision > b.precision ? a.precision : b.precision;
    size_t power = a.precision + b.precision;
    result.DivisionBy10(power);

    result.precision = position;
    result.decimals.erase(position);

    return result;
}

LongDouble& LongDouble::operator+=(const LongDouble& a)
{
    *this = *this + a;

    return *this;
}

LongDouble& LongDouble::operator-=(const LongDouble& a)
{
    *this = *this - a;

    return *this;
}

LongDouble& LongDouble::operator*=(const LongDouble& a)
{
    *this = *this * a;

    return *this;
}

LongDouble& LongDouble::operator++()
{
    if (*this == -1)
    {
        digits[0] = '0';
        sign = true;

        return *this;
    }

    if (sign)
        Increment(digits);
    else
    {
        if (digits[0] == '0')
            *this = *this + 1;
        else
            Decrement(digits);
    }

    return *this;
}

LongDouble& LongDouble::operator--()
{
    if (sign)
    {
        if (digits[0] == '0')
            *this = *this - 1;
        else
            Decrement(digits);
    }
    else
        Increment(digits);

    return *this;
}

LongDouble LongDouble::operator++(int)
{
    LongDouble a(*this);
    if (*this == -1)
    {
        digits[0] = '0';
        sign = true;

        return a;
    }

    if (sign)
        Increment(digits);
    else
    {
        if (digits[0] == '0')
            *this = *this + 1;
        else
            Decrement(digits);
    }

    return a;
}

LongDouble LongDouble::operator--(int)
{
    LongDouble a(*this);
    if (sign)
    {
        if (digits[0] == '0')
            *this = *this - 1;
        else
            Decrement(digits);
    }
    else
        Increment(digits);

    return a;
}

void LongDouble::SetPrecision(size_t value)
{
    if (value < 6 || precision == value)
        return;

    if (value > precision)
    {
        for (size_t i = precision; i < value; i++)
            decimals.push_back('0');
    }
    else
    {
        bool add = decimals[value] >= '5' ? true : false;
        decimals.erase(value);

        if (add)
            Increment(decimals);

        if (decimals.size() != value)
        {
            Increment(digits);
            decimals.erase(decimals.begin(), decimals.begin() + 1);
        }
    }

    precision = value;
}

void LongDouble::SetPrecisionWithoutRounding(size_t value)
{
    if (value < 6 || precision == value)
        return;

    if (value > precision)
    {
        for (size_t i = precision; i < value; i++)
            decimals.push_back('0');
    }
    else
    {
        decimals.erase(value);
    }

    precision = value;
}

LongDouble operator/(const LongDouble& a, const LongDouble& b)
{
    if (b == 0)
        throw DivisionByZero();
    if (a == b)
        return 1;
    if (a == -b)
        return -1;
    if (b == 1)
        return a;
    if (b == -1)
        return -a;
    if (a == 0)
        return 0;

    LongInteger c(a.digits + a.decimals), d(b.digits + b.decimals);
    LongDouble result;
    bool sign = a.sign ^ b.sign;
    size_t value, precision = a.precision;
    string digitsResult, decimalsResult;

    //Establishes the precision with which the division must be made
    if (a.precision > b.precision)
    {
        precision = a.precision;
        d.MultiplyBy10(a.precision - b.precision);
    }
    else
    {
        if (a.precision < b.precision)
        {
            precision = b.precision;
            c.MultiplyBy10(b.precision - a.precision);
        }
    }

    if (d > c)
    {
        digitsResult = "0";
        goto label;
    }

    //Multiply the numbers
    if (c.digits[0] > d.digits[0])
    {
        value = c.digits.size() - d.digits.size();
        d.MultiplyBy10(value);
    }
    else
    {
        if (c.digits[0] == d.digits[0])
        {
            value = c.digits.size() - d.digits.size();
            d.MultiplyBy10(value);

            if (c < d)
            {
                d.DivisionBy10(1);
                value--;
            }
        }
        else
        {
            if (c.digits[0] < d.digits[0])
            {
                value = c.digits.size() - d.digits.size();
                if (value > 0)
                    value--;
                d.MultiplyBy10(value);
            }
        }
    }

    value++;
    d.MultiplyBy10(1);
    //Computes the integer part
    while (c > 0 && value > 0)
    {
        d.DivisionBy10(1);
        short int x = 0;
        while (c >= d)
        {
            c -= d;
            x++;
        }

        digitsResult.push_back(x + 48);
        value--;
    }

    //Checks if the numbers were divided exactly
    if (c == 0)
    {
        for (int i = 0; i < value; i++)
            digitsResult.push_back('0');
        for (int i = 0; i < precision; i++)
            decimalsResult.push_back('0');

        result.digits = digitsResult;
        result.decimals = decimalsResult;
        result.sign = !sign;
        result.precision = precision;

        return result;
    }

label:
    //Computes the real part
    size_t i = 0;
    for (; i < precision + 1; i++)
    {
        c.MultiplyBy10(1);
        short int x = 0;

        while (c >= d)
        {
            c -= d;
            x++;
        }

        decimalsResult.push_back(x + 48);
    }

    //Rounding the number
    bool add = false;
    if (decimalsResult[precision] >= '5')
        add = true;

    decimalsResult.erase(decimalsResult.size() - 1);

    if (add)
        Increment(decimalsResult);

    result.digits = digitsResult;
    result.decimals = decimalsResult;
    result.sign = !sign;
    result.precision = precision;

    return result;
}

LongDouble& LongDouble::operator/=(const LongDouble& number)
{
    *this = *this / number;

    return *this;
}

} //end namespace

