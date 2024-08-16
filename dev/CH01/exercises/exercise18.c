// Write a program to remove trailing blanks and tabs from each line of input,
// and to delete entirely blank lines.
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024  // Define a maximum line length that is sufficiently large

// Function to remove trailing blanks and tabs from a line
void trim_trailing_whitespace(char *line);

int main(void) {
    char line[MAX_LINE_LENGTH];

    // Read lines from standard input
    while (fgets(line, sizeof(line), stdin) != NULL) {
        trim_trailing_whitespace(line);

        // Print the line if it is not entirely blank
        if (strlen(line) > 0) {
            printf("%s\n", line);
        }
    }

    return 0;
}

void trim_trailing_whitespace(char *line) {
    size_t len = strlen(line);
    while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t' || line[len - 1] == '\n')) {
        len--;
    }
    line[len] = '\0';
}
