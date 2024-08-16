#include <stdarg.h>
#include <stdio.h>

// Variadic functions. with a variable number of arguments
void printNumbers(int count, ...);

// Function with two fixed arguments
// add function takes exactly two integer arguments, a and b
int add(int a, int b);

// Functions can only return one value, or return no value.
// Function returning an integer value
int multiply(int a, int b);

// greet performs an action (printing  a message)
// but does not return any value. (void)
void greet();

int main(void) {
    // printNumbers can take a variable number of integer arguments,
    // with the first argument indicating the count of subsequent arguments.
    // Call the sum, with number of arguments
    // Call the sum, with number of arguments
    printNumbers(5, 1, 2, 3, 4, 5);               // Output: 1 2 3 4 5
    printNumbers(7, 10, 20, 30, 40, 50, 60, 70);  // Output: 10 20 30 40 50 60 70
    printf("\n");

    // Function with two fixed arguments
    int result = add(5, 3);
    printf("Result: %d\n", result);  // Output: Result: 8
    printf("\n");

    // multiply returns the product of two integers.
    int product = multiply(4, 5);
    printf("Result: %d\n", product);  // Output: Result: 20

    // greet performs an action (printing a message)
    // but does not return any value. (void)
    greet();  // Output: Hello, World!

    return 0;
}
// Variadic functions. with a variable number of arguments
void printNumbers(int count, ...) {
    va_list args;
    int i, tot;

    // Set the va_list variable with the last fixed argument
    va_start(args, count);

    // Retrieve the arguments and calculate the printNumbers
    for (i = 0; i < count; i++) {
        tot += va_arg(args, int);
        printf("%d ", tot);
    }
    // use the va_end to clean va_list variable
    va_end(args);
    printf("\n");
}
// Function with two fixed arguments
int add(int a, int b) {
    return a + b;
}

// Functions can only return one value, or return no value.
// Function returning an integer value
int multiply(int a, int b) {
    return a * b;
}

// greet performs an action (printing a message)
// but does not return any value. (void)
void greet() {
    printf("Hello, World!\n");
}