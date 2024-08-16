#include <stdio.h>
#include <string.h>

// String Functions

// Function declaration
void myFunction(char name[], int age);
// Function declaration Pass Arrays as Function Parameters
void myArrays(int myArr[5]);
// Function declaration Return Values
int returnValue(int x, int y);
// Function declaration, to convert Fahrenheit to Celsius
float toCelsius(float fahrenheit);
// Function definition Recursion
int sum(int k);

int main() {
  // get the length of a string strlen()
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  printf("%lu\n", strlen(alphabet));  // 26
  printf("%lu\n", sizeof(alphabet));  // 27 as sizeof also includes the \0 character when counting
  printf("---------------\n");

  char alphabets[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  printf("%lu\n", strlen(alphabets));  // 26
  printf("%lu\n", sizeof(alphabets));  // 50 sizeof will always return the memory size (in bytes)
  printf("---------------\n");

  // Concatenate Strings using  strcat()
  char str1[20] = "Hello ";
  char str2[] = "World!";
  // Concatenate str2 to str1 (result is stored in str1)
  strcat(str1, str2);
  // Print str1
  printf("%s\n", str1);

  // Copy Strings
  char str11[20] = "Hello World!";
  char str22[20];

  // Copy str11 to str22
  strcpy(str22, str11);

  // Print str22
  printf("%s\n", str22);

  // Compare Strings strcmp()
  // It returns 0 if the two strings are equal, otherwise a value that is not 0:
  char str4[30] = "Hello";
  char str5[30] = "Hello";
  char str6[] = "Hi";

  // Compare str4 and str5, and print the result
  printf("%d\n", strcmp(str4, str5));  // Returns 0 (the strings are equal)

  // Compare str1 and str6, and print the result
  printf("%d\n", strcmp(str4, str6));  // Returns -4 (the strings are not equal)
  printf("---------------\n");

  // call the myFunction
  myFunction("Liam", 3);
  myFunction("Jenny", 14);
  myFunction("Anja", 30);
  printf("---------------\n");

  int myArr[5] = {10, 20, 30, 40, 50};
  myArrays(myArr);
  printf("---------------\n");
  // return value
  int result = returnValue(5, 3);
  printf("Result is: %d\n", result);
  printf("---------------\n");

  // Set a fahrenheit value
  float fahrenheit = 98.8;
  // Call the function with the fahrenheit value
  float results = toCelsius(fahrenheit);
  // Print the fahrenheit value
  printf("Fahrenheit: %.2f\n", fahrenheit);
  // Print the result
  printf("Convert Fahrenheit to Celsius: %.2f\n", results);

  int total = sum(10);
  printf("Total: %d", total);

  return 0;
}

// Function definition takes name, age as parameters
void myFunction(char name[], int age) {
  printf("Hello %s. You are %d years old.\n", name, age);
}

// Function definition Pass Arrays as Function Parameters
void myArrays(int myArr[5]) {
  for (int i = 0; i < 5; i++) {
    printf("%d\n", myArr[i]);
  }
}

// Function definition Return Values
int returnValue(int x, int y) {
  return x + y;
}

// Function definition to convert Fahrenheit to Celsius
float toCelsius(float fahrenheit) {
  return (5.0 / 9.0) * (fahrenheit - 32.0);
}

/*
 * Function definition Recursion
 * 10 + sum(9)
 * 10 + ( 9 + sum(8) )
 * 10 + ( 9 + ( 8 + sum(7) ) )
 * ...
 * 10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + sum(0)
 * 10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + 0
 */
int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);
  } else {
    return 0;
  }
}