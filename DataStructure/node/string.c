/*
 * Pointers are also variables and play a very important role in C programming language.
 * They are used for several reasons, such as
 *
 * - Strings
 * - Dynamic memory allocation
 * - Sending function arguments by reference
 * - Building complicated data structures
 * - Pointing to functions
 * - Building special data structures (i.e. Tree, Tries, etc...)
 *
 * In C, strings are arrays of characters,and pointers are often used
 * to manipulate strings efficiently.
 *
 * - Summary
 * Pointers in C are versatile and powerful, enabling efficient memory management,
 * dynamic memory allocation, the creation of complex data structures,
 * and the implementation of function pointers.
 * Their ability to directly manipulate memory addresses makes them
 * an indispensable tool for C programmers.
 */

#include <stdio.h>
#include <stdlib.h>

// increment function takes a pointer to an integer
// and increments the actual integer value.
void increment(int *num);
void swap(int *a, int *b);

// greeting message
void greet();

int main(void) {
    // String Manipulation: Using pointers to traverse and manipulate strings.
    // String Manipulation Using Pointers
    // ptrs is a pointer to the first character of the string str.
    // Pointers allow you to traverse and manipulate strings easily.

    char str[] = "Hello, World!";
    char *ptr = str;

    // Print the string using the pointer
    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");
    // Reset pointer to the start of the string
    ptr = str;
    // Modify the string using the pointer
    ptr[7] = 'C';

    // Print the modified string
    printf("%s\n", str);
    printf("\n");

    /*
     * Sending Function Arguments by Reference
     * In C, passing arguments to functions by reference (using pointers)
     * allows functions to modify the actual variables passed to them.
     * This is crucial for efficiency and for functions to return multiple values.
     */

    // Define a local variable value in our stack,
    int value = 10;

    // Sending Function Arguments by Reference
    increment(&value);
    printf("%d\n", value);  // Output: 11
    printf("\n");

    // Define a local variable value in our stack,
    int n1 = 10;
    int n2 = 20;

    // value before swapping
    printf("Before swapping: n1 is %d and n2 is %d\n", n1, n2);
    // calling the function passed by reference the address of the
    // arguments, they will be swapped with each other.
    swap(&n1, &n2);

    // value after swapping
    printf("After swapping: n1 is %d and n2 is %d\n", n1, n2);

    /**
     * Pointing to Functions
     * Function pointers allow you to store the address of a function in a variable.
     * This can be used for callback functions and implementing function tables.
     */

    // Pointing to Functions
    // funcPtr is a pointer to the greet function.
    void (*funcPtr)() = greet;
    funcPtr();  // Calls the greet function

    return 0;
}

// increment function takes a pointer to an integer
// and increments the actual integer value.
void increment(int *value) { (*value)++; }

// function definition with relevant pointers to recieve the
// parameters
void swap(int *a, int *b) {
    // accessing arguments like pointers
    int temp = *a;
    *a = *b;
    *b = temp;
}
void greet() { printf("Hello, World!\n"); }
