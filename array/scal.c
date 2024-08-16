/**
 * The first seven rows of Pascal's triangle are shown below. Note that row i contains i elements.
 * Therefore, to store the numbers from the first three rows, one would require 1 + 2 + 3 = 6 memory slots.
 * 1
 * 1 1
 * 1 2 1
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Define the 2D pointer variable here */
    int n_rows = 7;
    int n_cols = 7;
    int i, j;

    /* Allocate memory for holding three rows pointers */
    int **p_numbers = (int **)malloc(n_rows * sizeof(int *));

    /* Allocate memory for storing the individual elements in each row */
    p_numbers[0] = (int *)malloc(n_cols * sizeof(int));
    p_numbers[1] = (int *)malloc(n_cols * sizeof(int));
    p_numbers[2] = (int *)malloc(n_cols * sizeof(int));

    /* Check if memory allocation was successful*/
    if (p_numbers == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); /* indicates allocation failure.*/
    }
    printf("Memory allocation successful\n");

    /* Assign values to Pascal's triangle: The values are directly assigned to the allocated memory blocks*/
    p_numbers[0][0] = 1;
    p_numbers[1][0] = 1;

    p_numbers[1][1] = 1;
    p_numbers[2][0] = 1;

    p_numbers[2][1] = 2;
    p_numbers[2][2] = 1;

    /* Print the Pascal's triangle: A nested loop prints the values.*/
    for (i = 0; i < n_rows; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", p_numbers[i][j]);
        }
        printf("\n");
    }

    /* Free memory allocated for each row: This is done in a loo*/
    for (i = 0; i < n_rows; i++) {
        free(p_numbers[i]);
    }

    /*
     * Free the top-level pointer: Finally, free the memory allocated for
     * the row pointers using free(p_numbers);
     * Free the allocated memory using free(p_vowel) to avoid memory leaks.
     */
    free(p_numbers);

    /*
     * This check confirms that p_numbers has been set to NULL after freeing the memory,
     * indicating it is safe for use in subsequent checks to prevent dereferencing
     * a freed pointer.
     */
    p_numbers = NULL;
    if (p_numbers == NULL) {
        printf("p_numbers is NULL, safe to use in checks.\n");
    }

    return 0;
}
