/**
 * calloc
 * calloc is used to allocate memory for an array of elements,
 * initializing all bytes to zero. This function is particularly
 * useful when you want to ensure that the allocated memory is zero-initialized.
 * calloc(10, sizeof(int)) allocates memory for 10 integers
 * and initializes all of them to zero.
 *
 * void *calloc(size_t num, size_t size);
 * num: Number of elements.
 * size: Size of each element.
 *
 * realloc
 * realloc is used to resize a previously allocated memory block.
 * It can either extend or shrink the size of the block,
 * and it may move the block to a new location if necessary.
 *
 * void *realloc(void *ptr, size_t size);
 * ptr: Pointer to the previously allocated memory block.
 * size: New size in bytes.

 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Allocate memory for an array of 10 integers
    // and initializes all of them to zero.
    int *array = (int *)calloc(10, sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);  // Exit if memory allocation failed
    }
    
    // int length = sizeof(array) / sizeof(0);
    // Verify that the memory is zero-initialized
    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    /*
     * Free the allocated memory using free(person) to avoid memory leaks.
     * or dangling pointer, set it to NULL. The pointer person is
     * then set to * NULL to prevent it from being a dangling pointer.
     * Now person is safe to use in checks, and won't cause undefined behavior
     */
    free(array);
    array = NULL;
    if (array == NULL) {
        printf("array is NULL, safe to use in checks.\n");
    }
    printf("\n");

    // Allocate memory for an array of 5 integers
    int *arrays = (int *)malloc(5 * sizeof(int));
    if (arrays == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);  // Exit if memory allocation failed
    }

    // Initialize the array
    for (int i = 0; i < 5; i++) {
        arrays[i] = i + 1;
    }

    /*
     * Resize the array to hold 10 integers
     * realloc is used to resize a previously allocated memory block.
     * It can either extend or shrink the size of the block,
     * and it may move the block to a new location if necessary
     */
    int *new_array = (int *)realloc(arrays, 10 * sizeof(int));
    if (new_array == NULL) {
        printf("Memory reallocation failed\n");
        free(array);  // Free the original memory to avoid a memory leak
        return 1;
    }

    // Initialize the new elements
    for (int i = 5; i < 10; i++) {
        new_array[i] = i + 1;
    }

    // Print the array elements
    for (int i = 0; i < 10; i++) {
        printf("new_array[%d] = %d\n", i, new_array[i]);
    }

    // Free the reallocated memory
    free(new_array);
    return 0;
}
