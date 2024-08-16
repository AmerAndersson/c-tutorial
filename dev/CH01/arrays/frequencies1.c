/*
C program to print a histogram of the frequencies of different characters in its input.
This program will count the occurrences of each character and then print a histogram showing 
those frequencies. Horizontal Histogram
*/
#include <stdio.h>

#define NUM_CHARS 128  // Number of possible ASCII characters

int main(void) {
    int c, i, j;
    int char_count[NUM_CHARS] = {0};  // Array to store character counts

    // Read input and count character frequencies
    while ((c = getchar()) != EOF) {
        if (c < NUM_CHARS) {
            ++char_count[c];
        }
    }

    // Print the horizontal histogram
    printf("\nHorizontal Histogram of Character Frequencies:\n");
    for (i = 0; i < NUM_CHARS; ++i) {
        if (char_count[i] > 0) {
            if (i >= 32 && i <= 126) {
                printf("%c: ", i);  // Printable characters
            } else {
                printf("%02x: ", i);  // Non-printable characters in hex
            }
            for (j = 0; j < char_count[i]; ++j) {
                printf("#");
            }
            printf("\n");
        }
    }

    return 0;
}
