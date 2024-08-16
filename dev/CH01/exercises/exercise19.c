// Write a function reverse(s) that reverses the character string s.
// Use it to write a program that reverses its input a line at a time.
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024  // Define a maximum line length that is sufficiently large

// Function to reverse a character string
void reverse(char s[]);

int main(void) {
    char line[MAX_LINE_LENGTH];

    // Read lines from standard input
    while (fgets(line, sizeof(line), stdin) != NULL) {
        // Remove the newline character at the end of the line if it exists
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // Reverse the line
        reverse(line);

        // Print the reversed line
        printf("%s\n", line);
    }

    return 0;
}
void reverse(char s[]) {
    int length = strlen(s);
    int i;
    for (i = 0; i < length / 2; i++) {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
}
