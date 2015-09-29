#include "../src/LongNumber.h"

#include <boost/test/unit_test.hpp>

using namespace std;
using namespace LongNumber;

BOOST_AUTO_TEST_CASE(LongDoubleAbs)
{
    LongDouble x = "-12", y = "3.72";

    BOOST_CHECK(fabs(x) == "12");
    BOOST_CHECK(fabs(y) == "3.72");
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

BOOST_AUTO_TEST_CASE(TestTrunc)
{
    LongDouble a = 2, b = 2.3, c = 3.8, d = 5.5, e = -2.3, f = -3.8, g = -5.5;

    BOOST_CHECK(trunc(a) == 2);
    BOOST_CHECK(trunc(b) == 2);
    BOOST_CHECK(trunc(c) == 3);
    BOOST_CHECK(trunc(d) == 5);
    BOOST_CHECK(trunc(e) == -2);
    BOOST_CHECK(trunc(f) == -3);
    BOOST_CHECK(trunc(g) == -5);
}

BOOST_AUTO_TEST_CASE(TestCopysign)
{
    LongDouble a = 10, b = -10, c = 1, d = -1;

    BOOST_CHECK(copysign(a, c) == a);
    BOOST_CHECK(copysign(a, d) == b);
    BOOST_CHECK(copysign(b, c) == a);
    BOOST_CHECK(copysign(b, d) == b);
}

BOOST_AUTO_TEST_CASE(fdimTest)
{
    LongDouble a = 2, b = 1, c = -2, d = -1;

    BOOST_CHECK(fdim(a, b) == 1);
    BOOST_CHECK(fdim(b, a) == 0);
    BOOST_CHECK(fdim(c, d) == 0);
    BOOST_CHECK(fdim(d, c) == 1);
}

BOOST_AUTO_TEST_CASE(fmodTest)
{
    LongDouble a = 5.3, b = 2, c = 18.5, d = 4.2;

    BOOST_CHECK(fmod(a, b) == 1.3);
    BOOST_CHECK(fmod(a, -b) == 1.3);
    BOOST_CHECK(fmod(-a, b) == -1.3);
    BOOST_CHECK(fmod(-a, -b) == -1.3);
    BOOST_CHECK(fmod(c, d) == 1.7);
    BOOST_CHECK(fmod(c, -d) == 1.7);
    BOOST_CHECK(fmod(-c, d) == -1.7);
    BOOST_CHECK(fmod(-c, -d) == -1.7);
}

BOOST_AUTO_TEST_CASE(modfTest)
{
    LongDouble a = "3.14159265", c;
    LongInteger b;

    c = modf(a, b);
    BOOST_CHECK(c == "0.14159265" && b == 3);
    c = modf(-a, b);
    BOOST_CHECK(c == "-0.14159265" && b == -3);
}

BOOST_AUTO_TEST_CASE(intpowTest)
{
    size_t result = 2, size;
    BOOST_CHECK(intpow(2, 0) == 1);

    if (sizeof(size_t) == 4)
        size = 32;
    else
        size = 64;

    for (size_t i = 1; i < size; i++)
    {
        BOOST_CHECK(intpow(2, i) == result);
        result *= 2;
    }

    BOOST_CHECK(intpow(2, -10) == 0.000977);
}

