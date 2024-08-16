#include <stdbool.h>  // Import the boolean header file
#include <stdio.h>

int main() {
  // Get the Memory Size

  int myInt;
  float myFloat;
  double myDouble;
  char myChar;
  // It is because the compiler expects the sizeof operator
  // to return a long unsigned int (%lu)
  printf("%lu\n", sizeof(myInt));
  printf("%lu\n", sizeof(myFloat));
  printf("%lu\n", sizeof(myDouble));
  printf("%lu\n", sizeof(myChar));
  printf("\n");

  /*
   *Implicit Conversion (automatically)
   * Explicit Conversion (manually)
   */

  // Automatic conversion: int to float
  float myFloati = 9;
  // assign an int value to a float type
  printf("%f\n", myFloati);  // 9.000000
  printf("---------------\n");

  // Automatic conversion: float to int
  int myInti = 9.99;

  printf("%d\n", myInti);  // 9
  printf("---------------\n");

  // Manual conversion: int to float
  float sum = (float)5 / 2;
  printf("%f\n", sum);  // 2.500000
  printf("---------------\n");

  int num1 = 5;
  int num2 = 2;
  float sums = (float)num1 / num2;

  printf("%.1f\n", sums);  // 2.500000
  printf("---------------\n");

  // Set the maximum possible score in the game to 500
  int maxScore = 500;

  // The actual score of the user
  int userScore = 420;

  /* Calculate the percantage of the user's score in relation to the maximum available score.
  Convert userScore to float to make sure that the division is accurate */
  float percentage = (float)userScore / maxScore * 100.0;

  // Print the percentage
  printf("User's percentage is %.2f\n", percentage);
  printf("---------------\n");

  // unchangeable and read-only
  const int minutesPerHour = 60;
  const float PI = 3.14;
  const int BIRTHYEAR = 1980;
  printf("%d\n", minutesPerHour);
  printf("%f\n", PI);
  printf("%d\n", BIRTHYEAR);
  printf("---------------\n");

  int sum1 = 100 + 50;     // 150 (100 + 50)
  int sum2 = sum1 + 250;   // 400 (150 + 250)
  int sum3 = sum2 + sum2;  // 800 (400 + 400)
  printf("%d\n", sum1);
  printf("%d\n", sum2);
  printf("%d\n", sum3);
  printf("---------------\n");

  // Create boolean variables
  bool isProgrammingFun = true;
  bool isFishTasty = false;
  bool isHamburgerTasty = true;
  ;

  // Return boolean values
  printf("%d\n", isProgrammingFun);  // Returns 1 (true)
  printf("%d\n", isFishTasty);       // Returns 0 (false)
  printf("---------------\n");

  int x = 10;
  int y = 9;
  printf("%d\n", x > y);
  printf("---------------\n");

  printf("%d\n", 10 == 10);  // Returns 1 (true), because 10 is equal to 10
  printf("%d\n", 10 == 15);  // Returns 0 (false), because 10 is not equal to 15
  printf("%d\n", 5 == 55);   // Returns 0 (false) because 5 is not equal to 55
  printf("%d\n", 10 > 9);    // Returns 1 (true) because 10 is greater than 9

  bool isPizzaTasty = true;
  // Find out if both hamburger and pizza is tasty
  printf("%d", isHamburgerTasty == isPizzaTasty);

  return 0;
}