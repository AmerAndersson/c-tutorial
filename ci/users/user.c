#include <stdio.h>

int main() {
  // fgets() function to read a line of text.
  // arguments: sizeof(string_name), and stdin
  char fullNames[30];

  printf("Type your full name: \n");
  fgets(fullNames, sizeof(fullNames), stdin);
  printf("Hello %s", fullNames);

  // User Input scanf() and  it can only display a single word
  // Create an integer variable that will store the number we get from the user
  int myNum;

  // Ask the user to type a number
  printf("Type a number:\n");
  // Get and save the number the user types
  scanf("%d", &myNum);  // the reference operator (&myNum)
  // Output the number the user typed
  printf("Your number is: %d\n", myNum);

  // Multiple Inputs
  // Create an int and a char variable
  int myNums;
  char myChar;

  // Ask the user to type a number AND a character
  printf("Type a number AND a character and press enter: \n");
  // Get and save the number AND character the user types
  scanf("%d %c", &myNums, &myChar);
  // Print the number
  printf("Your number is: %d\n", myNums);
  // Print the character
  printf("Your character is: %c\n", myChar);

  // get a string entered by the user:
  // create a string
  char firstName[30];

  // Ask the user to input some text
  printf("Enter your first name: \n");
  // Get and save the text
  scanf("%s", firstName);
  // Output the text
  printf("Hello %s\n", firstName);

  return 0;
}