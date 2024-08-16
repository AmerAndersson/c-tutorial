// C Program to demonstrate use
// of left shift  operator
#include <stdio.h>

/*
MSb stands for most significant bit,
while LSb stands for least significant bit.

a is the integer value to be shifted.
b specifies how many positions to shift the bits.

Let’s take a=5; which is 101 in Binary Form.
Now, if “a is left-shifted by 2” i.e a=a<<2
then a will become a=a*(2^2).
Thus, a=5*(2^2)=20 which can be written as 10100.
*/
// Driver code
int main(void) {
    // a = 5(00000101), b = 9(00001001)
    unsigned char a = 5, b = 9;

    printf("Left-shifted  Operator:\n");
    // The result is 00001010
    printf("a<<1 = %d\n", (a << 1));

    // The result is 00010010
    printf("b<<1 = %d", (b << 1));
    printf("\n\n");

    /*
    C Program to demonstrate use of right-shift operator

    a is the integer value to be shifted.
    b specifies how many positions to shift the bits.
    let’s take a=5; which is 101 in Binary Form.

    Now, if “a is right-shifted by 2” i.e a=a>>2
    then a will become a=a/(2^2).
    Thus, a=a/(2^2)=1 which can be written as 01.
    */

    // a = 5(00000101), b = 9(00001001)
    unsigned char a1 = 5, b1 = 9;

    printf("Right-shifted Operator:\n");
    // The result is 00000010
    printf("a1>>1 = %d\n", (a1 >> 1));

    // The result is 00000100
    printf("b1>>1 = %d\n", (b1 >> 1));

    return 0;
}
