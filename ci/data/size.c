#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Get the Memory Size sizeof(), get the size (in bytes)
  // The memory size refers to how much space a type occupies in the computer's memory.
  int myInt;
  float myFloat;
  double myDouble;
  char myChar;

  printf("size of int: %lu bytes\n", sizeof(myInt));
  printf("size of float: %lu bytes\n", sizeof(myFloat));
  printf("size of double: %lu bytes\n", sizeof(myDouble));
  printf("size of char: %lu byte\n", sizeof(myChar));
  printf("\n");

  printf("CHAR_BIT    :   %d\n", CHAR_BIT);
  printf("CHAR_MAX    :   %d\n", CHAR_MAX);
  printf("CHAR_MIN    :   %d\n", CHAR_MIN);
  printf("\n");

  printf("INT_MAX     :   %d\n", INT_MAX);
  printf("INT_MIN     :   %d\n", INT_MIN);
  printf("\n");

  printf("LONG_MAX    :   %ld\n", (long)LONG_MAX);
  printf("LONG_MIN    :   %ld\n", (long)LONG_MIN);
  printf("\n");

  printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
  printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
  printf("\n");

  printf("SHRT_MAX    :   %d\n", SHRT_MAX);
  printf("SHRT_MIN    :   %d\n", SHRT_MIN);
  printf("\n");

  printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
  printf("\n");

  printf("UINT_MAX    :   %u\n", (unsigned int)UINT_MAX);
  printf("USHRT_MAX   :   %d\n", (signed short)SHRT_MAX);
  printf("USHRT_MIN   :   %d\n", (signed short)SHRT_MIN);
  printf("\n");

  printf("ULONG_MAX   :   %lu\n", (unsigned long)ULONG_MAX);
  printf("USHRT_MAX   :   %d\n", (unsigned short)USHRT_MAX);
  printf("\n");

  printf("The number of bits in a byte %d\n", CHAR_BIT);

  printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
  printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
  printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

  printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
  printf("The maximum value of SHORT INT = %d\n", SHRT_MAX);

  printf("The minimum value of INT = %d\n", INT_MIN);
  printf("The maximum value of INT = %d\n", INT_MAX);

  printf("The minimum value of CHAR = %d\n", CHAR_MIN);
  printf("The maximum value of CHAR = %d\n", CHAR_MAX);

  printf("The minimum value of LONG = %ld\n", LONG_MIN);
  printf("The maximum value of LONG = %ld\n", LONG_MAX);

  printf("\n");

  short a;
  long b;
  long long c;
  long double d;

  char ch;
  float f;
  double ds;
  short int si;
  unsigned int ui;
  long int li;
  long long int lli;
  unsigned long int uli;
  unsigned long long int ulli;
  signed char sc;
  unsigned char uc;
  printf("size of short: %lu bytes\n", sizeof(a));
  printf("\n");

  printf("size of long: %lu bytes\n", sizeof(b));
  printf("size of long long: %lu bytes\n", sizeof(c));
  printf("size of long double: %lu bytes\n", sizeof(d));
  printf("\n");

  printf("size of char: %lu byte\n", sizeof(ch));
  printf("\n");

  printf("size of float: %lu bytes\n", sizeof(f));
  printf("size of double:  %lu bytes\n", sizeof(ds));
  printf("\n");

  printf("size of short int: %lu bytes\n", sizeof(si));
  printf("\n");

  printf("size of unsigned int: %lu bytes\n", sizeof(ui));
  printf("\n");

  printf("size of long int: %lu bytes\n", sizeof(li));
  printf("size of long long int:  %lu bytes\n", sizeof(lli));
  printf("size of unsigned long int: %lu bytes\n", sizeof(uli));
  printf("\n");

  printf("size of unsigned long long int: %lu bytes\n", sizeof(ulli));
  printf("size of signed char: %lu byte\n", sizeof(sc));
  printf("size of unsigned char int:  %lu byte\n", sizeof(uc));
  printf("\n");

  /**
   When sizeof() is used with the data types, it simply returns the amount of memory allocated to that data type. The output can be different on different machines like a 32−bit system can show different output while a 64−bit system can show different of the same data types.
  */

  int as = 16;

  printf("Size of variable a : %lu\n", sizeof(as));
  printf("Size of int data type : %lu\n", sizeof(int));
  printf("Size of char data type : %lu\n", sizeof(char));
  printf("Size of float data type : %lu\n", sizeof(float));
  printf("Size of double data type : %lu\n", sizeof(double));
  printf("\n");

  // signed - allows for storage of both positive and negative numbers
  // unsigned - allows for storage of only positive numbers
  //  valid codes
  unsigned int o = 35;
  int m = -35;  // signed int
  int z = 36;   // signed int

  // invalid code: unsigned int cannot hold negative integers
  // unsigned int num = -35;

  printf("unsigned int %d\n", o);
  printf("signed int %d\n", m);
  printf("signed int %d\n", z);
  printf("\n");

  int x = 4 * 1024;
  x = x * 1024 * 1024;

  if (x > 0)
    printf("True\n");
  else
    printf("False\n");

  // So expression becomes, if(sizeof(int) > -1 ) ==> if(2 > 0xFFFF)
  // Printed false.
  if (sizeof(int) > -1)
    printf("True\n");
  else
    printf("False\n");

  // I suggest to try if((int)sizeof(int) > -1 ) for proper result.
  if ((int)sizeof(int) > -1) {
    printf("True\n");
  } else {
    printf("False.\n");
  }

  return 0;
}
