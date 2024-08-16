/**
 * The first seven rows of Pascal's triangle are shown below. Note that row i contains i elements.
 * Therefore, to store the numbers from the first three rows, one would require 1 + 2 + 3 = 6 memory slots.
 * 1
 * 1 1
 * 1 2 1
 * 1 3 3 1
 * 1 4 6 4 1
 * 1 5 10 10 5 1
 * 1 6 15 20 15 6 1
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Declaration n_rows */
    int n_rows = 7;
    int i, j;

    /* Allocate memory for holding pointers to rows */
    int **p_numbers = (int **)malloc(n_rows * sizeof(int *));

    /* Check if memory allocation for row pointers was successful */
    if (p_numbers == NULL) {
        fprintf(stderr, "Memory allocation for row pointers failed\n");
        exit(1); /* indicates allocation failure.*/
    }

    /* Allocate memory for storing the individual elements in each row and check for successful allocation */
    for (i = 0; i < n_rows; i++) {
        p_numbers[i] = (int *)malloc((i + 1) * sizeof(int));
        if (p_numbers[i] == NULL) {
            fprintf(stderr, "Memory allocation for row %d failed\n", i);
            exit(1); /* indicates allocation failure.*/
        }
    }

    printf("Memory allocation successful\n");

    /* Assign values to Pascal's triangle
     Nested loops are used to correctly assign the values in Pascal's Triangle*/
    for (i = 0; i < n_rows; i++) {
        p_numbers[i][0] = 1;
        p_numbers[i][i] = 1;
        for (j = 1; j < i; j++) {
            p_numbers[i][j] = p_numbers[i - 1][j - 1] + p_numbers[i - 1][j];
        }
    }

    /* Print the Pascal's triangle */
    for (i = 0; i < n_rows; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", p_numbers[i][j]);
        }
        printf("\n");
    }

    /* Free memory allocated for each row
    This ensures efficient memory usage and avoids segmentation faults or accessing invalid memory regions.*/
    for (i = 0; i < n_rows; i++) {
        free(p_numbers[i]);
    }

    /* Free the top-level pointer */
    free(p_numbers);

    /* Set the pointer to NULL */
    p_numbers = NULL;

    /* Confirm that p_numbers has been set to NULL */
    if (p_numbers == NULL) {
        printf("p_numbers is NULL, safe to use in checks.\n");
    }

    return 0;
}
