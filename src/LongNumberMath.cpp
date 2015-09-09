#include "LongNumberMath.h"

namespace LongNumber
{

LongInteger abs(LongInteger& x)
{
    if (x < 0)
        return -x;

    return x;
}

} //end namespace

