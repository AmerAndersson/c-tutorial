#include <stdio.h>

/**
 * -------------------------------------------------------------------------------
 * Sometimes, you have to convert the value of one data type to another type. To get the right result
 * This is known as type conversion. There are two types of conversion in C:
 * Implicit Conversion(automatically) Explicit Conversion(manually)
 * Implicit conversion is done automatically by the compiler when assign an int value to a float type
 * ------------------------------------------------------------------------------
 */
int main(void) {
  // Automatic conversion: int to float
  float myFloat = 9;
  printf("Automatic conversion int to float:  %f\n", myFloat);
  printf("\n");

  // Explicit conversion is done manually by the programmer
  // when assign an int value to a float type. Manual conversion: int to float
  int num1 = 5;
  int num2 = 2;
  float sum = (float)num1 / num2;                           //  place the type in front of a variable
  printf("Explicit conversion int to float: %.1f\n", sum);  // 2.500000, removing the extra zeros 2.50

  // Manual conversion: int to float
  float total = (float)5 / 2;
  printf("Explicit conversion int to float: %.1f", total);  // 2.500000
  printf("\n");

  /**
   * A real-life of data types and type conversion where
   * we create a program to calculate the percentage of a
   * user's score in relation to the maximum score in a game
   */

  // Set the maximum possible score in the game to 500
  int maxScore = 500;
  // The actual score of the user
  int userScore = 423;

  // Calculate the percentage of the user's score in relation to the maximum available score.
  // Convert userScore to float to make sure that the division is accurate

  float percentage = (float)userScore / maxScore * 100.0;

  // Print the percentage
  printf("User's percentage is %.2f\n", percentage);

  return 0;
}
