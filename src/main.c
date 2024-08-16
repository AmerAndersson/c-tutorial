#include <stdbool.h>
#include <stdio.h>

/**
 * - Defined using Data types:
 *
 * char, int, short, long or long long.
 *
 * unsigned char, unsigned int,
 * unsigned short,
 * unsigned long,
 * unsigned long long.
 *
 * Unsigned integers - whole numbers which can only be positive.
 *
 * - Defined using:
 *
 * float and double.
 * Floating point numbers - real numbers (numbers with fractions).
 *
 * A char can range only from -128 to 127,
 * A long can range from -2,147,483,648 to 2,147,483,647
 *
 * (long and other numeric data types may have another range on different computers,
 * for example: - from
 * –9,223,372,036,854,775,808 to
 * 9,223,372,036,854,775,807 on 64-bit computer).
 *
 * - Structures
 */

int main(void) {
    // Booleans represent values that are either true or false.
    bool isProgrammingFun = true;
    bool isFishTasty = false;
    printf("Returns (true) = %d\n", isProgrammingFun);  // Returns 1 (true)
    printf("Returns (false) = %d\n", isFishTasty);      // Returns 0 (false)

    bool isHamburgerTasty = true;
    bool isPizzaTasty = true;
    printf("Returns (true) = %d\n", isHamburgerTasty == isPizzaTasty);  // Returns 1 (true)

    int a = 3;
    float b = 4.5;
    double c = 5.25;
    float sum = (a + b + c);
    /* prints the sum */
    printf("The sum of a, b, and c is %.3f\n", sum);
    return 0;
}