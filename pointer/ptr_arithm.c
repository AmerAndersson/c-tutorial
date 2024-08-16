#include <stdio.h>

int main(void) {
    /*
     * Incrementing a Pointer with (++)
     * We increased the pointer's pointed-to address by one using the ++ operator:
     * Just like any variable the ++ operation increases the value of that variable.
     * In our case here the variable is a pointer hence when we increase its value
     * we are increasing the address in the memory that pointer points to.
     * Let's combine this operation with an array:
     */
    printf("\n");
    printf("--------------------------------------------------------\n");
    int ints_array[5] = {10, 20, 30, 40, 50};

    int length = sizeof(ints_array) / sizeof(int);
    int i;

    for (i = 0; i < length; i++) {
        // Print the address and value
        // Cast pointer arguments to (void *) to match the expected type for %p
        printf("ints_array[%d] has value %d - and address @ %p\n", i, ints_array[i], (void *)&ints_array[i]);
    }
    printf("\n");

    // Point to the 4th element in the array
    int *ints_pointer = &ints_array[3];

    // Print the address of the 4th element
    // Cast pointer arguments to (void *) to match the expected type for %p
    printf("address: %p ++ has value %d\n", (void *)ints_pointer, *ints_pointer);

    // Now increase the pointer's address so it points to the 5th element in the array
    ints_pointer++;

    // Print the address of the 5th element
    // Cast pointer arguments to (void *) to match the expected type for %p
    printf("address: %p ++ has value %d\n", (void *)ints_pointer, *ints_pointer);
    printf("\n");
    printf("--------------------------------------------------------\n");

    /*
     * Decreasing a Pointer with (--)
     * decrease the address pointed-to by one using the decrement operator (--).
     */

    int int_array[5] = {10, 20, 30, 40, 50};

    for (i = 0; i < 5; i++) {
        printf("int_array[%d] has value %d - and address @ %p\n", i, int_array[i], (void *)&int_array[i]);
    }
    printf("\n");

    // point to the 5th element in the array
    int *int_pointer = &int_array[4];

    // print the address of the 5th element
    printf("address: %p -- has value %d\n", (void *)int_pointer, *int_pointer);
    // now decrease the point's address so it points to the 4th element in the array
    int_pointer--;

    // Cast pointer arguments to (void *) to match the expected type for %p
    // print the address of the 4th element
    printf("address: %p -- has value %d\n", (void *)int_pointer, *int_pointer);
    printf("\n");
    printf("--------------------------------------------------------\n");

    /*
     * Adding Pointers with (+)
     * We can also increase it by an integer value such:
     */

    int array[5] = {10, 20, 30, 40, 50};

    for (i = 0; i < 5; i++) {
        printf("array[%d] has value: %d - and address @ %p\n", i, array[i], (void *)&array[i]);
    }
    printf("\n");

    // point to the 2nd element in the array
    int *pointer = &array[1];

    // print the address of the 2nd element
    printf("address: %p + has value %d\n", (void *)pointer, *pointer);

    // Now shift by two the point's address so it points to the 4th element in the array
    pointer += 2;  // the address is shifted by blocks of 4bytes (in case of int).
    // print the address of the 4th element
    printf("address: %p + has value %d\n", (void *)pointer, *pointer);
    /*
     * Note how in the output the address shifted by 8 steps in the memory.
     * You might be wondering why? The answer is simple:
     *
     * Because our pointer is an int-pointer and the size of an int variable is 4 bytes
     * the memory is shift-able by 4 blocks.
     *
     * In our code we shifted by 2 (added +2) to the initial address so that makes them 2 x 4 byte = 8.
     *
     */
    printf("\n");
    printf("--------------------------------------------------------\n");

    // Subtracting Pointers with (-) Similarly we can subtract:
    int arrays[5] = {10, 20, 30, 40, 50};

    for (i = 0; i < length; i++) {
        printf("arrays[%d] has value: %d - and address @ %p\n", i, arrays[i], (void *)&arrays[i]);
    }
    printf("\n");
    // point to the 5th element in the array
    int *ptr = &arrays[4];
    // print the address of the 5th element
    printf("address: %p -= has value %d\n", (void *)ptr, *ptr);

    // now shift by two the point's address so it points to the 3rd element in the array
    ptr -= 2;  // the address is shifted by blocks of 4bytes (in case of int).

    // print the address of the 3rd element
    printf("address: %p -= has value %d\n", (void *)ptr, *ptr);
    printf("\n");
    printf("--------------------------------------------------------\n");

    /**
     * Equality (==): Checks if two pointers point to the same memory location.
     * Inequality (!=): Checks if two pointers point to different memory locations.
     */
    int a = 5, b = 10;
    int *p1 = &a;
    int *p2 = &a;
    int *p3 = &b;

    if (p1 == p2) {
        printf("This condition is true since p1 and p2 point to the same memory location: (address of a)\n");
    }

    if (p1 != p3) {
        printf(
            "This condition is true since p1 and p3 point to different memory locations: (address of a and b "
            "respectively)\n");
    }
    printf("\n");
    printf("--------------------------------------------------------\n");

    /*
     * Relational Operators
     * Greater than (>): Checks if one pointer points to a memory address that comes
     * after another pointer in memory.
     *
     * Less than (<): Checks if one pointer points to a memory address that comes
     * before another pointer in memory.
     *
     * Greater than or equal to (>=): Checks if one pointer points to a memory address that comes
     * after or is the same as another pointer.
     *
     * Less than or equal to (<=): Checks if one pointer points to a memory address that comes
     * before or is the same as another pointer.
     */
    int arr[10];
    int *p4 = &arr[0];
    int *p5 = &arr[5];

    if (p4 < p5) {
        printf("This condition is true since p4 points to the beginning of the array and p5 points to 6th element\n");
    }

    if (p5 > p4) {
        printf("This condition is true since p5 points to a memory address further down the array than p4\n");
    }

    if (p4 <= &arr[0]) {
        printf("This condition is true since p4 points to the beginning of the array\n");
    }

    if (p5 >= &arr[5]) {
        printf("This condition is true since p5 points to the 6th element of the array\n");
    }
    printf("\n");
    printf("--------------------------------------------------------\n");

    /*
     *
     * Pointer comparisons are particularly useful when:

     * - Iterating through arrays: You can compare pointers to determine if you've reached the end of an array.
     * - Sub-array operations: Determine bounds and check for overlap.
     * - Memory management: Compare addresses for allocation and deallocation logic.
     */
    int comparisons[10];
    int *start = comparisons;
    int *end = comparisons + 10;

    while (start < end) {
        // Perform operations on the array
        *start = 0;  // Set each element to 0
        start++;
    }

    // Print the array to verify
    for (int i = 0; i < 10; i++) {
        printf("%d ", comparisons[i]);
    }
    printf("\n");
    printf("--------------------------------------------------------\n");

    /*
     * Important Considerations
     * Valid Range: Pointer comparisons are valid only within the same array or memory block.
     * Comparing pointers from different arrays or memory blocks is undefined behavior.
     *
     * Null Pointers: Comparing a pointer to NULL is valid and often used to check if a pointer is initialized
     * or has been allocated memory.
     *
     * Using these comparison operations allows for more flexible and dynamic memory manipulation,
     * crucial in systems programming and scenarios where performance and direct memory access are important.
     */
    int *ptrs = NULL;
    if (ptrs == NULL) {
        printf(" ptrs is not pointing to any memory location\n");
    }
    printf("\n");
    printf("--------------------------------------------------------\n");

    /*
     * int *pointer = &int_array[2]; sets pointer to point to the third element
     *  of int_array, which is 30.
     * The for loop iterates three times (0, 1, 2) and copies the addresses of
     * the last three elements of int_array (30, 40, 50) into p_array.
     * Each element of p_array is assigned the address of the corresponding
     * element in pointer. 
     * 
     * The test code checks if each element of p_array matches the address 
     * of the corresponding element in pointer,and prints "Matched!" 
     * if they match or "Fail" otherwise.
     * This code ensures that p_array correctly holds the addresses of
     * the last three elements of int_array.
     */
    int int_arrays[5] = {10, 20, 30, 40, 50};
    int *pointers = &int_arrays[2];  // pointer points to the third element (30)

    // Array of 3 pointers
    int *p_array[3];

    // Copy last three addresses of int_array into p_array
    // Use p_array and pointer

    for (i = 0; i < length; i++) {
        p_array[i] = &pointers[i];
    }

    // Test code
    for (i = 0; i < 3; i++) {
        if (p_array[i] == &pointers[i]) {
            printf("Matched!\n");
        } else {
            printf("Fail\n");
        }
    }
    printf("\n");
    printf("--------------------------------------------------------\n");

    return 0;
}
