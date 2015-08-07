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

BOOST_AUTO_TEST_CASE(TestNotLogicalOperator)
{
    LongInteger a = 1, b = 0, c = -325;

    BOOST_CHECK(!(!a));
    BOOST_CHECK(!b);
    BOOST_CHECK(!(!c));
}

BOOST_AUTO_TEST_CASE(TestAdditionOperator)
{
    LongInteger a = 973, b = 27, c = 99973, d = 13, e = 23756, f = 9237234;
    LongInteger g = 999999;

    BOOST_CHECK(a + b == 1000);
    BOOST_CHECK(b + c == 100000);
    BOOST_CHECK(b + d == 40);
    BOOST_CHECK(-d + -b == -40);
    BOOST_CHECK(e + f == 9260990);
    BOOST_CHECK(c + e == 123729);
    BOOST_CHECK(f + c == 9337207);
    BOOST_CHECK(d + f == 9237247);
    BOOST_CHECK(-d + -f == -9237247);
    BOOST_CHECK(-a + -b = -1000);
    BOOST_CHECK(-e + -f == -9260990);
    BOOST_CHECK(-c + -e == -123729);
    BOOST_CHECK(-f + -c == -9337207);
    BOOST_CHECK(g + 1 == 1000000);
    BOOST_CHECK(g + 2 == 1000001);
    BOOST_CHECK(g + d == 1000012);

    BOOST_CHECK(c + -a == 99000);
    BOOST_CHECK(b + -d == 14);
    BOOST_CHECK(d + -b == -14);
    BOOST_CHECK(e + -f == -9213478);
    BOOST_CHECK(f + -e == 9213478);
    BOOST_CHECK(g + d + -13 == 999999);

    a = -1;
    b = 1000000;
    BOOST_CHECK(b + -g == 1);
    BOOST_CHECK(g + -b == a);
    BOOST_CHECK(b + a == g);
}

BOOST_AUTO_TEST_CASE(TestDecreaseOperator)
{
    LongInteger a = 973, b = 99973, c = 99972, d = 1, e = 1000;

    BOOST_CHECK(a - b == -99000);
    BOOST_CHECK(b - a == 99000);
    BOOST_CHECK(b - c == 1);
    BOOST_CHECK(c - b == -1);
    BOOST_CHECK(d - e == -999);
    BOOST_CHECK(e - d == 999);
    BOOST_CHECK(e - -d == 1001);
    BOOST_CHECK(a - -b == 100946);
    BOOST_CHECK(b - -c == 199945);
}

BOOST_AUTO_TEST_CASE(TestAssignmentAdditionOperator)
{
    LongInteger a = 5, b = 7;

    a += b;
    BOOST_CHECK(a == 12);

    a += 3;
    BOOST_CHECK(a == 15);
}

BOOST_AUTO_TEST_CASE(TestAssignmentDecreaseOperator)
{
    LongInteger a = 5, b = 7;

    a -= b;
    BOOST_CHECK(a == -2);

    a -= -3;
    BOOST_CHECK(a == 1);
}

BOOST_AUTO_TEST_CASE(TestPrefixIncrementOperator)
{
    LongInteger a = 5, b = 2, c;
    c = ++a + b;

    BOOST_CHECK(c == 8);
    BOOST_CHECK(a == 6);
}

BOOST_AUTO_TEST_CASE(TestPrefixDecrementOperator)
{
    LongInteger a = 5, b = 2, c;
    c = --a + b;

    BOOST_CHECK(c == 6);
    BOOST_CHECK(a == 4);
}

BOOST_AUTO_TEST_CASE(TestPostfixIncrementOperator)
{
    LongInteger a = 5, b = 2, c;
    c = a + b++;

    BOOST_CHECK(c == 7);
    BOOST_CHECK(b == 3);
}

BOOST_AUTO_TEST_CASE(TestPostfixDecrementOperator)
{
    LongInteger a = 5, b = 2, c;
    c = a + b--;

    BOOST_CHECK(c == 7);
    BOOST_CHECK(b == 1);
}

BOOST_AUTO_TEST_CASE(TestMultiplicationOperator)
{
    LongInteger a = 2345, b = 1234, c = 99, d = -7, e = 35;

    BOOST_CHECK(a * 0 == 0);
    BOOST_CHECK(0 * a == 0);
    BOOST_CHECK(1 * a == a);
    BOOST_CHECK(a * 1 == a);
    BOOST_CHECK(-1 * a == -a);
    BOOST_CHECK(a * -1 == -a);
    BOOST_CHECK(d * e == -245);
    BOOST_CHECK(d * -e == 245);
    BOOST_CHECK(c * e == 3465);
    BOOST_CHECK(e * c == 3465);
    BOOST_CHECK(b * d == -8638);
    BOOST_CHECK(d * b == -8638);
    BOOST_CHECK(a * b == 2893730);
    BOOST_CHECK(b * a == 2893730);
    BOOST_CHECK(a * c == 232155);
    BOOST_CHECK(c * a == 232155);
}

BOOST_AUTO_TEST_CASE(TestDivisionOperator)
{
    LongInteger a = 231, b = 1472, c = 2345, d = 400;

    BOOST_CHECK(a / 2 == 115);
    BOOST_CHECK(a / -2 == -115);
    BOOST_CHECK(2 / a == 0);
    BOOST_CHECK(-2 / a == 0);
    BOOST_CHECK(d / 2 == 200);
    BOOST_CHECK(b / 9 = 163);
    BOOST_CHECK(2893730 / c == 1234);
    BOOST_CHECK(2893730 / -c == -1234);
    BOOST_CHECK(a / 10 == 23);
    BOOST_CHECK(a / -10 == -23);
    BOOST_CHECK(-a / -10 == 23);
    BOOST_CHECK(0 / a == 0);
    BOOST_CHECK(0 / -a == 0);
    BOOST_CHECK(b / 1 == b);
    BOOST_CHECK(c / -1 == -c);
    BOOST_CHECK(b / c == 0);
    BOOST_CHECK(c / b == 1);
    BOOST_CHECK(b / -c == 0);
    BOOST_CHECK(-b / c == 0);
    BOOST_CHECK(c / -b == -1);
    BOOST_CHECK(-c / b == -1);
}

BOOST_AUTO_TEST_CASE(TestModuloOperator)
{
    LongInteger a = 231, b = 1472, c = 2345, d = 400;

    BOOST_CHECK(c % 10 == 5);
    BOOST_CHECK(-c % 10 == -5);
    BOOST_CHECK(c % 2 == 1);
    BOOST_CHECK(-c % 2 == -1);
    BOOST_CHECK(a % 2 == 1);
    BOOST_CHECK(-a % 2 == -1);
    BOOST_CHECK(d % 2 == 0);
    BOOST_CHECK(-d % 2 == 0);
    BOOST_CHECK(a % d == 231);
    BOOST_CHECK(d % a == 169);
    BOOST_CHECK(-d % -a == -169);
    BOOST_CHECK(-d % a == -169);
    BOOST_CHECK(-a % -d == -a);
    BOOST_CHECK(-a % d == -231);
    BOOST_CHECK(a % 10 == 1);
    BOOST_CHECK(-a % 10 == -1);
    BOOST_CHECK(-a % -10 == -1);
    BOOST_CHECK(a % -a == 0);
    BOOST_CHECK(-a % a == 0);
    BOOST_CHECK(-a % -a == 0);
    BOOST_CHECK(0 % a == 0);
    BOOST_CHECK(0 % -a == 0);
    BOOST_CHECK(c % d == 345);
    BOOST_CHECK(-c % -d == -345);
    BOOST_CHECK(-c % d == -345);
    BOOST_CHECK(d % c == d);
}

