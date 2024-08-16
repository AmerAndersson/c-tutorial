/**
 * --------------------------------------------------------
 * This C program is designed to count the number of digits,
 * whitespace characters, and other characters in the input
 * provided by the user
 * count digits, white space, others
 * -------------------------------------------------------
 */
#include <stdio.h>

// count digits, white space, others
int main(void) {
    int c, i, nwhite, nother;
    int ndigit[10];  // declares ndigit to be an array of 10 integers.
    nwhite = nother = 0;

    // Initialize the ndigit array to zero
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    // Read characters from the input until EOF (End Of File)
    while ((c = getchar()) != EOF)
        // If the character is a digit (0-9)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];  // Increment the corresponding index in ndigit
    // If the character is a whitespace (space, newline, tab)
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;  // Increment the whitespace counter
    // If the character is anything else
        else
            ++nother;  // Increment the other characters counter

    // Print the results
    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);                                // Print the count of each digit
    printf(", white space = %d, other = %d\n", nwhite, nother);  // Print the count of whitespace and other characters
    return 0;
}
