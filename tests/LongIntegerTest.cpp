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

