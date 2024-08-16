/*
 Basic Array Access
 When you declare an array in C, you can access its elements
 using the array index notation. This is essentially a form of dereferencing.

Key Points to Remember
Array and Pointer Relationship: The name of the array is a constant pointer to the first element of the array.

Dereferencing: Using * to access the value at a particular address.
Pointer Arithmetic: You can move the pointer to different elements using arithmetic operations.
Using [] with Pointers: The [] operator works with pointers as well as with array names.

And since arrays are actually pointers, accessing the first item in the array is the same as dereferencing a pointer. Dereferencing a pointer is done using the asterisk operator *.
*/
#include <stdio.h>

int main(void) {
    // Basic Array Access
    int array[5] = {10, 20, 30, 40, 50};
    int value = array[2];  // Access the third element, value is 30
    printf("Access the third element[2]: %d\n", value);
    printf("\n");

    /*
     * Using Pointers with Arrays
     * use pointers to access elements of an array.
     * The array name itself acts as a pointer to the first element.
     */

    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // ptr is pointing to the first element of the array

    // Accessing elements using array index notation
    printf("Using array index notation: %d\n", arr[0]);  // Outputs 10
        // Accessing elements using array index notation
    printf("Using array index notation: %d\n", arr[1]);  // Outputs 20

    // Accessing elements using pointer dereferencing
    printf("Using pointer dereferencing: %d\n", *(ptr + 2));  // Outputs 30

    // Iterating through the array using pointers
    printf("Iterating through array using pointers: ");
    int i;
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < length; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // Using pointer arithmetic
    ptr++;   // Move to the next element
    printf("After pointer arithmetic, ptr++ points to: %d\n", *ptr);  // Outputs 20

    // Accessing array elements using [1] with pointers
    printf("Using [1] with pointers: %d\n", ptr[1]);  // Outputs 30, since ptr points to the second element now

    return 0;
}