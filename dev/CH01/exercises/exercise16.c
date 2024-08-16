/*
 * Revise the main routine of the longest-line program
 * so it will correctly print the length of arbitrary long input lines,
 * and as much as possible of the text.
 */

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_BUFFER_SIZE 100

int getline_dynamic(char **line, int *size);
void copy(char *to, char *from);

int main(void) {
    char *line = NULL;
    char *longest = NULL;
    int len;
    int max = 0;
    int buffer_size = INITIAL_BUFFER_SIZE;

    /* Allocate initial memory for line and longest */
    line = malloc(buffer_size);
    longest = malloc(buffer_size);

    if (line == NULL || longest == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    while ((len = getline_dynamic(&line, &buffer_size)) > 0) {
        if (len > max) {
            max = len;
            if (max >= buffer_size) {
                /* Reallocate memory for the longest line if necessary */
                longest = realloc(longest, buffer_size);
                if (longest == NULL) {
                    printf("Error reallocating memory\n");
                    free(line);
                    return 1;
                }
            }
            copy(longest, line);
        }
    }

    if (max > 0) {  /* There was a line */
        printf("Longest line length: %d\n", max);
        printf("Longest line text: %s\n", longest);
    }

    free(line);
    free(longest);
    return 0;
}

int getline_dynamic(char **line, int *size) {
    int c, len = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (len >= *size - 1) {  /* Check if more memory is needed*/
            *size *= 2;
            *line = realloc(*line, *size);
            if (*line == NULL) {
                printf("Error reallocating memory\n");
                exit(1);
            }
        }
        (*line)[len++] = c;
    }

    if (c == '\n') {
        (*line)[len++] = c;
    }

    (*line)[len] = '\0';
    return len;
}

void copy(char *to, char *from) {
    while ((*to++ = *from++) != '\0');
}
