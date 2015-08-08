#include "LongInteger.h"

using namespace std;

namespace LongNumber
{

LongInteger::LongInteger(const LongDouble& number)
{
    digits = number.GetDigits();
    sign = number.GetSign();
}

LongInteger::LongInteger()
{
    sign = true;
    digits = "0";
}

LongInteger::LongInteger(const int number)
{
    int x = number;
    if (number < 0)
    {
        sign = false;
        x *= -1;
    }
    else
        sign = true;

    digits = to_string(x);
}

LongInteger::LongInteger(const long number)
{
    long x = number;
    if (number < 0)
    {
        sign = false;
        x *= -1;
    }
    else
        sign = true;

    digits = to_string(x);
}

LongInteger::LongInteger(const long long number)
{
    long long x = number;
    if (number < 0)
    {
        sign = false;
        x *= -1;
    }
    else
        sign = true;

    digits = to_string(x);
}

LongInteger::LongInteger(const unsigned number)
{
    sign = true;
    digits = to_string(number);
}

LongInteger::LongInteger(const unsigned long number)
{
    sign = true;
    digits = to_string(number);
}

LongInteger::LongInteger(const unsigned long long number)
{
    sign = true;
    digits = to_string(number);
}

LongInteger::LongInteger(const LongInteger& number)
{
    digits = number.GetDigits();
    sign = number.GetSign();
}

LongInteger::LongInteger(const char *_number)
{
    string number = _number;
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

        size_t size = digits.size();
        for (size_t i = 0; i < size; i++)
            if (digits[i] < '0' || digits[i] > '9')
            {
                sign = true;
                digits = "0";
                return;
            }

        size_t i = 0, zerosNumber = 0;
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

        size_t size = digits.size();
        for (size_t i = 0; i < size; i++)
            if (digits[i] < '0' || digits[i] > '9')
            {
                sign = true;
                digits = "0";
                return;
            }

        size_t i = 0, zerosNumber = 0;
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

const string& LongInteger::GetDigits() const
{
    return digits;
}

bool LongInteger::GetSign() const
{
    return sign;
}

LongInteger& LongInteger::operator=(const LongInteger& number)
{
    this->digits = number.GetDigits();
    this->sign = number.GetSign();

    return *this;
}

bool operator==(const LongInteger& a, const LongInteger& b)
{
    if (a.sign != b.sign)
        return false;

    if (a.digits.size() != b.digits.size())
        return false;

    size_t size = a.digits.size();
    for (size_t i = 0; i < size; i++)
        if (a.digits[i] != b.digits[i])
            return false;

    return true;
}

bool operator!=(const LongInteger& a, const LongInteger& b)
{
    return !(a == b);
}

bool operator>(const LongInteger& a, const LongInteger& b)
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

    return false;
}

bool operator<(const LongInteger& a, const LongInteger& b)
{
    return !(a > b);
}

bool operator>=(const LongInteger& a, const LongInteger& b)
{
    if (a > b)
    {
        return true;
    }
    else
    {
        return a == b;
    }
}

bool operator<=(const LongInteger& a, const LongInteger& b)
{
    if (a < b)
    {
        return true;
    }
    else
    {
        return a == b;
    }
}

void LongInteger::SetSign(bool value)
{
    sign = value;
}

LongInteger LongInteger::operator-() const
{
    LongInteger a(*this);
    a.SetSign(!sign);

    return a;
}

LongInteger::operator bool() const
{
    if (*this != 0)
        return true;
    else
        return false;
}

bool LongInteger::operator!() const
{
    if (*this == 0)
        return true;
    else
        return false;
}

void LongInteger::SetDigits(const std::string& digits)
{
    this->digits = digits;
}

string GathersNumbers(const string& a, const string& b)
{
    string result = a;
    size_t bsize = b.size(), asize = a.size();
    size_t bs = bsize - 1, i, as = asize - 1;
    short int value;
    bool add = false;
    for (i = 0; i < bsize; i++)
    {
        value = a[as - i] + b[bs - i] - 96;
        if (add)
        {
            value++;
            add = false;
        }
        if (value > 9)
        {
            value %= 10;
            add = true;
        }
        result[as - i] = value + 48;
    }

    while (add && i < asize)
    {
        value = a[as - i] - 47;
        add = false;
        if (value > 9)
        {
            value %= 10;
            add = true;
        }
        result[as - i] = value + 48;
        i++;
    }

    if (add)
        result.insert(result.begin(), '1');

    return result;
}

string DecreasesNumbers(const string& a, const string& b)
{
    bool decreases = false;
    short int value;
    string result = a;
    size_t asize = a.size(), bsize = b.size(), as = asize - 1;
    size_t bs = bsize - 1, i;

    for (i = 0; i < bsize; i++)
    {
        if (decreases)
        {
            decreases = false;
            value = a[as - i] - b[bs - i] - 1;
        }
        else
        {
            value = a[as - i] - b[bs - i];
        }

        if (value < 0)
        {
            decreases = true;
            value += 10;
        }

        result[as - i] = value + 48;
    }

    while (decreases && i < asize)
    {
        value = a[as - i] - 49;
        decreases = false;
        if (value < 0)
        {
            value += 10;
            decreases = true;
        }
        result[as - i] = value + 48;
        i++;
    }

    for (i = 0; i < asize; i++)
        if (result[i] != '0')
            break;

    result.erase(0, i);

    return result;
}

LongInteger operator+(const LongInteger& a, const LongInteger& b)
{
    LongInteger result;
    if (a.sign == b.sign)
    {
        result.sign = a.sign;
        if (a.digits.size() > b.digits.size())
            result.digits = GathersNumbers(a.digits, b.digits);
        else
            result.digits = GathersNumbers(b.digits, a.digits);
    }
    else
    {
        if (a == -b)
            return 0;

        if (a.sign)
        {
            if (a > -b)
            {
                result.sign = true;;
                result.digits = DecreasesNumbers(a.digits, b.digits);
            }
            else
            {
                result.sign = false;
                result.digits = DecreasesNumbers(b.digits, a.digits);
            }
        }
        else
        {
            if (a < -b)
            {
                result.sign = false;
                result.digits = DecreasesNumbers(a.digits, b.digits);
            }
            else
            {
                result.sign = true;
                result.digits = DecreasesNumbers(b.digits, a.digits);
            }
        }
    }

    return result;
}

LongInteger operator-(const LongInteger& a, const LongInteger& b)
{
    return a + -b;
}

LongInteger& LongInteger::operator+=(const LongInteger& number)
{
    *this = *this + number;

    return *this;
}

LongInteger& LongInteger::operator-=(const LongInteger& number)
{
    *this = *this - number;

    return *this;
}

LongInteger& LongInteger::operator++()
{
    *this = *this + 1;

    return *this;
}

LongInteger& LongInteger::operator--()
{
    *this = *this - 1;
    
    return *this;
}

LongInteger LongInteger::operator++(int)
{
    LongInteger result(*this);

    *this = *this + 1;

    return result;
}

LongInteger LongInteger::operator--(int)
{
    LongInteger result(*this);

    *this = *this - 1;

    return result;
}

string Multiplies(const string& a, short int b)
{
    string result;
    short int add = 0, value;
    for (auto i = a.rbegin(); i != a.rend(); i++)
    {
        value = (*i - 48) * b + add;
        add = 0;
        if (value > 9)
        {
            add = value / 10;
            value %= 10;
        }
        result.insert(result.begin(), value + 48);
    }

    if (add != 0)
        result.insert(result.begin(), add + 48);

    return result;
}

LongInteger MultipliesIntegers(const string& a, const string& b)
{
    LongInteger result;
    string _a = a;

    for (auto i = b.rbegin(); i != b.rend(); i++)
    {
        short int value = *i - 48;

        if (value == 1)
            result += _a;
        else
            if (value > 1)
                result += Multiplies(_a, value);
        _a.push_back('0');
    }

    return result;
}

LongInteger operator*(const LongInteger& a, const LongInteger& b)
{
    if (a == 0 || b == 0)
        return 0;
    if (a == 1)
        return b;
    if (a == -1)
        return -b;
    if (b == 1)
        return a;
    if (b == -1)
        return -a;
    if (b == 10)
    {
        LongInteger result(a);
        MultiplyBy10(result, 1);

        return result;
    }
    if (b == -10)
    {
        LongInteger result(a);
        MultiplyBy10(result, 1);
        result.sign = !result.sign;

        return result;
    }

    LongInteger result;

    if (a.sign == b.sign)
    {
        result.sign = true;
    }
    else
    {
        result.sign = false;
    }

    if (a.digits.size() > b.digits.size())
    {
        result.digits = MultipliesIntegers(a.digits, b.digits).digits;
    }
    else
    {
        result.digits = MultipliesIntegers(b.digits, a.digits).digits;
    }

    return result;
}

LongInteger& LongInteger::operator*=(const LongInteger& number)
{
    *this = *this * number;

    return *this;
}

void MultiplyBy10(LongInteger& a, size_t x)
{
    if (a.digits == "0")
        return;
    for (size_t i = 0; i < x; i++)
        a.digits.push_back('0');
}

void DivisionBy10(LongInteger& a, size_t x)
{
    for (size_t i = 0; i < x; i++)
        a.digits.pop_back();

    if (a.digits.size() == 0)
    {
        a.sign = true;
        a.digits.push_back('0');
    }
}

LongInteger _abs(const LongInteger& a)
{
    LongInteger result(a);
    result.sign = true;

    return result;
}

LongInteger operator/(const LongInteger& a, const LongInteger& b)
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
    if (_abs(a) < _abs(b))
    {
        return 0;
    }

    if (b == 10)
    {
        LongInteger result(a);
        DivisionBy10(result, 1);

        return result;
    }

    if (b == -10)
    {
        LongInteger result(-a);
        DivisionBy10(result, 1);

        return result;
    }

    LongInteger c(a), d(b), result;
    bool sign = c.sign && d.sign;
    c.sign = true;
    d.sign = true;
    size_t value;

    if (c.digits[0] > d.digits[0])
    {
        value = c.digits.size() - d.digits.size();
        MultiplyBy10(d, value);
    }

    if (c.digits[0] == d.digits[0])
    {
        value = c.digits.size() - d.digits.size();
        MultiplyBy10(d, value);

        if (c < d)
        {
            DivisionBy10(d, 1);
            value--;
        }
    }

    if (c.digits[0] < d.digits[0])
    {
        value = c.digits.size() - d.digits.size() - 1;
        MultiplyBy10(d, value);
    }

    value++;
    while (c > 0 && value > 0)
    {
        short int x = 0;
        while (c >= d)
        {
            c -= d;
            x++;
        }

        MultiplyBy10(result, 1);
        DivisionBy10(d, 1);
        result += x;
        value--;
    }

    if (value > 0)
        MultiplyBy10(result, value);

    result.sign = sign;
    return result;
}

LongInteger& LongInteger::operator/=(const LongInteger& number)
{
    *this = *this / number;

    return *this;
}

LongInteger operator%(const LongInteger& a, const LongInteger& b)
{
    LongInteger d = _abs(b);
    if (b == 0)
        throw ModuloByZero();
    if (a == d)
        return 0;
    if (a == -d)
        return 0;
    if (d == 1)
        return 0;
    if (a == 0)
        return 0;
    if (_abs(a) < d)
    {
        return a;
    }

    if (d == 10)
    {
        int value = a.digits[a.digits.size() - 1] - 48;
        if (!a.sign)
            value *= -1;
        return value;
    }

    if (d == 2)
    {
        int value = a.digits[a.digits.size() - 1] - 48;
        if (!a.sign)
            value *= -1;
        return value % 2;
    }

    LongInteger c(a);
    bool sign = c.sign;
    c.sign = true;
    size_t value;

    if (c.digits[0] > d.digits[0])
    {
        value = c.digits.size() - d.digits.size();
        MultiplyBy10(d, value);
    }

    if (c.digits[0] == d.digits[0])
    {
        value = c.digits.size() - d.digits.size();
        MultiplyBy10(d, value);

        if (c < d)
        {
            DivisionBy10(d, 1);
            value--;
        }
    }

    if (c.digits[0] < d.digits[0])
    {
        value = c.digits.size() - d.digits.size() - 1;
        MultiplyBy10(d, value);
    }

    value++;
    while (c > 0 && value > 0)
    {
        while (c >= d)
            c -= d;

        DivisionBy10(d, 1);
        value--;
    }

    if (c != 0)
        c.sign = sign;

    return c;
}

LongInteger& LongInteger::operator%=(const LongInteger& number)
{
    *this = *this % number;

    return *this;
}

LongInteger& LongInteger::operator=(const LongDouble& number)
{
    *this = (LongInteger) number;

    return *this;
}

} //end namespace

