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
LongDouble abs(LongDouble&);

/**
 * Computes the natural logarithm from the number passed as parameter.
 */
LongDouble ln(LongDouble&);

/**
 * This functions computer the euler number (e) with x decimals, where x is
 * passed as parameter.
 */
LongDouble ComputesEulerNumber(size_t);

} //end namespace

#endif

