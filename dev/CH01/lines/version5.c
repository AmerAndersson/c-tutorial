#include <stdio.h>

/*
copy input to output, replacing each string of one or more blanks by a single blank.

The program initializes a flag in_blank to keep track of whether it is currently processing a sequence of blanks.

It enters a while loop that reads characters from standard input (getchar()) until EOF (End Of File) is encountered.

Inside the loop, it checks each character:
If the character is a blank (' '):
If in_blank is not set (i.e., the previous character was not a blank),
it outputs a single blank and sets in_blank to 1.
If in_blank is already set, it skips outputting the blank.
If the character is not a blank, it outputs the character and resets in_blank to 0, indicating that it is no longer in a sequence of blanks.
If the character is not a blank, it outputs the character and resets in_blank to 0, indicating that it is no longer in a sequence of blanks.
*/
int main(void) {
    int c;
    int in_blank = 0;  // Flag to indicate if we are currently in a sequence of blanks

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!in_blank) {
                putchar(c);    // Output a single blank
                in_blank = 1;  // Set flag to indicate we are in a blank sequence
            }
        } else {
            putchar(c);    // Output the non-blank character
            in_blank = 0;  // Reset flag since we're not in a blank sequence anymore
        }
    }

    return 0;
}
