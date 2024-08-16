/*
 * Arrays and Pointers
 * This code uses an integer array numbers and a pointer p_numbers to
 * illustrate the same concepts of pointer arithmetic and array indexing.
 * The addresses and values are printed * correctly by casting the pointers to void
 * when printing the addresses.
 */
#include <stdio.h>

int main(void) {
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char *p_vowels = vowels;
    int i;

    // Print the addresses
    for (i = 0; i < 5; i++) {
        printf("&vowels[%d]: %p, p_vowels + [%d]: %p, vowels + [%d]: %p\n",
               i, (void *)&vowels[i], i, (void *)(p_vowels + i), i, (void *)(vowels + i));
    }
    printf("\n");

    // Print the values
    for (i = 0; i < 5; i++) {
        printf("vowels[%d]: %c, *(p_vowels + [%d]): %c, *(vowels + [%d]): %c\n",
               i, vowels[i], i, *(p_vowels + i), i, *(vowels + i));
    }
    printf("\n");

    return 0;
}
