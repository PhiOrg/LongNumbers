#include "LongNumberMath.h"

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

} //end namespace

