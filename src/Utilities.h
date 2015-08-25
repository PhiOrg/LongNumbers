#ifndef _LongNumber_UTILITIES_H__
#define _LongNumber_UTILITIES_H__

#include <string>

namespace LongNumber
{

/*
 * The first string must be greater than the second string or both strings to
 * have the same size.
 */
std::string GathersNumbers(const std::string&, const std::string&);

/*
 * The first string must be greater than the second string.
 */
std::string DecreasesNumbers(const std::string&, const std::string&);

/*
 * Check if the string represents an integer number.
 */
void CheckString(const std::string&, std::string&, bool&);

/*
 * Return true if the string is not equal with 0, otherwise false.
 */
bool CheckIfStringNotEqualWithZero(const char*, size_t);

/* Return:
 * -1 if a <  b
 *  0 if a == b
 *  1 if a >  b
 */
short int CompareStrings(const std::string&, const std::string&);

/*
 * Doesn't matter if the first string is greater or less than the second
 * string.
 * The third parameter indicates if was taken a unit from the integer part.
 */
std::string DecreasesDecimals(const std::string&, const std::string&, bool&);

/*
 * Doesn't matter if the first string is greater or less than the second
 * string.
 * The third parameter indicates if must added a unit in integer part.
 */
std::string GathersDecimals(const std::string&, const std::string&, bool&);

/*
 * The std::string is incremented with a unit.
 */
void Increment(std::string&);

/*
 * Ths std::string is decremented with a unit. Be sure that the std::string
 * is greater than 0.
 */
void Decrement(std::string&);

} //end namespace

#endif

