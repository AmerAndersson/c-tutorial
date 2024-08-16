/*
 * Compiling a simple C program multiple source files
 * The classic program for the C language is Hello World.
 * Here is the source code for our version of the
 */
#include <math.h>
#include <stdio.h>

#include "hello.h"

int main(void) {
    printf("\n");
    const char name[] = "Hello, Amer!";
    printf("the string asm is %s\n", name);
    printf("\n");

    add(5, 2);
    subtract(10, 2);
    printf("\n");
    square(sqrt(2.0));
    /* pow is used to compute the cube of two (2 raised to the power of 3) */
    cubed(pow(2.0, 3.0));
    printf("\n");
    /* print a greeting to everyone */
    hello("everyone");
    printf("\n");
    return 0;
}
