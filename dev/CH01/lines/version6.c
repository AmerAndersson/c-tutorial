#include <stdio.h>

/*
copy input to output, replacing each tab by \t, each backspace by \b, and each backslash by \\

The program reads characters from the standard input using getchar()
until EOF is encountered.

Inside the loop, it checks each character:

If the character is a tab ('\t'), it outputs \t by printing two characters: '\\' and 't'.
If the character is a backspace ('\b'), it outputs \b by printing two characters: '\\' and 'b'.
If the character is a backslash ('\\'), it outputs \\ by printing two characters: '\\' and '\\'.
For all other characters, it simply outputs the character as is.
*/
int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }

    return 0;
}
