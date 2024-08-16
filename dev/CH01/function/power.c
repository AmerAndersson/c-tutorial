#include <stdio.h>

// Function prototype to calculate power
int power(int m, int n);
// Function prototype to calculate power
double powers(double base, int exp);

// Test power function
int main(void) {
    int i;

    for (i = 0; i < 10; ++i) {
        printf("[%d]:  %d  %d\n", i, power(2, i), power(-3, i));
    }
    printf("\n");

    double base;
    int exponent;

    // Test cases
    base = 2.0;
    exponent = 3;
    printf("%.2f^%d = %.2f\n", base, exponent, powers(base, exponent));

    base = 5.0;
    exponent = 4;
    printf("%.2f^%d = %.2f\n", base, exponent, powers(base, exponent));

    base = 2.0;
    exponent = 0;
    printf("%.2f^%d = %.2f\n", base, exponent, powers(base, exponent));

    base = 7.0;
    exponent = 2;
    printf("%.2f^%d = %.2f\n", base, exponent, powers(base, exponent));
    return 0;
}
// Function definition power: raise base to n-th power; n >= 0
// base = 2  n = 3
int power(int base, int n) {
    int i, p;
    p = 1;

    for (i = 1; i <= n; ++i) {
        p = p * base;
    }
    return p;
}

double powers(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
