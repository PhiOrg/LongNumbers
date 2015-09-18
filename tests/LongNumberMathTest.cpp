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

BOOST_AUTO_TEST_CASE(fminTest)
{
    LongDouble a = 2.34, b = 3.75, c = -3.75;

    BOOST_CHECK(fmin(a, b) == a);
    BOOST_CHECK(fmin(b, a) == a);
    BOOST_CHECK(fmin(c, b) == c);
    BOOST_CHECK(fmin(a, c) == c);
}

BOOST_AUTO_TEST_CASE(maxTest)
{
    LongDouble a = 2, b = 3, c = -3;

    BOOST_CHECK(max(a, b) == b);
    BOOST_CHECK(max(b, a) == b);
    BOOST_CHECK(max(c, b) == b);
    BOOST_CHECK(max(a, c) == a);
}

BOOST_AUTO_TEST_CASE(minTest)
{
    LongDouble a = 2, b = 3, c = -3;

    BOOST_CHECK(min(a, b) == a);
    BOOST_CHECK(min(b, a) == a);
    BOOST_CHECK(min(c, b) == c);
    BOOST_CHECK(min(a, c) == c);
}

