#include "../src/LongNumber.h"

#define BOOST_TEST_MODULE LongDoubleTest
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace LongNumber;

BOOST_AUTO_TEST_CASE(TestLongDoubleConstructor)
{
    LongDouble a(3.17), b(-1923.34646), c(56.123456789);

    BOOST_CHECK(a.GetDigits() == "3" && a.GetDecimals() == "170000" &&
                a.GetSign() && a.GetDecimalsNumber() == 6);
    BOOST_CHECK(b.GetDigits() == "1923" && b.GetDecimals() == "346460" &&
                !b.GetSign() && b.GetDecimalsNumber() == 6);
    BOOST_CHECK(c.GetDigits() == "56" && c.GetDecimals() == "123457" &&
                c.GetSign() && c.GetDecimalsNumber() == 6);
}

BOOST_AUTO_TEST_CASE(TestLongIntegerConstructor)
{
    LongInteger a = 17, b = -32;
    LongDouble c(a), d(b);

    BOOST_CHECK(c.GetDigits() == "17" && c.GetDecimals() == "000000" &&
                c.GetSign() && c.GetDecimalsNumber() == 6);
    BOOST_CHECK(d.GetDigits() == "32" && d.GetDecimals() == "000000" &&
                !d.GetSign() && d.GetDecimalsNumber() == 6);
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
    LongDouble a("123"), b("-17"), c("0"), d("0.23"), e("-12934643324.1234");
    LongDouble f("12+.-123"), g("asd"), h("12..79"), i("-123.45a"), j("a");

    BOOST_CHECK(a.GetDigits() == "123" && a.GetDecimals() == "000000" &&
                a.GetSign() && a.GetDecimalsNumber() == 6);
    BOOST_CHECK(b.GetDigits() == "17" && b.GetDecimals() == "000000" &&
                !b.GetSign() && b.GetDecimalsNumber() == 6);
    BOOST_CHECK(c.GetDigits() == "0" && a.GetDecimals() == "000000" &&
                c.GetSign() && c.GetDecimalsNumber() == 6);
    BOOST_CHECK(d.GetDigits() == "0" && d.GetDecimals() == "230000" &&
                d.GetSign() && d.GetDecimalsNumber() == 6);
    BOOST_CHECK(e.GetDigits() == "12934643324" && e.GetDecimals() == "123400" &&
                !e.GetSign() && e.GetDecimalsNumber() == 6);
    BOOST_CHECK(f.GetDigits() == "0" && f.GetDecimals() == "000000" &&
                f.GetSign() && f.GetDecimalsNumber() == 6);
    BOOST_CHECK(g.GetDigits() == "0" && g.GetDecimals() == "000000" &&
                g.GetSign() && g.GetDecimalsNumber() == 6);
    BOOST_CHECK(h.GetDigits() == "0" && h.GetDecimals() == "000000" &&
                h.GetSign() && h.GetDecimalsNumber() == 6);
    BOOST_CHECK(i.GetDigits() == "0" && i.GetDecimals() == "000000" &&
                i.GetSign() && i.GetDecimalsNumber() == 6);
    BOOST_CHECK(j.GetDigits() == "0" && j.GetDecimals() == "000000" &&
                j.GetSign() && j.GetDecimalsNumber() == 6);
}

BOOST_AUTO_TEST_CASE(TestLongDoubleClassConstructor)
{
    LongDouble a = "12.345", b = "-7.2345";
    LongDouble c(a), d(b);

    BOOST_CHECK(c.GetDigits() == "12" && a.GetDecimals() == "345000" &&
                c.GetSign() && c.GetDecimalsNumber() == 6);
    BOOST_CHECK(d.GetDigits() == "7" && d.GetDecimals() == "234500" &&
                !d.GetSign() && d.GetDecimalsNumber() == 6);
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

BOOST_AUTO_TEST_CASE(LongDoubleTestEqualOperator)
{
    LongDouble a = 5, b = 4, c = -5, d = 12, e = 5, f = 17, g = 17, h = -17;
    LongDouble i = 2.73, j(2.73), k = 2.72, l("2.73000010");

    BOOST_CHECK(!(a == b));
    BOOST_CHECK(a == a);
    BOOST_CHECK(a == e);
    BOOST_CHECK(a == 5);
    BOOST_CHECK(!(a == c));
    BOOST_CHECK(!(a == d));
    BOOST_CHECK(a == -c);
    BOOST_CHECK(!(d == e));
    BOOST_CHECK(!(d == 11));
    BOOST_CHECK(!(d == f));
    BOOST_CHECK(!(g == h));
    BOOST_CHECK(f == f);
    BOOST_CHECK(!(i == k));
    BOOST_CHECK(i == j);
    BOOST_CHECK(!(i == l));
}

BOOST_AUTO_TEST_CASE(LongDoubleTestGreaterOperator)
{
    LongDouble a = 2.73, b = "2.7300000001", c = "2.7300000000", d = 2.754;
    LongDouble e = 3.14, f = -13.24;

    BOOST_CHECK(!(a > b));
    BOOST_CHECK(!(a > c));
    BOOST_CHECK(b > c);
    BOOST_CHECK(d > b);
    BOOST_CHECK(d > a);
    BOOST_CHECK(d > c);
    BOOST_CHECK(b > a);
    BOOST_CHECK(a > -b);
    BOOST_CHECK(a > f);
    BOOST_CHECK(!(a > e));
    BOOST_CHECK(e > a);
    BOOST_CHECK(e > d);
    BOOST_CHECK(!(a > a));
}

BOOST_AUTO_TEST_CASE(LongDoubleTestLessOperator)
{
    LongDouble a = 2.73, b = "2.7300000001", c = "2.7300000000", d = 2.754;
    LongDouble e = 3.14, f = -13.24;

    BOOST_CHECK(a < b);
    BOOST_CHECK(!(a < c));
    BOOST_CHECK(!(b < c));
    BOOST_CHECK(b < d);
    BOOST_CHECK(!(b < c));
    BOOST_CHECK(c < b);
    BOOST_CHECK(-b < a);
    BOOST_CHECK(f < a);
    BOOST_CHECK(!(e < a));
    BOOST_CHECK(a < e);
    BOOST_CHECK(d < e);
    BOOST_CHECK(!(a < a));
}

BOOST_AUTO_TEST_CASE(LongDoubleTestGreatesOrEqualOperator)
{
    LongDouble a = 2.73, b = "2.7300000001", c = "2.7300000000", d = 2.754;
    LongDouble e = 3.14, f = -13.24;

    BOOST_CHECK(!(a >= b));
    BOOST_CHECK(b >= a);
    BOOST_CHECK(b >= b);
    BOOST_CHECK(b >= c);
    BOOST_CHECK(a >= c);
    BOOST_CHECK(c >= a);
    BOOST_CHECK(!(c >= d));
    BOOST_CHECK(e >= f);
    BOOST_CHECK(-f >= e);
    BOOST_CHECK(e >= a);
    BOOST_CHECK(d >= c);
    BOOST_CHECK(d >= b);
}

BOOST_AUTO_TEST_CASE(LongDoubleTestLessOrEqualOperator)
{
    LongDouble a = 2.73, b = "2.7300000001", c = "2.7300000000", d = 2.754;
    LongDouble e = 3.14, f = -13.24;

    BOOST_CHECK(a <= b);
    BOOST_CHECK(!(b <= a));
    BOOST_CHECK(b <= b);
    BOOST_CHECK(!(b <= c));
    BOOST_CHECK(c <= a);
    BOOST_CHECK(a <= c);
    BOOST_CHECK(c <= d);
    BOOST_CHECK(!(e <= f));
    BOOST_CHECK(e <= -f);
    BOOST_CHECK(a <= e);
    BOOST_CHECK(c <= d);
    BOOST_CHECK(b <= d);
}

BOOST_AUTO_TEST_CASE(LongDoubleTestAdditionOperator)
{
    LongDouble a = "387562935723657235623756234.268765237652375627356";
    LongDouble b = "89325892365823561231283.23856235327657236572357236573";
    LongDouble c = "2.99", d = "0.01", e = "0.001", f = "7", g = "7.01";
    LongDouble h = "7.001", i = "12.30", j = "7.32", k = "2.17", l = 1.29;
    LongDouble m = "3.79";

    BOOST_CHECK(a + b ==
                "387652261616023059184987517.50732759092894799307957236573");
    BOOST_CHECK(c + d == 3);
    BOOST_CHECK(c + 0.7 == 3.69);
    BOOST_CHECK(c + e == "2.991");
    BOOST_CHECK(c + f == 9.99);
    BOOST_CHECK(c + g == 10);
    BOOST_CHECK(c + h == "9.991");
    BOOST_CHECK(d + h == "7.011");
    BOOST_CHECK(h + e == "7.002");
    BOOST_CHECK(g + h == "14.011");
    BOOST_CHECK(i + j == "19.62");
    BOOST_CHECK(j + m == "11.11");
    BOOST_CHECK(k + m == 5.96);
    BOOST_CHECK(m + l == 5.08);
    BOOST_CHECK(h + -e == 7);
    BOOST_CHECK(-h + e == -7);
    BOOST_CHECK(k + -l == 0.88);
    BOOST_CHECK(i + -j == 4.98);
    BOOST_CHECK(-i + j == "-4.98");
    BOOST_CHECK(j + -k == "5.15");
    BOOST_CHECK(i + -l == "11.01");
    BOOST_CHECK(i + -k == "10.13");
    BOOST_CHECK(i + -m == "8.51");
}

