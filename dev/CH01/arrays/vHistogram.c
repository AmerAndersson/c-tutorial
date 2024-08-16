//  C program for a vertical histogram of word lengths:
#include <stdio.h>

#define MAX_WORD_LENGTH 20  // Maximum word length we are considering

int main(void) {
    int c, i, j, word_length = 0;
    int word_lengths[MAX_WORD_LENGTH + 1] = {0};  // Array to store word length counts

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (word_length > 0) {
                if (word_length <= MAX_WORD_LENGTH)
                    ++word_lengths[word_length];
                else
                    ++word_lengths[MAX_WORD_LENGTH];  // Consider words longer than MAX_WORD_LENGTH in a single bucket
                word_length = 0;
            }
        } else {
            ++word_length;
        }
    }

    // Handle the last word if it wasn't followed by a space, newline or tab
    if (word_length > 0) {
        if (word_length <= MAX_WORD_LENGTH)
            ++word_lengths[word_length];
        else
            ++word_lengths[MAX_WORD_LENGTH];
    }

    // Determine the maximum count of any word length
    int max_count = 0;
    for (i = 1; i <= MAX_WORD_LENGTH; ++i) {
        if (word_lengths[i] > max_count) {
            max_count = word_lengths[i];
        }
    }

    // Print the vertical histogram
    printf("\nVertical Histogram of Word Lengths:\n");
    for (i = max_count; i > 0; --i) {
        for (j = 1; j <= MAX_WORD_LENGTH; ++j) {
            if (word_lengths[j] >= i) {
                printf(" # ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    // Print the axis with word lengths
    for (i = 1; i <= MAX_WORD_LENGTH; ++i) {
        printf("---");
    }
    printf("\n");
    for (i = 1; i <= MAX_WORD_LENGTH; ++i) {
        printf("%2d ", i);
    }
    printf("\n");

    return 0;
}
