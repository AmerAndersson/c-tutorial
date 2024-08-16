#include <stdio.h>

// Define Constants:
#define IN 1   // inside a word
#define OUT 0  // outside a word

/*
 * This line includes the standard I/O library
 * which allows the program to use functions
 * like getchar() and printf().
 * count lines, words, and characters in input
 */
int main(void) {
    /**
     * c is an integer variable to store the current character read from input.
     * nl (number of lines),
     * nw (number of words),
     * nc (number of characters) are integer counters.
     * state is used to track whether the program is currently
     * inside a word or outside a word.
     */
    int c, nl, nw, nc, state;

    // Set the initial state to OUT (outside a word).
    // Initialize the counters nl, nw, and nc to 0. state = OUT;
    nl = (nw = (nc = 0));  // nl = nw = nc = 0;

    // Read Input and Count:
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' | c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    // Print the number of (lines, words, and characters).
    printf("%d %d %d\n", nl, nw, nc);
    return 0;
}
