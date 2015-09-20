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

BOOST_AUTO_TEST_CASE(TestRound)
{
    LongDouble a = 2, b = 2.3, c = 3.8, d = 5.5, e = -2.3, f = -3.8, g = -5.5;

    BOOST_CHECK(round(a) == 2);
    BOOST_CHECK(round(b) == 2);
    BOOST_CHECK(round(c) == 4);
    BOOST_CHECK(round(d) == 6);
    BOOST_CHECK(round(e) == -2);
    BOOST_CHECK(round(f) == -4);
    BOOST_CHECK(round(g) == -6);
}

BOOST_AUTO_TEST_CASE(TestFloor)
{
    LongDouble a = 2, b = 2.3, c = 3.8, d = 5.5, e = -2.3, f = -3.8, g = -5.5;

    BOOST_CHECK(floor(a) == 2);
    BOOST_CHECK(floor(b) == 2);
    BOOST_CHECK(floor(c) == 3);
    BOOST_CHECK(floor(d) == 5);
    BOOST_CHECK(floor(e) == -3);
    BOOST_CHECK(floor(f) == -4);
    BOOST_CHECK(floor(g) == -6);
}

BOOST_AUTO_TEST_CASE(TestCeil)
{
    LongDouble a = 2, b = 2.3, c = 3.8, d = 5.5, e = -2.3, f = -3.8, g = -5.5;

    BOOST_CHECK(ceil(a) == 2);
    BOOST_CHECK(ceil(b) == 3);
    BOOST_CHECK(ceil(c) == 4);
    BOOST_CHECK(ceil(d) == 6);
    BOOST_CHECK(ceil(e) == -2);
    BOOST_CHECK(ceil(f) == -3);
    BOOST_CHECK(ceil(g) == -5);
}

