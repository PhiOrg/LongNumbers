#ifndef _LONGNUMBERMATH_H__
#define _LONGNUMBERMATH_H__

#include "LongInteger.h"
#include "LongDouble.h"
#include "Exception.h"

namespace LongNumber
{

/**
 * Returns the absolut value of x.
 */
LongInteger abs(LongInteger&);

/**
 * Returns the absolut value of x.
 */
LongDouble fabs(LongDouble&);

/**
 * Returns the larger of its arguments: either x or y.
 */
LongDouble fmax(const LongDouble&, const LongDouble&);

/**
 * Returns the smaller of its arguments: either x or y.
 */
LongDouble fmin(const LongDouble&, const LongDouble&);

/**
 * Returns the larger of its arguments: either x or y.
 */
LongInteger max(const LongInteger&, const LongInteger&);

/**
 * Returns the smaller of its arguments: either x or y.
 */
LongInteger min(const LongInteger&, const LongInteger&);

/**
 * Returns the integral value that is nearest to x, with halfway cases rounded
 * away from zero.
 */
LongDouble round(const LongDouble&);

/**
 * Rounds x downward.
 * Returns the largest integer value that is not greater than x.
 */
LongDouble floor(const LongDouble&);

/**
 * Rounds x upward.
 * Returns the smallest integer value that is not less than x.
 */
LongDouble ceil(const LongDouble&);

/**
 * Rounds x toward 0.
 * Returns the nearest integer value that is not larger than x.
 */
LongDouble trunc(const LongDouble&);

/**
 * Returns a value with the magnitude of x and the sign of y.
 */
LongDouble copysign(const LongDouble&, const LongDouble&);

/**
 * Returns true if x is greater than y, otherwise false.
 */
bool isgreater(const LongDouble&, const LongDouble&);

/**
 * Returns true if x is greater than or equal to y, otherwise false.
 */
bool isgreaterequal(const LongDouble&, const LongDouble&);

/**
 * Returns true if x is less than y, otherwise false.
 */
bool isless(const LongDouble&, const LongDouble&);

/**
 * Returns true if x is less than or equal to y, otherwise false.
 */
bool islessequal(const LongDouble&, const LongDouble&);

/**
 * Returns true if x != y, otherwise false.
 */
bool islessgreater(const LongDouble&, const LongDouble&);

/**
 * Returns x - y if x > y, otherwise 0.
 */
LongDouble fdim(const LongDouble&, const LongDouble&);

/**
 * fmod = x - t * y
 * Where t is the truncated result of x / y.
 */
LongDouble fmod(const LongDouble&, const LongDouble&);

/**
 * Breaks x into an integral and a fractional part. Integral part is stored
 * in the second parameter and the fractional part is returned by the function.
 */
LongDouble modf(const LongDouble&, LongDouble&);

/**
 * Computes the natural logarithm from the number passed as parameter.
 */
LongDouble ln(const LongDouble&);

/**
 * This functions computer the euler number (e) with x decimals, where x is
 * passed as parameter.
 */
LongDouble ComputeEulerNumber(size_t);

/**
 * Returns x^y.
 */
LongDouble intpow(const LongDouble&, const LongInteger&);

/**
 * Returns true if x is negative, otherwise false.
 */
bool isnegative(const LongDouble&);

/**
 * Returns true if x is positive, otherwise false.
 */
bool ispositive(const LongDouble&);

/**
 * Returns true if x is negative, otherwise false.
 */
bool isnegative(const LongInteger&);

/**
 * Returns true if x is positive, otherwise false.
 */
bool ispositive(const LongInteger&);

} //end namespace

#endif

