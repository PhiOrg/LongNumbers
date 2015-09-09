#include "LongNumberMath.h"

using namespace std;

namespace LongNumber
{

LongInteger abs(LongInteger& x)
{
    if (x < 0)
        return -x;

    return x;
}

LongDouble abs(LongDouble& x)
{
    if (x < 0)
        return -x;

    return x;
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
        for (int i = 0; i < precision; i++)
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
        for (int i = 0; i < precision; i++)
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
    return result + result;
}

} //end namespace

