// C program to print Integer data types.
#include <stdio.h>

int main(void) {
    // Integer value with positive data.
    int a = 9;

    // integer value with negative data.
    int b = -9;

    // U or u is Used for Unsigned int in C.
    int c = 89U;

    // L or l is used for long int in C.
    long int d = 99998l;

    printf("Integer value with positive data: %d\n", a);
    printf("Integer value with negative data: %d\n", b);
    printf("Integer value with an unsigned int data: %u\n", c);
    printf("Integer value with an long int data: %ld\n", d);
    printf("\n");

    // C program to print Integer data types
    char as = 'a';
    char cs;

    printf("Value of a: %c\n", as);

    as++;
    printf("Value of a after increment is: %c\n", as);

    // c is assigned ASCII values
    // which corresponds to the
    // character 'c'
    // a-->97 b-->98 c-->99
    // here c will be printed
    cs = 99;

    printf("Value of c: %c\n", cs);
    printf("\n");

    // C Program to demonstrate use
    // of Floating types
    float f1 = 9.0f;
    float f2 = 2.5f;

    // 2x10^-4
    float f3 = 2E-4f;
    float f4 = 2E4f;
    printf("%f\n", f1);
    printf("%f\n", f2);
    printf("%f\n", f3);
    printf("%f\n", f4);
    printf("\n");

    // C Program to demonstrate
    // use of double data type
    double d1 = 123123123.00;
    double d2 = 12.293123;
    double d3 = 2312312312.123123;

    printf("%lf\n", d1);
    printf("%lf\n", d2);
    printf("%lf\n", d3);
    printf("\n");

    // C Program to print size of
    // different data type in C
    int size_of_int = sizeof(int);
    int size_of_char = sizeof(char);
    int size_of_float = sizeof(float);
    int size_of_double = sizeof(double);

    printf("The size of int data type : %d\n", size_of_int);
    printf("The size of char data type : %d\n",
           size_of_char);
    printf("The size of float data type : %d\n",
           size_of_float);
    printf("The size of double data type : %d\n",
           size_of_double);
    printf("\n");

    return 0;
}
