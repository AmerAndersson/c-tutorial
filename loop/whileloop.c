/*
 * For loops in C are straightforward.
 * They supply the ability to create a loop - a code block that runs multiple times.
 * For loops require an iterator variable, usually notated as i.
 *
 *
 * While loops are similar to for loops, but have less functionality.
 * A while loop continues executing the while block as long as the condition
 * in the while remains true.
 *
 */
#include <stdio.h>

int main(void) {
    /*
     * A while loop continues executing the while block as long
     * as the condition in the while remains true. For example,
     * the following code will execute exactly ten times:
     */

    // initializes the sum variable to 0
    int n = 0;

    while (n < 10) {
        printf("[n] %d\n", n);
        n++;
    }
    printf("\n");

    /*
    * There are two important loop directives that are used
    * in conjunction with all loop types in C - the break and continue directives.

    * The break directive halts a loop after ten loops,
    * even though the while loop never finishes:
    */
    // initializes the m variable to 0
    int m = 0;
    while (1) {
        m++;
        if (m == 10) {
            break;
        }
        printf("[m] %d\n", m);
    }
    printf("\n");

    // The code, the continue directive causes the printf command to be skipped,
    // so that only even numbers are printed out:

    // initializes the i variable to 0
    int i = 0;
    while (i < 20) {
        i++;

        // check that i is odd
        if (i % 2 == 1) {
            // go back to the start of the while block
            continue;
        }

        // we reach this code only if i is even
        printf("The number [i] %d is even.\n", i);
    }
    printf("\n");

    // initializes the v variable to 0
    int v = 0;
    while (v < 20) {
        v++;
        // check that i is even
        if (v % 2 == 0) {
            // go back to the start of the while block
            continue;
        }
        // we reach this code only if i is odd
        printf("The number [i] %d is odd.\n", v);
    }
    printf("\n");

    /*
     * The array variable consists of a sequence of ten numbers. Inside the while loop, you must write two if conditions, which change the flow of the loop in the following manner (without changing the printf command):

    If the current number which is about to printed is less than 5, don't print it.
    If the current number which is about to printed is greater than 10, don't print it and stop the loop.
    Notice that if you do not advance the iterator variable i and use the continue derivative, you will get stuck in an infinite loop

    * First if condition:
    * if (array[i] < 5): This condition checks if the current element is less than 5
    * If true, it increments i and uses continue to skip the rest of the loop body
    * (including the printf statement) for the current iteration.

    *  Second if condition:
    *  if (array[i] > 10): This condition checks if the current element is greater than 10.
    *  If true, it breaks out of the loop, stopping any further iterations.
    *
    * If neither condition is met, the current element is printed,
    * and i is incremented normally.
    *
    * This ensures that numbers less than 5 are not printed, and
    * numbers greater than 10 stop the loop, and all other numbers are printed correctly
    */

    int arrays[] = {1, 7, 4, 5, 9, 3, 5, 11, 6, 3, 4};
    int s = 0;  // initializes the i variable to 0

    // Get the length of the array
    int length = sizeof(arrays) / sizeof(int);

    while (s < length) {
        if (arrays[s] < 5) {
            s++;
            continue;
        }
        if (arrays[s] > 10) {
            break;
        }
        // Increment and Print:
        printf("[s] %d\n", arrays[s]);
        s++;
    }

    return 0;
}
