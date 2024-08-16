#include <stdio.h>

int main() {
  // calculate speed and time
  int speed = 0;
  int time = 0;

  // user enter speed
  printf("Enter speed: ");
  scanf("%d", &speed);

  // user enter time
  printf("Enter time: ");
  scanf("%d", &time);

  // print out the distance
  printf("Distance: %d\n", speed * time);
  return 0;
}