#include <stdio.h>

int main() {
  int var = 2;
  printf("var * 2  = %d \n", var << 1);  // 1 position to the left
  printf("var * 4  = %d \n", var << 2);  // 2 position to the left
  printf("var * 8  = %d \n", var << 3);  // 3 position to the left
  printf("var * 16 = %d \n", var << 4);  // 4 position to the left
  printf("var * 32 = %d \n", var << 5);  // 5 position to the left

  return 0;
}