// C program to create a horizontal histogram of word lengths:
// This involves determining the maximum count of any word length and then printing from the top row downwards
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

    // Print the horizontal histogram
    printf("\nHorizontal Histogram of Word Lengths:\n");
    for (i = 1; i <= MAX_WORD_LENGTH; ++i) {
        printf("%2d: ", i);
        for (j = 0; j < word_lengths[i]; ++j) {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
