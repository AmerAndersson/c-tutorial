/**
 * Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
 *
 * getchar( ) function is used to read one character at a time from the key board.
 * ch = getchar( ); where ch is a char Var. When this function is executed, the computer will wait for a key to be pressed and assigns the value to the variable when the “enter” key pressed.
 */

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB_WIDTH 8  // Default tab width, can be changed if needed

void detab(int tab_width);

int main(int argc, char *argv[]) {
    int tab_width = DEFAULT_TAB_WIDTH;

    if (argc > 1) {
        tab_width = atoi(argv[1]);
        if (tab_width <= 0) {
            fprintf(stderr, "Invalid tab width specified. Using default value of %d.\n", DEFAULT_TAB_WIDTH);
            tab_width = DEFAULT_TAB_WIDTH;
        }
    }

    detab(tab_width);
    return 0;
}

void detab(int tab_width) {
    int ch, i, column = 0;

    // read one character at a time from the key board
    while ((ch = getchar()) != EOF) {
        if (ch == '\t') {
            int spaces = tab_width - (column % tab_width);
            for (i = 0; i < spaces; ++i) {
                putchar(' ');
                ++column;
            }
        } else {
            putchar(ch);
            if (ch == '\n') {
                column = 0;
            } else {
                ++column;
            }
        }
    }
}
