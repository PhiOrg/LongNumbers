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
    if (a.GetSign() != b.GetSign())
        return false;

    if (a.GetDigits().size() != b.GetDigits().size())
        return false;

    unsigned int size = a.GetDigits().size();
    const string& bDigits = b.GetDigits();
    const string& aDigits = a.GetDigits();
    for (unsigned int i = 0; i < size; i++)
        if (aDigits[i] != bDigits[i])
            return false;

    return true;
}

bool operator!=(const LongInteger& a, const LongInteger& b)
{
    return !(a == b);
}

bool operator>(const LongInteger& a, const LongInteger& b)
{
    if (a.GetSign() && !b.GetSign())
        return true;
    if (!a.GetSign() && b.GetSign())
        return false;

    if (a.GetDigits().size() > b.GetDigits().size())
    {
        if (a.GetSign())
            return true;
        else
            return false;
    }

    if (a.GetDigits().size() < b.GetDigits().size())
    {
        if (a.GetSign())
            return false;
        else
            return true;
    }

    unsigned int size = a.GetDigits().size();
    const string& bDigits = b.GetDigits();
    const string& aDigits = a.GetDigits();
    for (int i = 0; i < size; ++i)
        if (aDigits[i] != bDigits[i])
        {
            if (aDigits[i] > bDigits[i])
                if (a.GetSign())
                    return true;
                else
                    return false;
            else
                if (a.GetSign())
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
    unsigned bsize = b.size(), asize = a.size();
    unsigned bs = bsize - 1, i, as = asize - 1;
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
    unsigned asize = a.size(), bsize = b.size(), as = asize - 1;
    unsigned bs = bsize - 1, i;

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
    if (a.GetSign() == b.GetSign())
    {
        result.SetSign(a.GetSign());
        if (a.GetDigits().size() > b.GetDigits().size())
            result.SetDigits(GathersNumbers(a.GetDigits(), b.GetDigits()));
        else
            result.SetDigits(GathersNumbers(b.GetDigits(), a.GetDigits()));
    }
    else
    {
        if (a == -b)
            return 0;

        if (a.GetSign())
        {
            if (a > -b)
            {
                result.SetSign(a.GetSign());
                result.SetDigits(DecreasesNumbers(a.GetDigits(),
                                                  b.GetDigits()));
            }
            else
            {
                result.SetSign(!a.GetSign());
                result.SetDigits(DecreasesNumbers(b.GetDigits(),
                                                  a.GetDigits()));
            }
        }
        else
        {
            if (a < -b)
            {
                result.SetSign(a.GetSign());
                result.SetDigits(DecreasesNumbers(a.GetDigits(),
                                                  b.GetDigits()));
            }
            else
            {
                result.SetSign(!a.GetSign());
                result.SetDigits(DecreasesNumbers(b.GetDigits(),
                                                  a.GetDigits()));
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

