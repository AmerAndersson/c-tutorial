#include <stdio.h>

int main(void) {
  // C Program to demonstrate use of bitwise operators

  // a = 5(00000101), b = 9(00001001)
  unsigned int a = 5, b = 9;

  // The result is 00000001
  printf("a = %u, b = %u\n", a, b);
  printf("a&b = %u\n", a & b);

  // The result is 00001101
  printf("a|b = %u\n", a | b);

  // The result is 00001100
  printf("a^b = %u\n", a ^ b);

  // The result is 11111010
  printf("~a = %u\n", a = ~a);

  // The result is 00010010
  printf("b<<1 = %u\n", b << 1);

  // The result is 00000100
  printf("b>>1 = %u\n", b >> 1);

  // program to demonstrate the use of left - shift and right-shift operators.
  int x = 19;
  printf("x << 1 = %d\n", x << 1);
  printf("x >> 1 = %d\n", x >> 1);

  // use bitwise & operator to find if the given number is even or odd.
  int x = 19;
  (x & 1) ? printf("Odd") : printf("Even");

  // C program to demonstrate the use of bitwise NOT operator.
  unsigned int c = 1;
  printf("Signed Result %d \n", ~c);
  printf("Unsigned Result %u \n", ~c);

  // C program to Demonstrate the difference between & and && operator
  int x = 2,
      y = 5;
  (x & y) ? printf("True ") : printf("False ");
  (x && y) ? printf("True ") : printf("False ");
  return 0;
}
