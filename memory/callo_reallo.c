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
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Allocate memory for an array of 5 integers
    int *array = (int *)malloc(5 * sizeof(int));
    /* Check if memory allocation was successful */
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); /* indicates allocation failure.*/
    }
    int i;
    /* Initialize the array*/
    for (i = 0; i < 5; i++) {
        array[i] = i + 1;
    }

    /*----------------------------------------------------
     * Resize the array to hold 10 integers The original array is extended,
     * and the new elements are initialized.
     *----------------------------------------------------
     */
    int *new_array = (int *)realloc(array, 10 * sizeof(int));
    /* Check if memory allocation was successful */
    if (new_array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); /* indicates allocation failure.*/
    }

    /* Initialize the new elements */
    for (i = 5; i < 10; i++) {
        new_array[i] = i + 1;
    }

    /* Print the array elements */
    for (i = 0; i < 10; i++) {
        printf("new_array[%d] = %d\n", i, new_array[i]);
    }

    /*-------------------------------------------------------------------
     * The reallocated memory is free the allocated memory using free(new_array) * to avoid memory leaks. or dangling pointer, set it to NULL.
     * The pointer new_array is then set to * NULL to prevent it from
     * being a * dangling pointer. Now person is safe to use in checks,
     *  and won't cause undefined behavior
     *------------------------------------------------------------------
     */
    free(new_array);
    new_array = NULL;
    if (new_array == NULL) {
        printf("new_array is NULL, safe to use in checks.\n");
    }
    printf("\n");

    /*------------------------------------------------
     * Allocate memory for an array of 10 integers
     * and initializes all of them to zero.
     *------------------------------------------------
     */
    int *arrays = (int *)calloc(10, sizeof(int));
    /* Check if memory allocation was successful */
    if (arrays == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); /* indicates allocation failure.*/
    }
    /* Verify that the memory is zero-initialized*/
    for (i = 0; i < 10; i++) {
        printf("arrays[%d] = %d\n", i, arrays[i]);
    }

    /*-------------------------------------------------------------------
     * Free the allocated memory using free(arrays) to avoid memory leaks.
     * or dangling pointer, set it to NULL. The pointer arrays is
     * then set to * NULL to prevent it from being a dangling pointer.
     * Now person is safe to use in checks, and won't cause undefined behavior
     *--------------------------------------------------------------------
     */
    free(arrays);
    arrays = NULL;
    if (arrays == NULL) {
        printf("arrays is NULL, safe to use in checks.\n");
    }
    printf("\n");

    return 0;
}
