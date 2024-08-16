/* The definition of the function hello */
#include "hello.h"

#include <stdio.h>

int add(int a, int b) { return a + b; }

int subtract(int a, int b) { return a - b; }

// Other function definitions

void square(double x) { printf("The square root of 2.0 is %f\n", x); }

void cubed(double x) { printf("Two cubed is %f\n", x); }

// This function prints the message “Hello, name!”
void hello(const char* name) {
    // using its argument as the value of name.
    printf("Hello, %s!\n", name);
}
