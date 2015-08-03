#ifndef _LONGDOUBLE_H__
#define _LONGDOUBLE_H__

#include <string.h>
#include <iostream>

class LongDouble;

#ifndef _LONGINTEGER_H__
#include "LongInteger.h"
#endif

class LongDouble
{
    public:
        LongDouble(long double, unsigned short int);
        LongDouble(const LongInteger&);

    private:
        unsigned short int decimals;
        bool sign; //true for positive, false for negative
        std::string digits;
};

#endif

