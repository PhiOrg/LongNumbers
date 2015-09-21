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
 * Computes the natural logarithm from the number passed as parameter.
 */
LongDouble ln(const LongDouble&);

/**
 * This functions computer the euler number (e) with x decimals, where x is
 * passed as parameter.
 */
LongDouble ComputeEulerNumber(size_t);

} //end namespace

#endif

