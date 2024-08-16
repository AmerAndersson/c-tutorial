#include <stdio.h>

// The quantities LOWER, UPPER and STEP are symbolic constants
#define LOWER 0    // lower limit of table
#define UPPER 300  // upper limit
#define STEP 20    // step size

/*
 * print Fahrenheit-Celsius table
 * for fahrenheit = 0, 20, ..., 300 floating-point
 */
int main(void) {
    float fahr, celsius;

    fahr = LOWER;
    // Print the heading
    printf("Fahrenheit  Celsius\n");
    printf("-------------------\n");

    while (fahr <= UPPER) {
        // celsius = (5.0 / 9.0) * (fahr - 32.0);
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        // %3.0f (fahr) prints at least three characters wide,
        // with no decimal point and no fraction digits.
        // %6.1f (celsius) prints at least six characters wide,
        // with 1 digit after the decimal point
        printf("%3.0f  %6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }

    return 0;
}
