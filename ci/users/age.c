
#include <stdio.h>

int main() {
  // Old enough to vote!" if myAge is greater than or equal to 18.
  // Otherwise output "Not old enough to vote.":
  int age = 25;
  int voting = 18;

  if (age >= voting) {
    printf("Old enough to vote!\n");
  } else {
    printf("Not old enough to vote.\n");
  }

  // The if Statement
  if (20 > 18) {
    printf("20 is greater than 18\n");
  }

  int x = 20;
  int y = 18;
  if (x > y) {
    printf("x is greater than y\n");
  }

  // The if-else Statement
  int time = 20;
  if (time < 18) {
    printf("Good day.\n");
  } else {
    printf("Good evening.\n");
  }

  // The else if Statement
  int times = 22;
  if (times < 10) {
    printf("Good morning.\n");
  } else if (times < 20) {
    printf("Good day.\n");
  } else {
    printf("Good evening.\n");
  }

  // Short Hand If Else
  int shortTime = 20;
  (shortTime < 18) ? printf("Good day.\n") : printf("Good evening.\n");

  int doorCode = 1337;

  if (doorCode == 1337) {
    printf("Correct code. The door is now open.\n");
  } else {
    printf("Wrong code. The door remains closed.\n");
  }

  // Is this a positive or negative number?
  int num = 10;

  if (num > 0) {
    printf("The value is a positive number.\n");
  } else if (num < 0) {
    printf("The value is a negative number.\n");
  } else {
    printf("The value is 0.\n");
  }

  int nums = 5;

  if (nums % 2 == 0) {
    printf("%d is even.\n", nums);
  } else {
    printf("%d is odd.\n", nums);
  }

  return 0;
}