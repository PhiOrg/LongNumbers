#ifndef _LongNumber_UTILITIES_H__
#define _LongNumber_UTILITIES_H__

#include <string>

namespace LongNumber
{

std::string GathersNumbers(const std::string&, const std::string&);

std::string DecreasesNumbers(const std::string&, const std::string&,
                             bool = true);

void CheckString(const std::string&, std::string&, bool&);

bool CheckIfStringNotEqualWithZero(const char*, size_t);

short int CompareStrings(const std::string&, const std::string&);

} //end namespace

#endif

