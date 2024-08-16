#include <stdio.h>

// The quantities LOWER, UPPER and STEP are symbolic constants
#define LOWER 0    // lower limit of table
#define UPPER 300  // upper limit
#define STEP 20    // step size

/*
 * print Fahrenheit-Celsius table
 * for fahrenheit = 300, 280, ..., 0 floating-point
 */
int main(void) {
    int fahr;

    // Print the heading
    printf("Fahrenheit  Celsius\n");
    printf("-------------------\n");
    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

    return 0;
}
