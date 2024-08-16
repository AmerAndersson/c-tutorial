
#include <stdio.h>
// Function to return the only odd  occurring element
int findOdd(int arr[], int n);

int main(void) {
  //  Arrays are used to store multiple values in a single variable,
  //  instead of declaring separate variables for each value.

  int myNumbers[] = {20, 40, 35, 90};
  // To access an array element, refer to its index number.
  printf("The first: %d\n", myNumbers[0]);

  myNumbers[0] = 33;
  // To access an array element, refer to its index number.
  printf("New value: %d\n", myNumbers[0]);
  printf("\n");

  // By using the sizeof formula we can now make loops that work for arrays of any size,
  // which is more sustainable and making better Loops
  int lengths = sizeof(myNumbers) / sizeof(myNumbers[0]);
  int i;

  for (i = 0; i < lengths; i++) {
    printf("%d\n", myNumbers[i]);
  }
  printf("\n");

  // Declare an array of four integers and set the size of the array, and add element.
  // Using this method, you should know the number of array elements in advance,
  // in order for the program to store enough memory.
  int myNumber[4];
  myNumber[0] = 25;
  myNumber[1] = 50;
  myNumber[2] = 75;
  myNumber[3] = 100;

  printf("The first elements in an array: %d\n", myNumber[0]);
  printf("The second elements in an array: %d\n", myNumber[1]);
  printf("The third elements in an array: %d\n", myNumber[2]);
  printf("\n");

  // Get the size of an array using the sizeof operator.
  // It is because the sizeof operator returns the size of a type in bytes: 20
  // int type is usually 4 bytes, 4 x 5 (4 bytes x 5 elements) = 20 bytes.
  // 20 bytes is memory size of an array.
  int myNum[] = {10, 25, 50, 75, 100};
  printf("Get the size of an array in bytes: %lu\n", sizeof(myNum));

  // When you just want to find out how many elements an array has, you can use the
  // following formula (which divides the size of the array by the size of one array element):
  int length = sizeof(myNum) / sizeof(myNum[0]);
  printf("Find out how many elements an array has: %d\n", length);
  // Prints 5

  // C program to find odd occurring elements in an array
  int arr[] = {12, 12, 14, 90, 14, 14, 14};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("The odd occurring element is %d ",
         findOdd(arr, n));
  return 0;
}

// Function to return the only odd  occurring element
int findOdd(int arr[], int n) {
  int res = 0, i;
  for (i = 0; i < n; i++)
    res ^= arr[i];
  return res;
}