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

