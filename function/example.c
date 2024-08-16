/**
 * Macro defined in header <stdarg.h>
 * va_start: enables access to variadic function arguments.(function macro)

 * va_arg: accesses the next variadic function argument.(function macro)

 * va_copy(C99): makes a copy of the variadic function arguments.(function macro)

 * va_end: ends traversal of the variadic function arguments.(function macro)

 * va_list: This is a type suitable for holding information needed by the three macros va_start(), va_arg(), va_end() and va_copy.(typedef)
 */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a function that concatenates a
// variable number of strings into a single result string.
char *concatenate(int count, ...);

// THE MAIN FUNCTION:
int main(void) {
    char *res = concatenate(3, "Hello, ", "Hello World", "India");
    if (res) {
        printf("%s\n", res);
        // Free the allocated memory
        free(res);
    }
    return 0;
}

// Create a function that concatenates a
// variable number of strings into a single result string.
char *concatenate(int count, ...) {
    va_list args;  // Holds the information needed
    int length = 0;

    // Calculate length
    // Set the va_list variable with the last fixed argument
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        length += strlen(va_arg(args, char *));
    }
    va_end(args);  // Use the va_end to clean va_list variable

    // Allocate memory for the result string
    char *res = (char *)malloc(length + 1);
    if (!res) {
        return NULL;
    }

    // Concatenate the strings
    // Initialize result as an empty string
    res[0] = '\0';
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        strcat(res, va_arg(args, char *));
    }
    va_end(args);

    return res;
}
