#include "../src/LongNumber.h"

#define BOOST_TEST_MODULE LongNumberMathTest
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace LongNumber;

BOOST_AUTO_TEST_CASE(LongDoubleAbs)
{
    LongDouble x = "-12", y = "3.72";

    BOOST_CHECK(abs(x) == "12");
    BOOST_CHECK(abs(y) == "3.72");
}

