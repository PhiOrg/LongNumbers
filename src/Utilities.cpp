#include "Utilities.h"

using namespace std;

namespace LongNumber
{

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

void CheckString(const string& number, string& digits, bool& sign)
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

bool CheckIfStringNotEqualWithZero(const char* str, size_t size)
{
    for (size_t i = 0; i < size; i++)
        if (str[i] != '0')
            return true;

    return false;
}

/*
 * Return:
 * -1 if a <  b
 *  0 if a == b
 *  1 if a >  b
 */
short int CompareStrings(const string& a, const string& b)
{
    size_t sizeA = a.size(), sizeB = b.size();
    size_t size = sizeA > sizeB ? sizeA : sizeB;
    for (size_t i = 0; i < size; i++)
    {
        if (a[i] != b[i])
        {
            if (a[i] > b[i])
                return 1;
            else
                return -1;
        }
    }

    if (sizeA == size)
    {
        if (CheckIfStringNotEqualWithZero(b.c_str() + size, sizeB - size))
            return -1;
        else
            return 0;
    }
    else
    {
        if (CheckIfStringNotEqualWithZero(a.c_str() + size, sizeA - size))
            return 1;
        else
            return 0;
    }
}

string DecreasesDecimals(const string& a, const string& b, bool& taken)
{
    string result = a;
    size_t sizeA = a.size() - 1, sizeB = b.size() - 1;
    if (sizeA < sizeB)
    {
        for (size_t i = sizeA; i < sizeB; i++)
            result.push_back('0');
    }

    short int value;
    bool decreases = false;
    for (size_t i = sizeB; i > 0; i--)
    {
        value = a[i] - b[i];
        if (decreases)
        {
            value--;
            decreases = false;
        }
        if (value < 0)
        {
            value += 10;
            decreases = true;
        }
        result[i] = value + 48;
    }

    value = a[0] - b[0];
    if (decreases)
        value--;
    if (value < 0)
    {
        value += 10;
        taken = true;
    }
    result[0] = value + 48;

    return result;
}

} //end namespace

