#include <stdio.h>

// The quantities LOWER, UPPER and STEP are symbolic constants
#define LOWER 0    // lower limit of table
#define UPPER 300  // upper limit
#define STEP 20    // step size

/*
 * print Celsius-Fahrenheit table
 * for Celsius = 0, 20, ..., 300 floating-point
 */
int main(void) {
    float celsius, fahr;

    celsius = LOWER;
    // Print the heading
    printf("Celsius  Fahrenheit\n");
    printf("-------------------\n");

    while (celsius <= UPPER) {
        fahr = (celsius * 9.0 / 5.0) + 32.0;
        // %3.0f (celsius) prints at least three characters wide,
        // with no decimal point and no fraction digits.
        // %6.1f (fahr) prints at least six characters wide,
        // with 1 digit after the decimal point
        printf("%3.0f   %6.1f\n", celsius, fahr);
        celsius = celsius + STEP;
    }
    return 0;
}
