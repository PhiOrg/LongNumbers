#include "LongNumberMath.h"
#include "Constants.h"

using namespace std;

namespace LongNumber
{

#define ADDITIONAL_PRECISION 5
#define STANDARD_PRECISION 100

LongInteger abs(LongInteger& x)
{
    if (x < 0)
        return -x;

    return x;
}

LongDouble fabs(LongDouble& x)
{
    if (x < 0)
        return -x;

    return x;
}

LongDouble fmax(const LongDouble& x, const LongDouble& y)
{
    if (x > y)
        return x;
    else
        return y;
}

LongDouble fmin(const LongDouble& x, const LongDouble& y)
{
    if (x < y)
        return x;
    else
        return y;
}

LongInteger max(const LongInteger& x, const LongInteger& y)
{
    if (x > y)
        return x;
    else
        return y;
}

LongInteger min(const LongInteger& x, const LongInteger& y)
{
    if (x < y)
        return x;
    else
        return y;
}

LongDouble round(const LongDouble& x)
{
    if (x.IsInteger())
        return x;

    if (x.GetDecimals()[0] > '4')
    {
        LongDouble result;
        result.SetDigits(x.GetDigits());
        result++;
        result.SetSign(x.GetSign());

        return result;
    }
    else
    {
        LongDouble result;
        result.SetDigits(x.GetDigits());
        result.SetSign(x.GetSign());

        return result;
    }
}

LongDouble floor(const LongDouble& x)
{
    if (x.IsInteger())
        return x;

    if (x.GetSign())
    {
        LongDouble result;
        result.SetDigits(x.GetDigits());

        return result;
    }
    else
    {
        LongDouble result;
        result.SetDigits(x.GetDigits());
        result++;
        result.SetSign(false);

        return result;
    }
}

LongDouble ceil(const LongDouble& x)
{
    if (x.IsInteger())
        return x;

    if (x.GetSign())
    {
        LongDouble result;
        result.SetDigits(x.GetDigits());
        result++;

        return result;
    }
    else
    {
        LongDouble result;
        result.SetDigits(x.GetDigits());
        result.SetSign(false);

        return result;
    }
}

LongDouble trunc(const LongDouble& x)
{
    LongDouble result;
    result.SetDigits(x.GetDigits());
    result.SetSign(x.GetSign());

    return result;
}

LongDouble copysign(const LongDouble& x, const LongDouble& y)
{
    LongDouble result = x;
    result.SetSign(y.GetSign());

    return result;
}

bool isgreater(const LongDouble& x, const LongDouble& y)
{
    return x > y;
}

bool isgreaterequal(const LongDouble& x, const LongDouble& y)
{
    return x >= y;
}

bool isless(const LongDouble& x, const LongDouble& y)
{
    return x < y;
}

bool islessequal(const LongDouble& x, const LongDouble& y)
{
    return x <= y;
}

bool islessgreater(const LongDouble& x, const LongDouble& y)
{
    return x != y;
}

LongDouble fdim(const LongDouble& x, const LongDouble& y)
{
    if (x > y)
        return x - y;
    else
        return 0;
}

LongDouble fmod(const LongDouble& x, const LongDouble& y)
{
    LongDouble result = x;
    result /= y;
    result.SetDigits("0");
    result *= y;
    result.SetSign(x.GetSign());

    return result;
}

LongDouble modf(const LongDouble& x, LongDouble& intpart)
{
    LongDouble result = x;
    intpart = x;

    intpart.RoundsNumber();
    result.SetDigits("0");

    return result;
}

/**
 * Helper for ln().
 * Computes ln(x) if (x > 0 && x < 1) or x > 1.
 *
 * ln(x) = 2 * ((x - 1) / (x + 1) + (((x - 1) / (x + 1)) ^ 3) / 3 +
 *              (((x - 1) / (x + 1)) ^ 5) / 5 + ...)
 *
 *  Initialize result with (x - 1) / (x + 1) and then computes
 *  ((x - 1) / (x + 1) ^ n) / n until this result is less than 0.x1, where
 *  x represents the precision - 1 of x and n grow from 2 in 2.
 */
LongDouble _ln(LongDouble& x)
{
    x.SetPrecisionWithoutRounding(x.GetPrecision() + ADDITIONAL_PRECISION);

    /**
     * The growth value of the power. The power grow from 2 in to.
     */
    static const LongInteger growthValue = 2;

    /**
     * Represents ((x - 1) / (x + 1) ^ n). At each iteration, it is multiplied
     * with ratioSquare.
     */
    LongDouble ratio = (x - 1) / (x + 1);

    /**
     * Represents the result of the following calculation:
     * (x - 1) / (x + 1) + (((x - 1) / (x + 1)) ^ 3) / 3 +
     * (((x - 1) / (x + 1)) ^ 5) / 5 + ...
     * Is initialized with (x - 1) / (x + 1)
     */
    LongDouble result = ratio;

    /**
     * Represents ((x - 1) / (x + 1)) ^ 2.
     */
    const LongDouble ratioSquare = ratio * ratio;

    /**
     * Represents the power at that was raised the ratio and also the number
     * at that must divided the ratio.
     */
    LongInteger power = 3;

    if (ratio.GetSign())
    {
        /**
         * On this branch is computed ln(x) if x > 1.
         */

        /**
         * Computes the limits to which must arrive the ratio.
         */
        string str = "0.";
        size_t precision = x.GetPrecision() - 1;
        for (size_t i = 0; i < precision; i++)
            str.push_back('0');
        str.push_back('1');
        const LongDouble limit = str;

        /**
         * Iterates until the ration arrive at the established limit.
         */
        while (1)
        {
            /**
             * Computes ((x - 1) / (x + 1)) ^ n
             */
            ratio *= ratioSquare;

            /**
             * Computes (((x - 1) / (x + 1)) ^ n) / n
             */
            LongDouble partialResult = ratio / power;

            /**
             * Checks if the limit was reached.
             */
            if (partialResult < limit)
                break;

            /**
             * Gathers (((x - 1) / (x + 1)) ^ n) / n to result.
             */
            result += partialResult;

            /**
             * Grow the power with 2 units.
             */
            power += growthValue;
        }
    }
    else
    {
        /**
         * On this branch is computes ln(x) if x > 0 && x < 1.
         */

        /**
         * Computes the limit to which must arrive the ratio.
         */
        string str = "-0.";
        size_t precision = x.GetPrecision() - 1;
        for (size_t i = 0; i < precision; i++)
            str.push_back('0');
        str.push_back('1');
        const LongDouble limit = str;

        /**
         * Iterates until the ratio arrive at the established limit.
         */
        while (1)
        {
            /**
             * Computes ((x - 1) / (x + 1)) ^ n
             */
            ratio *= ratioSquare;

            /**
             * Computes (((x - 1) / (x + 1)) ^ n) / n
             */
            LongDouble partialResult = ratio / power;

            /**
             * Checks if the limit was reached.
             */
            if (partialResult > limit)
                break;

            /**
             * Gathers (((x - 1) / (x + 1)) ^ n) / n to result.
             */
            result += partialResult;

            /**
             * Grow the power with 2 units.
             */
            power += growthValue;
        }
    }

    /**
     * Result is equal with (x - 1) / (x + 1) + (((x - 1) / (x + 1)) ^ 3) / 3 +
     * (((x - 1) / (x + 1)) ^ 5) / 5 + ...
     * But the ln(x) is equal with 2 * (with that calculation above).
     */
    result += result;
    result.SetPrecisionWithoutRounding(result.GetPrecision() -
                                       ADDITIONAL_PRECISION);

    return result;
}

/**
 * e = 1 / 0! + 1 / 1! + 1 / 2! + 1 / 3! + 1 / 4! + ...
 */
LongDouble ComputeEulerNumber(size_t precision)
{
    if (precision < 6)
        precision = 6;

    LongDouble result = 2;
    result.SetPrecisionWithoutRounding(precision + ADDITIONAL_PRECISION);

    string str = "0.";
    for (size_t i = 0; i < precision; i++)
        str.push_back('0');
    str += "00001";

    const LongDouble limit = str;
    LongDouble partialResult = 1, divisionNumber = 1;
    partialResult.SetPrecisionWithoutRounding(precision + ADDITIONAL_PRECISION);
    divisionNumber.SetPrecisionWithoutRounding(precision + ADDITIONAL_PRECISION);

    while (1)
    {
        divisionNumber++;
        partialResult /= divisionNumber;
        if (partialResult < limit)
            break;
        result += partialResult;
    }

    result.SetPrecisionWithoutRounding(precision);

    return result;
}

LongDouble ln(const LongDouble& x)
{
    if (x == 0)
        throw LnZero();
    if (!x.GetSign())
        throw LnNegativeNumber();
    if (x == 1)
    {
        LongDouble result = 0;
        result.SetPrecision(x.GetPrecision());

        return result;
    }

    LongDouble copyOfX = x;

    if (x > 0 && x < 1)
        return _ln(copyOfX);

    if (x > 1 && x < 3)
        return _ln(copyOfX);

    if (x.GetPrecision() > STANDARD_PRECISION)
    {
        LongDouble result;
        result.SetPrecisionWithoutRounding(x.GetPrecision() +
                                           ADDITIONAL_PRECISION);

        LongDouble __ln10 = 10;
        __ln10.SetPrecisionWithoutRounding(x.GetPrecision() +
                                           ADDITIONAL_PRECISION);
        LongDouble _ln10 = _ln(__ln10);

        size_t power = x.GetDigits().size();
        copyOfX.DivisionBy10(power);
        copyOfX.SetPrecisionWithoutRounding(x.GetPrecision());

        result = power * _ln10 + _ln(copyOfX);
        result.SetPrecisionWithoutRounding(x.GetPrecision());

        return result;
    }
    else
    {
        LongDouble result;
        result.SetPrecisionWithoutRounding(x.GetPrecision() +
                                           ADDITIONAL_PRECISION);

        LongDouble _ln10 = Constants::ln10;
        _ln10.SetPrecisionWithoutRounding(x.GetPrecision() +
                                          ADDITIONAL_PRECISION);

        size_t power = x.GetDigits().size();
        copyOfX.DivisionBy10(power);
        copyOfX.SetPrecisionWithoutRounding(x.GetPrecision());

        result = power * _ln10 + _ln(copyOfX);
        result.SetPrecisionWithoutRounding(x.GetPrecision());

        return result;
    }
}

LongDouble intpow(const LongDouble& x, const LongInteger& y)
{
    if (x == 0)
        return 0;
    if (y == 0 || x == 1)
        return 1;
    if (y == 1)
        return x;
    if (isnegative(y))
        return 1 / intpow(x, -y);

    LongInteger i, j = y, k;
    LongDouble result = 1, partialResult, square = x * x;

    result.SetPrecision(x.GetPrecision());
    partialResult.SetPrecision(x.GetPrecision());

    if (j % 2 == 1)
    {
        result = x;
        j--;
    }

    while (j != 0)
    {
        i = 4;
        k = 2;
        partialResult = square;
        while (i <= j)
        {
            k = i;
            partialResult *= partialResult;
            i += i;
        }
        j -= k;
        result *= partialResult;
    }

    return result;
}

bool isnegative(const LongDouble& x)
{
    return !x.GetSign();
}

bool ispositive(const LongDouble& x)
{
    return x.GetSign();
}

bool isnegative(const LongInteger& x)
{
    return !x.GetSign();
}

bool ispositive(const LongInteger& x)
{
    return x.GetSign();
}

bool signbit(const LongDouble& x)
{
    return x.GetSign();
}

bool signbit(const LongInteger& x)
{
    return x.GetSign();
}

/**
 * Computes e^x, where x is greater than 0 and smallest than 1.
 */
LongDouble _exp(const LongDouble& x)
{
    LongDouble result = 1 + x, y = x, partialResult;
    LongInteger z = 1;
    string _limit;
    size_t precision = x.GetPrecision();

    for (size_t i = 0; i < precision; i++)
        _limit.push_back('0');

    _limit += "00001";
    LongDouble limit = _limit;

    while (1)
    {
        y *= x;
        z++;
        partialResult = y / z;
        if (partialResult < limit)
            break;
        result += partialResult;
    }

    return result;
}

} //end namespace

