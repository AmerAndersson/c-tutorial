/*
 * Dynamic memory allocation for a two-dimensional array.
 * This can be generalized to n-dimensions in a similar way.
 * Unlike one-dimensional arrays, where we used a pointer,
 * in this case we require a pointer to a pointer.
 *
 *  - Summary:
 * p_vowels is a dynamically allocated two-dimensional array of characters.
 * The code demonstrates how to allocate memory for such an array, assign values,
 * print them, and properly free the allocated memory to prevent memory leaks.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    /* Declaration n_row & n_cols */
    int n_rows = 2;
    int n_cols = 5;
    int i, j;

    /*
     * p_vowels is declared as a pointer to a pointer of type char,
     * malloc(n_rows * sizeof(char *)) allocates memory for n_rows pointers to char.
     * This is the first level of the two-dimensional array, representing the rows of the array.
     * Allocate memory for nrows pointers
     */
    char **p_vowels = (char **)malloc(n_rows * sizeof(char *));

    // For each row, allocate memory for n_cols elements
    p_vowels[0] = (char *)malloc(n_cols * sizeof(char));
    p_vowels[1] = (char *)malloc(n_cols * sizeof(char));

    /* Check if memory allocation was successful*/
    if (p_vowels == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); /* indicates allocation failure.*/
    }
    printf("Memory allocation successful\n");

    /*
     * Values are assigned to each element of the two-dimensional array.
     * p_vowels[0] refers to the first row, and p_vowels[1] refers to the second row.
     */
    p_vowels[0][0] = 'A';
    p_vowels[0][1] = 'B';
    p_vowels[0][2] = 'C';
    p_vowels[0][3] = 'D';
    p_vowels[0][4] = 'E';

    p_vowels[1][0] = 'a';
    p_vowels[1][1] = 'b';
    p_vowels[1][2] = 'c';
    p_vowels[1][3] = 'd';
    p_vowels[1][4] = 'e';

    /*
     * Printing the Array:
     * A nested loop is used to print the elements of the array.
     * The outer loop iterates over the rows,
     * and the inner loop iterates over the columns of each row.
     */
    for (i = 0; i < n_rows; i++) {
        for (j = 0; j < n_cols; j++) {
            printf("%c ", p_vowels[i][j]);
        }

        printf("\n");
    }

    /*
     * The allocated memory for each row is freed first.
     * Then, the memory allocated for the array of pointers is freed.
     * Free the allocated memory using free(p_vowel) to avoid memory leaks.
     */
    free(p_vowels[0]); /* Free individual rows.*/
    free(p_vowels[1]);
    free(p_vowels); /* Free the top-level pointer */

    /*
     * This check confirms that p_vowels has been set to NULL after freeing the memory,
     * indicating it is safe for use in subsequent checks to prevent dereferencing
     * a freed pointer.
     */
    p_vowels = NULL;
    if (p_vowels == NULL) {
        printf("p_vowels is NULL, safe to use in checks.\n");
    }
    return 0;
}
