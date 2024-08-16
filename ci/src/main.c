
#include <stdio.h>

int main(void) {
  // Here's a real-life example of using different data types,
  // to calculate and output the total cost of a number of items:
  int items = 50;
  float cost_per_item = 9.99;
  float total_cost = items * cost_per_item;
  char currency = '$';

  // Print variables
  printf("Number of items: %d\n", items);
  printf("Cost per item: %.2f%c\n", cost_per_item, currency);
  printf("Total cost = %.2f%c\n", total_cost, currency);

  return 0;
}
