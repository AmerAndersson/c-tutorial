/*
 * Recursion occurs when a function contains within it a call to itself.
 * Recursion can result in very neat, elegant code that is intuitive to follow.
 * It can also result in a very large amount of memory being used if the recursion gets too deep.
 *
 *   - Common examples of where recursion is used :
 *
 * Walking recursive data structures such as linked lists, binary trees, etc.
 * Exploring possible scenarios in games such as chess
 * Recursion always consists of two main parts. A terminating case that indicates
 * when the recursion will finish and a call to itself that must make progress
 * towards the terminating case.
 * 
 * Recursive Breakdown
 * 
 * multiply(3, 5):
 * x is 3, which is greater than 1, so it returns 5 + multiply(2, 5).
 * multiply(2, 5):
 * x is 2, which is greater than 1, so it returns 5 + multiply(1, 5).
 * multiply(1, 5):
 * x is 1, so it returns 5.
 * Now, putting it all together:
 * 
 * multiply(1, 5) returns 5.
 * multiply(2, 5) returns 5 + 5 which is 10.
 * multiply(3, 5) returns 5 + 10 which is 15.
 * Thus, multiply(3, 5) evaluates to 15.
 */

#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y);

/* 
* Function prototype
* Define the factorial function
* Checks if n is 0. If it is, returns 1 (base case).
* Otherwise, returns n * factorial(n - 1), 
* which recursively calls the factorial function with n - 1.
*/
int factorial(int n);

int main(void) {
    /* This function will perform multiplication by recursively adding: */
    int x = 3;
    int y = 5;

    printf("3 times 5 is %d\n", multiply(x, y));
    printf("\n");

    /* Calls the factorial function with different arguments (0, 1, 3, 5)
     and prints the results.*/
    printf("0! = %i\n", factorial(0));
    printf("1! = %i\n", factorial(1));
    printf("3! = %i\n", factorial(3));
    printf("5! = %i\n", factorial(5));
    return 0;
}
unsigned int multiply(unsigned int x, unsigned int y) {
    if (x == 1) {
        /* Terminating case */
        return y;
    } else if (x > 1) {
        /* Recursive step */
        return y + multiply(x - 1, y);
    }

    /* Catch scenario when x is zero */
    return 0;
}
/* 
* Define the factorial function
* Checks if n is 0. If it is, returns 1 (base case).
* Otherwise, returns n * factorial(n - 1), 
* which recursively calls the factorial function with n - 1.
*/
int factorial(int n) {
    if (n == 0) {
        return 1;  // Base case: 0! = 1
    } else {
        return n * factorial(n - 1);  // Recursive case
    }
}

