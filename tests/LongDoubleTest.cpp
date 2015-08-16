#include "../src/LongNumber.h"

#define BOOST_TEST_MODULE LongDoubleTest
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace LongNumber;

BOOST_AUTO_TEST_CASE(TestLongDoubleConstructor)
{
    LongDouble a(3.17), b(-1923.34646), c(56.123456789, 9);

    BOOST_CHECK(a.GetDigits() == "3" && a.GetDecimals() == "170000" &&
                a.GetSign() && a.GetDecimalsNumber() == 6);
    BOOST_CHECK(b.GetDigits() == "1923" && b.GetDecimals() == "346460" &&
                !b.GetSign() && b.GetDecimalsNumber() == 6);
    BOOST_CHECK(c.GetDigits() == "56" && c.GetDecimals() == "123457000" &&
                c.GetSign() && c.GetDecimalsNumber() == 9);
}

BOOST_AUTO_TEST_CASE(TestLongIntegerConstructor)
{
    LongInteger a = 17, b = -32;
    LongDouble c(a), d(b, 9);

    BOOST_CHECK(c.GetDigits() == "17" && c.GetDecimals() == "000000" &&
                c.GetSign() && c.GetDecimalsNumber() == 6);
    BOOST_CHECK(d.GetDigits() == "32" && d.GetDecimals() == "000000000" &&
                !d.GetSign() && d.GetDecimalsNumber() == 9);
}

BOOST_AUTO_TEST_CASE(TestAssignmentLongDoubleOperator)
{
    LongDouble a(17.23), b(-23.17), c, d;
    c = a;
    d = b;

    BOOST_CHECK(c.GetDigits() == "17" && c.GetDecimals() == "230000" &&
                c.GetSign() && c.GetDecimalsNumber() == 6);
    BOOST_CHECK(d.GetDigits() == "23" && d.GetDecimals() == "170000" &&
                !d.GetSign() && d.GetDecimalsNumber() == 6);
}

BOOST_AUTO_TEST_CASE(TestAssignmentLongIntegerOperator)
{
    LongDouble a, c;
    LongInteger b = 17;
    a = b;
    c = -b;

    BOOST_CHECK(a.GetDigits() == "17" && a.GetDecimals() == "000000" &&
                a.GetSign() && a.GetDecimalsNumber() == 6);
    BOOST_CHECK(c.GetDigits() == "17" && c.GetDecimals() == "000000" &&
                !c.GetSign() && c.GetDecimalsNumber() == 6);
}

BOOST_AUTO_TEST_CASE(TestStringConstructor)
{
    LongDouble a("123"), b("-17"), c("0"), d("0.23"), e("-12934643324.1234", 2);
    LongDouble f("12+.-123"), g("asd"), h("12..79"), i("-123.45a", 8), j("a", 3);

    BOOST_CHECK(a.GetDigits() == "123" && a.GetDecimals() == "000000" &&
                a.GetSign() && a.GetDecimalsNumber() == 6);
    BOOST_CHECK(b.GetDigits() == "17" && b.GetDecimals() == "000000" &&
                !b.GetSign() && b.GetDecimalsNumber() == 6);
    BOOST_CHECK(c.GetDigits() == "0" && a.GetDecimals() == "000000" &&
                c.GetSign() && c.GetDecimalsNumber() == 6);
    BOOST_CHECK(d.GetDigits() == "0" && d.GetDecimals() == "230000" &&
                d.GetSign() && d.GetDecimalsNumber() == 6);
    BOOST_CHECK(e.GetDigits() == "12934643324" && e.GetDecimals() == "12" &&
                !e.GetSign() && e.GetDecimalsNumber() == 2);
    BOOST_CHECK(f.GetDigits() == "0" && f.GetDecimals() == "000000" &&
                f.GetSign() && f.GetDecimalsNumber() == 6);
    BOOST_CHECK(g.GetDigits() == "0" && g.GetDecimals() == "000000" &&
                g.GetSign() && g.GetDecimalsNumber() == 6);
    BOOST_CHECK(h.GetDigits() == "0" && h.GetDecimals() == "000000" &&
                h.GetSign() && h.GetDecimalsNumber() == 6);
    BOOST_CHECK(i.GetDigits() == "0" && i.GetDecimals() == "00000000" &&
                i.GetSign() && i.GetDecimalsNumber() == 8);
    BOOST_CHECK(j.GetDigits() == "0" && j.GetDecimals() == "000" &&
                j.GetSign() && j.GetDecimalsNumber() == 3);
}

BOOST_AUTO_TEST_CASE(TestLongDoubleClassConstructor)
{
    LongDouble a = "12.345", b = "-7.2345";
    LongDouble c(a), d(b, 2);

    BOOST_CHECK(c.GetDigits() == "12" && a.GetDecimals() == "345000" &&
                c.GetSign() && c.GetDecimalsNumber() == 6);
    BOOST_CHECK(d.GetDigits() == "7" && d.GetDecimals() == "23" &&
                !d.GetSign() && d.GetDecimalsNumber() == 2);
}

BOOST_AUTO_TEST_CASE(LongDoubleTestUnaryMinusOperator)
{
    LongDouble a("-123"), b(73);
    LongDouble c, d;
    c = -a;
    d = -b;

    BOOST_CHECK(c.GetDigits() == "123" && a.GetDecimals() == "000000" &&
                c.GetSign() && c.GetDecimalsNumber() == 6);
    BOOST_CHECK(d.GetDigits() == "73" && d.GetDecimals() == "000000" &&
                !d.GetSign() && d.GetDecimalsNumber() == 6);
}

BOOST_AUTO_TEST_CASE(TestLongDoubleCastToBool)
{
    LongDouble a = 0, b = 5.23, c = 0.00023, d = 0.00000007;

    BOOST_CHECK(!(bool) a);
    BOOST_CHECK((bool) b);
    BOOST_CHECK((bool) c);
    BOOST_CHECK(!(bool) d);
}

BOOST_AUTO_TEST_CASE(LongDoubleTestNotOperator)
{
    LongDouble a = 0, b = 5.23, c = 0.00023, d = 0.00000007;

    BOOST_CHECK(!a);
    BOOST_CHECK(!(!b));
    BOOST_CHECK(!(!c));
    BOOST_CHECK(!d);
}

