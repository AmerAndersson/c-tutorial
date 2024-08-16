/*
 * Arrays and Pointers
 * This code uses an integer array numbers and a pointer p_numbers to
 * illustrate the same concepts of pointer arithmetic and array indexing.
 * The addresses and values are printed * correctly by casting the pointers to void
 * when printing the addresses.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Allocate memory to store five characters
    int n = 5;
    char *p_vowels = (char *)malloc(n * sizeof(char));
    int i;

    /*
     * Check if memory allocation was successful
     * If malloc returns NULL, it means the allocation failed,
     * and we print an error message and exit the program.
     */
    if (p_vowels == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); /* indicates allocation failure.*/
    }
    printf("Memory allocation successful\n");

    p_vowels[0] = 'A';
    p_vowels[1] = 'B';
    *(p_vowels + 2) = 'C';
    p_vowels[3] = 'D';
    *(p_vowels + 4) = 'E';

    /*
     p_vowels points to the first element of the array, which is 'A'.
     p_vowels + 4 points to the fifth element of the array (index 4).
     *(p_vowels + 4) dereferences this pointer to access the actual element at this position.
     *(p_vowels + 4) = 'U'; sets the fifth element of the array to 'E'.

     *(p_vowels + 2) = 'I'; sets the third element to 'C'.
     p_vowels[3] = 'O'; sets the fourth element to 'D'.
     */

    /* Verify that the memory is zero-initialized*/
    for (i = 0; i < n; i++) {
        printf("%c ", p_vowels[i]);
    }

    printf("\n");

    /* Free the allocated memory using free(p_vowel) to avoid memory leaks.*/
    free(p_vowels);
    p_vowels = NULL;
    if (p_vowels == NULL) {
        printf("p_vowels is NULL, safe to use in checks.\n");
    }

    return 0;
}
