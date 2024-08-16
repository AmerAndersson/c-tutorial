/*
 * -W which warns about a selection of common programming errors,
 * such as functions which can return without a value
 * (also known as “falling off the end of the function body”)
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int foo(unsigned int x);
void f(const char *str);

int main(int argc, char *argv[]) {
    printf("\n");
    printf("---------------------------------\n");
    // Declare variable outside the for loop
    printf("Argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        // Print the last element of the array
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    printf("---------------------------------\n");
    printf("\n");

    printf("foo(0) = %d\n", foo(0));                                // Expected output: 0
    printf("foo(1) = %d\n", foo(1));                                // Expected output: 0
    printf("foo((unsigned int)-1) = %d\n", foo((unsigned int)-1));  // Expected output: 1
    printf("---------------------------------\n");
    printf("\n");

    double x = -3.14;
    double y = fabs(x); /* should be fabs(x) */
    printf("x = %g |x| = %g\n", x, y);

    printf("---------------------------------\n");
    f("hello World!");
    printf("---------------------------------\n");
    printf("\n");

    return 0;
}
int foo(unsigned int x) {
    if (x < (unsigned int)-1)
        return 0;
    else
        return 1;
}

void f(const char *str) { printf("%s\n", str); }
