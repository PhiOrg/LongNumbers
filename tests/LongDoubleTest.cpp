#include "../src/LongNumber.h"

#define BOOST_TEST_MODULE LongDoubleTest
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(TestLongDoubleConstructor)
{
    LongDouble a(3.17), b(-1923.34646), c(56.123456789, 9);

    BOOST_CHECK(a.GetDigitsForTest() == "3" &&
                a.GetDecimalsForTest() == "170000" &&
                a.GetSignForTest() && a.GetDecimalsNumberForTest() == 6);
    BOOST_CHECK(b.GetDigitsForTest() == "1923" &&
                b.GetDecimalsForTest() == "346460" &&
                !b.GetSignForTest() && b.GetDecimalsNumberForTest() == 6);
    BOOST_CHECK(c.GetDigitsForTest() == "56" &&
                c.GetDecimalsForTest() == "123457000" &&
                c.GetSignForTest() && c.GetDecimalsNumberForTest() == 9);
}

