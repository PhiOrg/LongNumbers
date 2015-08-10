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

