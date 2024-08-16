#include <stdio.h>

int main(void) {
  /**
  Assuming that the compiler creates the variable at the address 1000
  and "x" at the address 2000, then the address of "a" is stored in "x".
  Use the reference operator (&), to access it a memory address is in hexadecimal form (0x..).
  */
  int var = 100;

  // Outputs the value of var (100)
  printf("var: %d\n", var);
  // Outputs the memory address of var (0x7ff7b98205c8)
  printf("Access a memory address: %p\n", (void*)&var);
  printf("\n");

  // Create a pointer variable with the name ptr, that points to an int variable (age)
  // Use the & reference operator to store the memory address of the myAge variable, and assign
  // it to the pointer. Now, ptr holds the value of age's memory address.
  int age = 43;  // An int variable
  int* ptr = &age;

  // Output the value of age (43)
  printf("The value of age: %d\n", age);
  // Output the memory address of age (0x7ff7b19175c4)
  printf("Access a memory address: %p\n", (void*)&age);
  // Output the memory address of age with the pointer (0x7ff7b19175c4)
  printf("Reference memory address: %p\n", (void*)ptr);
  printf("\n");

  // Get the value of the variable the pointer points to,
  // by using the * operator (the dereference operator):
  int myAge = 43;      // Variable declaration
  int* ptrs = &myAge;  // Pointer declaration

  // Reference: Output the memory address of myAge with the pointer (0x7ffe5367e044)
  printf("Reference memory address: %p\n", (void*)ptrs);
  // Dereference: Output the value of myAge with the pointer (43)
  printf("Dereference: %d\n", *ptrs);

  return 0;
}
