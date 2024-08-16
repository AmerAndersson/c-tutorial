
// The temperature conversion program to use a function for conversion.
#include <stdio.h>

// The quantities LOWER, UPPER and STEP are symbolic constants
#define LOWER 0    // lower limit of table
#define UPPER 300  // upper limit
#define STEP 20    // step size

// Function prototype
float fahrenheitToCelsius(float fahrenheit);

int main(void) {
    float fahr, celsius;

    fahr = LOWER;
    printf("Fahrenheit to Celsius conversion table\n");
    printf("--------------------------------------\n");
    while (fahr <= UPPER) {
        celsius = fahrenheitToCelsius(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }

    return 0;
}

// Function definition
float fahrenheitToCelsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}
