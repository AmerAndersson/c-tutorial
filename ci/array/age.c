#include <stdio.h>

int main(void) {
  // Create a program with storage of an array
  // that calculates the average of different ages:
  int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};

  float avg, sum = 0;
  int i;

  // Get the length of the array
  int length = sizeof(ages) / sizeof(ages[0]);

  // Loop through the elements of the array and accumulate the sum
  for (i = 0; i < length; i++) {
    sum += ages[i];
  }

  // Calculate the average by dividing the sum by the length
  avg = sum / length;

  // Print the average
  printf("The average age is: %.2f", avg);
  printf("\n");

  // Finds the lowest age among different ages:

  // Get the length of the array
  int theLength = sizeof(ages) / sizeof(ages[0]);

  //  Create a 'lowest age' and assign the first array element of ages to it
  int lowestAge = ages[0];

  // Loop through the elements of the ages array to find the lowest age
  for (i = 0; i < theLength; i++) {
    // Check if the current age is smaller than current the 'lowest age'
    if (lowestAge > ages[i]) {
      // If the smaller age is found, update 'lowest age' with that element
      lowestAge = ages[i];
    }
  }

  // Output the value of the lowest age
  printf("The lowest age in the array is: %d\n", lowestAge);

  return 0;
}
