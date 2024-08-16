#include <stdio.h>

// Define any macros or constants
// that will be used throughout the program.
#define PI 3.14159

// Function declaration
void calculateRadius();

int main() {
  // Call calculate func
  calculateRadius();
  return 0;
}

// Function definition & implementation
void calculateRadius() {
  float radius = 5.0;
  float area = PI * radius * radius;
  printf("Area of the circle: %f\n", area);  // TODO %.3f
}