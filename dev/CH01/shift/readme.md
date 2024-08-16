# Applications of Right Shift Operators


Division by Powers of Two: Right shifting a number by n positions is equivalent to dividing it by 2^n and it is very fast.
Efficient Calculations: Used in performance-critical applications for fast division operations.
Bit Manipulation: Useful in extracting specific bits from data, common in data compression and cryptography.

```c
## Important Points of Shift Operators

1. The left-shift and right-shift operators should not be used for negative numbers. The result of is undefined behavior if any of the operands is a negative number. For example, results of both 1 >> -1 and 1 << -1 is undefined
// C program to show behaviour of shift operators for
// negative values
#include <stdio.h>

// left shift for negative value
printf("2 << -5 = %d\n", (2 << -5));

// right shift for negative value
printf("2 >> -5 = %d", (2 >> -5));

2. If the number is shifted more than the size of the integer, the behavior is undefined. For example, 1 << 33 is undefined if integers are stored using 32 bits. For bit shift of larger values 1ULL<<62  ULL is used for Unsigned Long Long which is defined using 64 bits that can store large values.

// c program to demonstrate the behaviour of bitwise
// shift operators for large values
#include <stdio.h>
int N = 3;

// left shift of 65 digits
printf("3 << 65 = %d", (3 << 65));


3. The left-shift by 1 and right-shift by 1 are equivalent to the product of the first term and 2 to the power given element(1<<3 = 1*pow(2,3)) and division of the first term and second term raised to power 2 (1>>3 = 1/pow(2,3)) respectively.
// C program for the above approach

#include <math.h>
#include <stdio.h>
printf("2^5 using pow() function: %.0f\n", pow(2, 5));
printf("2^5 using left shift: %d\n", (1 << 5));
```