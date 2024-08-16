#include <stdio.h>

#define IN 1   // inside a word
#define OUT 0  // outside a word

int main(void) {
    int c, state;

    // Initialize the state to OUT (outside a word)
    state = OUT;

    // Read input character by character
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                // End of a word, print a newline
                putchar('\n');
                state = OUT;
            }
        } else {
            // Inside a word, print the character
            putchar(c);
            state = IN;
        }
    }

    // If the last character was part of a word, ensure a newline at the end
    if (state == IN) {
        putchar('\n');
    }

    return 0;
}
