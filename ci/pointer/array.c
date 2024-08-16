#include <stdio.h>

int main(void) {
  // You can also use pointers to access arrays.

  // Pointers & Arrays
  int myNumbers[4] = {25, 50, 75, 100};
  for (int i = 0; i < 4; i++) {
    printf("Access a memory address: %p\n", (void *)&myNumbers[i]);
    // Output the memory address of myNumbers
  }
  printf("\n");

  // Create an int variable
  // The size of an int type is typically 4 bytes
  int myInt;
  // Get the memory size of an int
  printf("Bytes: %lu\n", sizeof(myInt));

  // The entire array takes up 16 bytes (4 * 4) of memory storage
  int myNumber[4] = {25, 50, 75, 100};
  // Get the size of the myNumbers array
  printf("Bytes: %lu\n", sizeof(myNumber));
  printf("\n");

  // The memory address of the first element is the same as the name of the array:
  int myNum[5] = {25, 50, 75, 80, 100};
  // Get the memory address of the myNum array
  printf("Access a memory address: %p\n", (void *)myNum);
  // Get the memory address of the first array element
  printf("Access a memory address: %p\n", (void *)&myNum[0]);
  printf("\n");

  // Get the value of the first element in myNum
  printf("Value of the first element: %d\n", *myNum);
  // To access the rest of the elements in myNumbers,
  // you can increment the pointer/array (+1, +2, etc):
  // Get the value of the second element in myNumbers
  printf("Value of the second element: %d\n", *(myNum + 1));
  // Get the value of the third element in myNumbers
  printf("Value of the third element: %d\n", *(myNum + 2));
  // Get the value of the four element in myNumbers
  printf("Value of the four element: %d\n", *(myNum + 3));
  // Get the value of the five element in myNumbers
  printf("Value of the five element: %d\n", *(myNum + 4));
  printf("\n");

  // loop through it:
  int myNums[5] = {25, 50, 75, 80, 100};
  int *pointer = myNums;
  int a;

  for (a = 0; a < 4; a++) {
    printf("%d\n", *(pointer + a));
  }
  printf("\n");

  // It is also possible to change the value of array elements with pointers:
  // Change the value of the first element to 13
  *myNums = 13;

  // Change the value of the second element to 17
  *(myNums + 1) = 17;

  // Get the value of the first element
  printf("%d\n", *myNums);

  // Get the value of the second element
  printf("%d\n", *(myNums + 1));
  printf("\n");
  return 0;
}
