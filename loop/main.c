/*
 * For loops in C are straightforward.
 * They supply the ability to create a loop - a code block that runs multiple times.
 * For loops require an iterator variable, usually notated as i.
 *
 * For loops give the following functionality:

 * - Initialize the iterator variable using an initial value
 * - Check if the iterator has reached its final value
 * - Increases the iterator
 */
#include <stdio.h>

int main(void) {
    // iterator variable i
    int i;

    // Loop through the numbers 0 through 9 (10 numbers in total):
    for (i = 0; i <= 10; i++) {
        printf("[i] %d\n", i);  // print the numbers 0 through 9 (10 numbers in total)
    }
    printf("\n");

    // if we would want to sum all the values of an array,
    //  we would use the iterator i as the array index:
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;  // initializes the sum variable to 0
    int r;        // iterator variable r

    // Get the length of the array
    int length = sizeof(array) / sizeof(int);

    // Loop through the elements of the array
    for (r = 0; r < length; r++) {
        sum += array[r];
    }
    // Print the sum, now contains a[0] + a[1] + ... + a[9]
    printf("Sum of the array is %d.\n", sum);

    // Calculate the factorial (multiplication of all items array[0] to array[9], inclusive),
    // of the variable array.
    int arrays[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // initializes the factorial variable to 1
    // because multiplying by 1 doesn't change the result.
    int factorial = 1;
    int f;  // iterator variable f

    // Get the length of the array
    int lengths = sizeof(arrays) / sizeof(int);

    // loops through each element of the array,
    // multiplying the factorial variable by the current array element.
    for (f = 0; f < lengths; f++) {
        factorial *= arrays[f];
    }
    // prints the calculated factorial of 10!
    printf("10! is %d.\n", factorial);

    return 0;
}
