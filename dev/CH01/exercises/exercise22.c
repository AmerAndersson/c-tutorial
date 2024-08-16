/**
 * Write a program to ``fold'' long input lines into two or more shorter
 * lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with
 * very long lines, and if there are no blanks or tabs before the
 * specified column.
 */
#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000  // Maximum input line size

int get_line(char line[], int max_line);
void fold_line(char line[], int max_len, int n);

int main(void) {
    int column = 30;  // Column number at which we fold lines
    char line[MAX_LINE];

    while (get_line(line, MAX_LINE) > 0) {
        fold_line(line, MAX_LINE, column);
    }

    return 0;
}

// Function to get a line from input
int get_line(char line[], int max_line) {
    int c, i;

    for (i = 0; i < max_line - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

// Function to fold a line
void fold_line(char line[], int max_len, int n) {
    int len = strlen(line);
    int last_blank = -1;
    int col = 0;

    for (int i = 0; i < len; ++i) {
        if (line[i] == ' ' || line[i] == '\t') {
            last_blank = i;
        }
        if (col >= n) {
            if (last_blank == -1) {
                // If there's no blank space, fold at column n
                putchar('\n');  // Print the character to the console
                col = 0;
            } else {
                // Fold at the last blank space
                line[last_blank] = '\n';
                col = i - last_blank;
                last_blank = -1;
            }
        }
        putchar(line[i]);  // Print the character to the console
        col++;
        if (line[i] == '\n') {
            col = 0;
        }
    }
}
