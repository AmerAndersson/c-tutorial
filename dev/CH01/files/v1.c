#include <stdio.h>

/*
 * copy input to output
 * - read a character
 * - while (charater is not end-of-file indicator)
 *   - output the character just read
 * - read a character
 */
int main(void) {
    // An integer to store the character
    int c;

    // File Copying
    c = getchar();
    while (c != EOF) {
        // putchar prints a character each time:
        putchar(c);
        c = getchar();
    }

    return 0;
}
