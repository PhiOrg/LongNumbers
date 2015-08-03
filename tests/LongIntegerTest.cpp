#include "../src/LongNumber.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE LongIntegerTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(TestConstructorInt)
{
    int number = 5;
    LongInteger a(number);
    BOOST_CHECK(a.GetSignForTests() && a.GetDigitsForTests() == "5");

    number = -5;
    LongInteger b(number);
    BOOST_CHECK(!b.GetSignForTests() && b.GetDigitsForTests() == "5");
}

