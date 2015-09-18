#include "../src/LongNumber.h"

#include <boost/test/unit_test.hpp>

using namespace std;
using namespace LongNumber;

BOOST_AUTO_TEST_CASE(LongDoubleAbs)
{
    LongDouble x = "-12", y = "3.72";

    BOOST_CHECK(abs(x) == "12");
    BOOST_CHECK(abs(y) == "3.72");
}

BOOST_AUTO_TEST_CASE(LongIntegerAbs)
{
    LongInteger x = -1, y = 3;

    BOOST_CHECK(abs(x) == 1);
    BOOST_CHECK(abs(y) == 3);
}

BOOST_AUTO_TEST_CASE(fmaxTest)
{
    LongDouble a = 2.34, b = 3.75, c = -3.75;

    BOOST_CHECK(fmax(a, b) == b);
    BOOST_CHECK(fmax(b, a) == b);
    BOOST_CHECK(fmax(c, b) == b);
    BOOST_CHECK(fmax(a, c) == a);
}

