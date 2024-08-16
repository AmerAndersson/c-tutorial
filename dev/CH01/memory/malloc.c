#include <stdio.h>
#include <stdlib.h>

/**
 * Dynamic memory is memory that is allocated after the program starts running.
 * Allocation of dynamic memory can also be referred to as runtime memory allocation.

 * Unlike with static memory, you have full control over how much memory is being used at any time. * You can write code to determine how much memory you need and allocate it.

 * Dynamic memory does not belong to a variable, it can only be accessed with pointers.

 * To allocate dynamic memory, you can use the malloc() or calloc() functions.
 * It is necessary to include the <stdlib.h> header to use them.
 * The malloc() and calloc() functions allocate some memory and return a pointer to its address.
 */
int main(void) {
    int *p1 = malloc(4 * sizeof(int));  // allocates enough for an array of 4 int
    int *p2 = malloc(sizeof(int[4]));   // same, naming the type directly
    int *p3 = malloc(4 * sizeof *p3);   // same, without repeating the type name

    int n;

    if (p1) {
        for (n = 0; n < 4; ++n)  // populate the array
            p1[n] = n * n;
        for (n = 0; n < 4; ++n)  // print it back out
            printf("p1[%d] == %d\n", n, p1[n]);
    }

    free(p1);
    free(p2);
    free(p3);

    p1 = NULL;
    p2 = NULL;
    p3 = NULL;

    printf("\n");

    // C program to demonstrate
    // use of void pointers
    int val = 30;
    void *ptr = &val;
    printf("%d\n", *(int *)ptr);
    return 0;
}
