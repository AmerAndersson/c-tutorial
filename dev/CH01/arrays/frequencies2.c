/**
 For a vertical histogram, the approach is slightly different.
 We need to determine the maximum frequency and then print
 the histogram from top to bottom. Vertical Histogram
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

    // Determine the maximum frequency
    int max_count = 0;
    for (i = 0; i < NUM_CHARS; ++i) {
        if (char_count[i] > max_count) {
            max_count = char_count[i];
        }
    }

    // Print the vertical histogram
    printf("\nVertical Histogram of Character Frequencies:\n");
    for (i = max_count; i > 0; --i) {
        for (j = 0; j < NUM_CHARS; ++j) {
            if (char_count[j] > 0) {
                if (char_count[j] >= i) {
                    printf(" # ");
                } else {
                    printf("   ");
                }
            }
        }
        printf("\n");
    }

    // Print the axis with characters
    for (i = 0; i < NUM_CHARS; ++i) {
        if (char_count[i] > 0) {
            if (i >= 32 && i <= 126) {  // Printable characters
                printf(" %c ", i);
            } else {
                printf("%02x", i);  // Non-printable characters in hex
            }
        }
    }
    printf("\n");

    return 0;
}
