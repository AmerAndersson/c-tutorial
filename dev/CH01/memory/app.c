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
    int numStudents = 12;
    int *students = calloc(numStudents, sizeof(*students));
    printf("%lu Bytes\n", numStudents * sizeof(*students));  // 48 bytes

    // Allocate memory
    int *ptr = calloc(4, sizeof(*ptr));

    // Write to the memory
    *ptr = 2;
    ptr[1] = 4;
    ptr[2] = 6;
    ptr[3] = 10;

    // Read from the memory
    printf("%d\n", *ptr);
    printf("%d %d %d\n", ptr[1], ptr[2], ptr[3]);

    return 0;
}
