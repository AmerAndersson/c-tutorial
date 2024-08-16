/**
 * Dynamic Memory Allocation
 * Pointers are essential for dynamic memory allocation,
 * which allows for the allocation of memory at runtime.
 *
 *  This is done using functions like:
 * - malloc(), - calloc(), - realloc(), and - free().
 *
 * Dynamic Memory Allocation for an Array
 * The malloc function is used to allocate memory dynamically for an array.
 * How you might use it and handle potential allocation failure:
 * dynamic_memory
 */

#include <stdio.h>
#include <stdlib.h>

/* Declares a structure type struct Point */
typedef struct {
    int x;
    int y;
} Point;

int main(void) {
    Point *point = NULL;

    /* Dynamically allocate a new point struct which point points to here */
    point = (Point *)malloc(sizeof(Point));
    /* Check if memory allocation was successful */
    if (point == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); /* indicates allocation failure.*/
    }
    printf("Memory allocation successful\n");

    point->x = 10;
    point->y = 5;
    printf("point coordinates: %d, %d\n", point->x, point->y);
    /*-------------------------------------------------------------------
     * Memory Deallocation: 'point'
     * Free the allocated memory using free(arrays) to avoid memory leaks.
     * or dangling pointer, set it to NULL. The pointer arrays is
     * then set to * NULL to prevent it from being a dangling pointer.
     * Now person is safe to use in checks, and won't cause undefined behavior
     *--------------------------------------------------------------------
     */
    free(point);
    point = NULL;
    if (point == NULL) {
        printf("Point is NULL, safe to use in checks.\n");
    }
    printf("\n");

    /*
     * Dynamic Memory Allocation: Allocating and using dynamic memory for arrays,
     * arr is a pointer to a block of memory that can hold 10 integers.
     */
    int *arr = (int *)malloc(10 * sizeof(int));
    // Check if memory allocation was successful
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); /* indicates allocation failure.*/
    }
    printf("Memory allocation successful\n");

    /* Initialize and use the array*/
    int i;
    for (i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }

    /* Print the array elements*/
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /*-------------------------------------------------------------------
     * Memory Deallocation: 'array'
     * Free the allocated memory using free(arrays) to avoid memory leaks.
     * or dangling pointer, set it to NULL. The pointer arrays is
     * then set to * NULL to prevent it from being a dangling pointer.
     * Now person is safe to use in checks, and won't cause undefined behavior
     *--------------------------------------------------------------------
     */
    free(arr);
    arr = NULL;
    if (arr == NULL) {
        printf("Array is NULL, safe to use in checks.\n");
    }
    printf("\n");

    /*
     * se fprintf(stderr, ...) for error and diagnostic messages
     * to ensure they are seen immediately and not lost in redirection.
     *
     * Error Reporting: fprintf(stderr, "Memory allocation failed\n");
     * If malloc fails, an error message is immediately sent to stderr.
     * This ensures the error message is visible even if the program's
     * standard output is redirected.
     *
     * Normal Output: printf("Memory allocation successful\n");
     * If malloc succeeds, a confirmation message is sent to stdout.
     * This message can be redirected as needed without affecting
     * the visibility of the error message.
     */

    /* Memory Allocation: malloc is used to allocate 1000 bytes.*/
    char *data = (char *)malloc(1000 * sizeof(char));

    /* Check if memory allocation was successful*/
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); /* indicates allocation failure. */
    }
    printf("Memory allocation successful\n");

    /* Initialize the allocated memory with zeros*/
    for (i = 0; i < 1000; i++) {
        data[i] = 0;
    }
    /* Assign some values*/
    data[0] = 'H';
    data[1] = 'e';
    data[2] = 'l';
    data[3] = 'l';
    data[4] = 'o';
    data[5] = '\0';
    /* Print the string */
    printf("%s\n", data);
    /*-------------------------------------------------------------------
     * Memory Deallocation: 'data'
     * Free the allocated memory using free(arrays) to avoid memory leaks.
     * or dangling pointer, set it to NULL. The pointer arrays is
     * then set to * NULL to prevent it from being a dangling pointer.
     * Now person is safe to use in checks, and won't cause undefined behavior
     *--------------------------------------------------------------------
     */
    free(data);
    data = NULL;
    if (data == NULL) {
        printf("Data is NULL, safe to use in checks.\n");
    }
    return 0;
}
