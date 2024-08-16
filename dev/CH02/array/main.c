#include <stdio.h>

void print_array(const int arr[], int size);
int get_length(const char s[]);

int main(void) {
    // call this function and pass a character array (string) to it:
    const char myString[20] = "Hello, World";
    int len = get_length(myString);
    printf("Length of the string is: %d\n", len);
    printf("\n");

    const int myArray[5] = {1, 2, 3, 4, 5};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    print_array(myArray, size);
    return 0;
}

int get_length(const char s[]) {
    int length = 0;
    // Iterate through the array until the null terminator is found
    while (s[length] != '\0') {
        length++;
    }
    return length;  // Return the length of the string
}
// printArray takes an integer array and its size,
// and prints the elements of the array.
void print_array(const int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
