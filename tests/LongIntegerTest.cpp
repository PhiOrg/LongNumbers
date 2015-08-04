#include "../src/LongNumber.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE LongIntegerTest
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(TestConstructorInt)
{
    int number = 5;
    LongInteger a(number);
    BOOST_CHECK(a.GetSignForTests() && a.GetDigitsForTests() == "5");

    number = -5;
    LongInteger b(number);
    BOOST_CHECK(!b.GetSignForTests() && b.GetDigitsForTests() == "5");
}

BOOST_AUTO_TEST_CASE(TestConstructorLong)
{
    long number = 123456789;
    LongInteger a(number);
    BOOST_CHECK(a.GetSignForTests() && a.GetDigitsForTests() == "123456789");

    LongInteger b(-number);
    BOOST_CHECK(!b.GetSignForTests() && b.GetDigitsForTests() == "123456789");
}

BOOST_AUTO_TEST_CASE(TestConstructorLongLong)
{
    long long number = 446744073709551616;
    LongInteger a(number);
    BOOST_CHECK(a.GetSignForTests() &&
                a.GetDigitsForTests() == "446744073709551616");

    LongInteger b(-number);
    BOOST_CHECK(!b.GetSignForTests() &&
                b.GetDigitsForTests() == "446744073709551616");
}

BOOST_AUTO_TEST_CASE(TestConstructorUnsigned)
{
    unsigned number = 123;
    LongInteger a(number);
    BOOST_CHECK(a.GetSignForTests() && a.GetDigitsForTests() == "123");
}

BOOST_AUTO_TEST_CASE(TestConstructorUnsignedLong)
{
    unsigned long number = 432156789;
    LongInteger a(number);
    BOOST_CHECK(a.GetSignForTests() && a.GetDigitsForTests() == "432156789");
}

BOOST_AUTO_TEST_CASE(TestConstructorUnsignedLongLong)
{
    unsigned long long number = 8446744073709551616;
    LongInteger a(number);
    BOOST_CHECK(a.GetSignForTests() &&
                a.GetDigitsForTests() == "8446744073709551616");
}

BOOST_AUTO_TEST_CASE(TestConstructorLongInteger)
{
    LongInteger a(5);
    LongInteger b(a);
    BOOST_CHECK(b.GetSignForTests() && b.GetDigitsForTests() == "5");
}

BOOST_AUTO_TEST_CASE(TestConstructorByDefault)
{
    LongInteger a;
    BOOST_CHECK(a.GetSignForTests() && a.GetDigitsForTests() == "0");
}

BOOST_AUTO_TEST_CASE(TestConstructorString)
{
    LongInteger a("a123");
    BOOST_CHECK(a.GetSignForTests() && a.GetDigitsForTests() == "0");

    LongInteger b("-12asd3");
    BOOST_CHECK(b.GetSignForTests() && b.GetDigitsForTests() == "0");

    LongInteger c("-");
    BOOST_CHECK(c.GetSignForTests() && c.GetDigitsForTests() == "0");

    LongInteger d("+");
    BOOST_CHECK(d.GetSignForTests() && d.GetDigitsForTests() == "0");

    LongInteger e("00000000");
    BOOST_CHECK(e.GetSignForTests() && d.GetDigitsForTests() == "0");

    LongInteger f("-00000000");
    BOOST_CHECK(f.GetSignForTests() && f.GetDigitsForTests() == "0");

    LongInteger g("000000002");
    BOOST_CHECK(g.GetSignForTests() && g.GetDigitsForTests() == "2");

    LongInteger h("-00000000234");
    BOOST_CHECK(!h.GetSignForTests() && h.GetDigitsForTests() == "234");

    LongInteger i("1996");
    BOOST_CHECK(i.GetSignForTests() && i.GetDigitsForTests() == "1996");

    LongInteger j("-123");
    BOOST_CHECK(!j.GetSignForTests() && j.GetDigitsForTests() == "123");
}

BOOST_AUTO_TEST_CASE(TestAssignmentOperator)
{
    LongInteger a(5);
    LongInteger b = a;
    BOOST_CHECK(b.GetSignForTests() && b.GetDigitsForTests() == "5");

    LongInteger c;
    c = 10;
    BOOST_CHECK(c.GetSignForTests() && c.GetDigitsForTests() == "10");
}

BOOST_AUTO_TEST_CASE(TestEqualOperator)
{
    LongInteger a, b, c;
    a = 15;
    b = c = -15;

    BOOST_CHECK(!(a == b));
    BOOST_CHECK(b == c);
    BOOST_CHECK(a == 15);
}

BOOST_AUTO_TEST_CASE(TestNotEqualOperator)
{
    LongInteger a, b, c;
    a = 15;
    b = c = -15;

    BOOST_CHECK(!(b != c));
    BOOST_CHECK(a != b);
    BOOST_CHECK(c != 3);
}

BOOST_AUTO_TEST_CASE(TestGreaterOperator)
{
    LongInteger a = 2, b = 3, c = -5, d = -7;

    BOOST_CHECK(!(a > b));
    BOOST_CHECK(b > a);
    BOOST_CHECK(a > c);
    BOOST_CHECK(a > 0);
    BOOST_CHECK(!(c > 0));
    BOOST_CHECK(c > d);
    BOOST_CHECK(!(d > c));
    BOOST_CHECK(!(a > a));
    BOOST_CHECK(b > 1);
    BOOST_CHECK(c > -123);
}

BOOST_AUTO_TEST_CASE(TestLessOperator)
{
    LongInteger a = 2, b = 3, c = -5;

    BOOST_CHECK(a < b);
    BOOST_CHECK(c < b);
    BOOST_CHECK(c < -1);
    BOOST_CHECK(c < 0);
    BOOST_CHECK(!(b < a));
    BOOST_CHECK(!(a < 0));
    BOOST_CHECK(b < 123);
}

BOOST_AUTO_TEST_CASE(TestGreaterOrEqualOperator)
{
    LongInteger a = 1, b = 2, c = 3, d = -4;

    BOOST_CHECK(c >= b);
    BOOST_CHECK(a >= a);
    BOOST_CHECK(!(a >= b));
    BOOST_CHECK(b >= -12);
    BOOST_CHECK(c >= d);
    BOOST_CHECK(d >= -4);
    BOOST_CHECK(d >= -5);
}

BOOST_AUTO_TEST_CASE(TestLessOrEqualOperator)
{
    LongInteger a = 1, b = 2, c = 3, d = -4;

    BOOST_CHECK(b <= c);
    BOOST_CHECK(a <= a);
    BOOST_CHECK(!(b <= a));
    BOOST_CHECK(b <= 12);
    BOOST_CHECK(d <= c);
    BOOST_CHECK(d <= -4);
    BOOST_CHECK(d <= -3);
}

BOOST_AUTO_TEST_CASE(TestUnaryMinusOperator)
{
    LongInteger a = 1, b = -a;

    BOOST_CHECK(b == -1);
    BOOST_CHECK(-b == a);
}

BOOST_AUTO_TEST_CASE(TestBoolCast)
{
    LongInteger a = 1, b = 0, c = -325;

    BOOST_CHECK(a);
    BOOST_CHECK(!b);
    BOOST_CHECK(c);
}

