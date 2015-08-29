# LongNumber
LongNumber is a library for operations with long numbers.



How works LongDouble constructors?
------

The constructors which receives as parameter float, double, long double, int,
long, long long, unsigned int, unsigned long, unsigned long long or LongInteger
creates a LongDouble with 6 decimals.

The constructors which receives as paramter char or std::string creates a
LongDouble with the decimals number on which has them the number from the
std::string if the number from std::string has at least 6 decimals. If the
number from the std::string has less than 6 decimals then will be added zeros
at the end of the number such that the number to have 6 decimals. If the
std::string doesn't represints a valid number then the LongDouble will have
the 0.000000 value.

The constructor which receives LongDouble as paramter creates a new LongDouble
with same value.



How works operations(+, -, \*, /) with the LongDouble numbers?
------

The result of each operation(+, -, \*, /) is calculated with the greater decimals
number between the decimals number of the first number and the second number.

E.g.:
2.343000 + 3.5123000000 = 5.8553000000

5.000000 - 1.0000000000 = 4.0000000000

0.100000 * 1.000000 = 0.100000

5.000000 / 2.000000 = 2.500000



How rounding is made?
------

If the number should have 6 decimals then seventh decimal is checked. If seventh
decimal is >= 5 then the number is rounded by addition, otherwise by absence.



How works opeartor\* for LongDouble?
------

The LongDouble numbers are multiplied with 10^(decimals number) and the numbers
are multiplied as LongInteger and the result is multiplied with 1/10^(decimals
number of the first number + decimals number of the second number).

E.g.:
5.200000 * 2.000000 = (5.200000 * 10 ^ 6 * 2.000000 * 10 ^ 6) / 10 ^ 12
= (5200000 * 2000000) / 1000000000000 = 10400000000000 / 1000000000000
= 10.400000000000

The result has (decimals number of the first number + decimals number of the
second number) decimals, but in the end the result will have the greater
decimals number between the decimals number of the first number and the second
number. So, it can make the rounding in safe.



How works operator/ for LongDouble?
------

The LongDouble number are multiplied with 10^(the greater number between the
decimals number of the first number and the second number) and then the
numbers are divided. If the result should have 6 decimals then the result
will be calculated with 7 decimals and according to the seventh decimal is
rounded the result.



How works SetPrecision()?
------

The precision of a LongDouble number cannot be less than 6 decimals.
When you set a precision greater than the current precision will be added
zeros at the end of the decimal part. If the precision on which you want to set
is less than the current precision then the number will be rounded.

Remeber that a number cannot have less of 6 decimals.



HINT
===
If you need precision of six decimals, I recommend you to set the
precision at 9-11 decimals. In other words, I recommend you to add with 3-5
decimals more.
