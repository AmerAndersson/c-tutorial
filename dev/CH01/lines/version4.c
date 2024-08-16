#include <stdio.h>

/*
 * C program to count blanks, tabs, and newlines in the input
 * 4nd version:

 * The program initializes three counters: blanks, tabs, and newlines to zero.
 * It then enters a while loop that reads characters from standard input
 * (getchar()) until EOF (End Of File) is encountered.
 *
 * Inside the loop, it checks each character
 * If the character is a blank (' '), it increments the blanks counter.
 * If the character is a tab ('\t'), it increments the tabs counter.
 * If the character is a newline ('\n'), it increments the newlines counter.
 */
int main(void) {
    int c, blanks, tabs, newlines;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
        } else if (c == '\t') {
            ++tabs;
        } else if (c == '\n') {
            ++newlines;
        }
    }

    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);

    return 0;
}
