#include <stdio.h>

#define MAXLINE 1000  // maximum input line size

int max;                // maximum length seen so far
char line[MAXLINE];     // current input line
char longest[MAXLINE];  // longest line saved here

// Function declaration
int get_line(void);
void copy(void);

// print longest input line
int main(void) {
    int len;
    extern int max;
    extern char longest[];  // Redundant extern definition & declaration

    max = 0;
    while ((len = get_line()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0)  // there was aline
        printf("%s", longest);
    return 0;
}

// Function definition
// get_line: specialized version
int get_line(void) {
    int c, i;
    extern char line[];  // Redundant extern definition & declaration

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

// Function definition
// copy: specialized version
void copy(void) {
    int i;
    extern char line[], longest[];  // Redundant extern definition & declaration
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
