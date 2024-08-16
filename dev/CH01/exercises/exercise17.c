
// Write a program to print all input lines that are longer than 80 characters
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024  // Define a maximum line length that is sufficiently large

int main(void) {
    char line[MAX_LINE_LENGTH];

    // Read lines from standard input
    while (fgets(line, sizeof(line), stdin) != NULL) {
        // Remove the newline character at the end of the line if it exists
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        // Print the line if it is longer than 80 characters
        if (len > 80) {
            printf("%s\n", line);
        }
    }

    return 0;
}
