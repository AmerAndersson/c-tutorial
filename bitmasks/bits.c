/**
 * Bitmasks
 * Bit masking is simply the process of storing data truly as bits,
 * as opposed to storing it as chars/ints/floats.
 * It is incredibly useful for storing certain types of data compactly and efficiently.

 * The idea for bit masking is based on boolean logic.
 * For those not familiar, boolean logic is the manipulation of 'true'
 * (1) and 'false' (0) through logical operations (that take 0s and 1s as their argument).
 *  We are concerned with the following operations:

 * NOT a - the final value is the opposite of the input value (1 -> 0, 0 -> 1)
 * a AND b - if both values are 1, the final value is 1, otherwise the final value is 0
 * a OR b - if either value is 1, the final value is 1, otherwise the final value is 0
 * a XOR b - if one value is 1 and the other value is 0, the final value is 1,
 * otherwise the final value is 0
 *
 * In computing, one of these true/false values is a bit.
 * Primitives in C (int, char, float, double, and pointers)
 * are made up of some number of bits, where that number is a multiple of 8.
 * For example, an int may be at least 16 bits in size,
 * where a char may be 8 bits. 8 bits is typically referred to as a byte.
 * C guarantees that certain primitives are at least some number of bytes in size.
 * The introduction of stdint.h in C11 allows the programmer to specify integer types
 * that are exactly some number of bytes, which is extremely useful when using masks.
 * ------------------------------------------------
 *  the binary representation of the decimal number 9. and 36
 * 9 = 0000 1001 and 36 = 0010 0100:
 * The program declares an integer x with the value 9.
 * It performs a bitwise left shift on x by 2 positions, resulting in the value 36.
 * It then prints the result (36) to the console.
 */
#include <stdio.h>
#include <stdlib.h>  //for qsort()

int main(void) {
    /*
     * r is assigned the result of the operation x << 2.
     * x << 2 is a bitwise left shift operation.
     * This operation shifts the bits of x (which is 9 or 0000 1001 in binary)
     * to the left by 2 positions.
     *
     * r is assigned the result of the operation x >> 2.
     * x >> 2 is a bitwise right shift operation.
     * This operation shifts the bits of x (which is 9 or 0000 1001 in binary)
     * to the right by 2 positions.
     */

    /*
     * 9 =     00001001
     * 24 =    00011000
     *
     * X << 2 = 36
     * X << 1 = 18
     * X >> 2 = 4
     * X >> 1 = 2
     *
     * ~x = -10
     * x & y = 00001000 = 8
     * x | y = 00011001 = 25
     * x ^ y = 00011001 = 17
     */
    unsigned int x = 9;   // 00001001
    unsigned int y = 24;  // 00011000

    unsigned int shift_by_two = x << 2;
    unsigned int shift_by_one = x << 1;

    puts("Bitwise left shift operation:");
    printf("X << 2 : %u\n", shift_by_two);
    printf("X << 1 : %u\n", shift_by_one);

    puts("=============================");
    printf("\n");

    unsigned int shift_by_two_r = x >> 2;
    unsigned int shift_by_one_r = x >> 1;

    puts("Bitwise right shift operation:");
    printf("X >> 2 : %u\n", shift_by_two_r);
    printf("X >> 1 : %u\n", shift_by_one_r);

    puts("=============================");
    printf("\n");

    /*
     * The bitwise NOT operator (~) inverts all the bits of the given number.
     * Each 1 in the binary representation of the number becomes 0, and each 0 becomes 1
     *
     *
     * NOT a - the final value is the opposite of the input value (1 -> 0, 0 -> 1)
     * a AND b - if both values are 1, the final value is 1, otherwise the final value is 0
     * a OR b - if either value is 1, the final value is 1, otherwise the final value is 0
     * a XOR b - if one value is 1 and the other value is 0, the final value is 1,
     * otherwise the final value is 0
     */

    // NOT operation
    unsigned int not_x = ~x;
    // AND operation
    unsigned int and_x = x & y;
    // OR operation
    unsigned int or_x = x | y;

    // XOR operation
    unsigned int xor_x = x ^ y;

    // Print results

    puts("Bitwise (NOT,AND, OR,XOR) operation:");
    printf("NOT ~X : %u\n", not_x);
    printf("X & Y : %u\n", and_x);  // 00001000 = 8
    printf("X | Y : %u\n", or_x);   // 00011001 = 25
    printf("XOR : %u\n", xor_x);

    puts("=============================");
    printf("\n");

    /*
     * The 2's complement process converts a positive number
     * to its negative equivalent in binary.
     * In C, when you use negative integers, they are stored in memory
     * using the 2's complement form.
     * Example `00010100` becomes `11101100` when you apply the 2's complement
     * process, which corresponds to `-20` in a signed 8-bit integer.
     * The binary representation of `x = 20` is `00010100`.
     * The binary representation of `y = -20` will be `11101100`
     *
     * 8 says that you want to show 8 digits
     * 0 that you want to prefix with 0's instead of just blank spaces
     * x that you want to print in lower-case hexadecimal.
     */
    puts("2's complement process converts a positive number:");
    int xs = 20;
    int ys = -xs;

    printf("xs: %d\n", xs);
    printf("ys: %d\n", ys);
    printf("\n");

    printf("xs-x: %x\n", xs);  // just print xs
    printf("ys-x: %x\n", ys);  // just print ys
    printf("\n");

    printf("xs-0x: %0x\n", xs);  // just print xs ('0' on its own has no effect)
    printf("ys-0x: %0x\n", ys);  // just print ys ('0' on its own has no effect)
    printf("\n");

    printf("Binary of xs: %08x\n", xs);  // print in 8 width and pad with 0's
    printf("Binary of ys: %08x\n", ys);  // print in 8 width and pad with 0's
    printf("\n");

    int data = 29;
    printf("%x\n", data);    // just print data
    printf("%0x\n", data);   // just print data ('0' on its own has no effect)
    printf("%8x\n", data);   // print in 8 width and pad with blank spaces
    printf("%08x\n", data);  // print in 8 width and pad with 0's

    puts("=============================");
    printf("\n");

    unsigned int a = 5;  // Example value (0101 in binary)
    unsigned int b = 3;  // Example value (0011 in binary)

    // NOT operation
    unsigned int not_a = ~a;  // bitwise NOT of a (inverts all bits)

    // AND operation
    unsigned int and_ab = a & b;  // bitwise AND of a and b

    // OR operation
    unsigned int or_ab = a | b;  // bitwise OR of a and b

    // XOR operation
    unsigned int xor_ab = a ^ b;  // bitwise XOR of a and b

    // Print results
    printf("a = %u\n", a);
    printf("b = %u\n", b);
    printf("NOT a = %u\n", not_a);
    printf("a AND b = %u\n", and_ab);
    printf("a OR b = %u\n", or_ab);
    printf("a XOR b = %u\n", xor_ab);

    /**
     *
    * NOT a (~a): This inverts all bits of a. For example, if a is 5 (binary 0101), NOT a will be
    * 11111111 11111111 11111111 11111010 in a 32-bit system, which is the two's complement of 5.
    * a AND b (a & b): This operation compares each bit of a and b.
    * If both bits are 1, the result bit is 1. Otherwise, it is 0.
    * For example, 5 & 3 results in 1 (binary 0001).

    * a OR b (a | b): This operation compares each bit of a and b.
    * If at least one bit is 1, the result bit is 1. Otherwise, t is 0.
    * For example, 5 | 3 results in 7 (binary 0111).

    * a XOR b (a ^ b): This operation compares each bit of a and b.
    * If one bit is 1 and the other is 0, the result bit is 1. Otherwise, it is 0.
    * For example, 5 ^ 3 results in 6 (binary 0110).
    *
    * Note: The result of NOT a might seem large because ~ inverts all 32 bits on most systems,
    * and 5 in binary is 00000000000000000000000000000101,
    * so the inverted result is 11111111111111111111111111111010,
    * which is the unsigned integer equivalent of 4294967290.
     */

    return 0;
}
