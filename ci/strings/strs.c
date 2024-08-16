#include <stdio.h>

int main(void) {
  // Strings
  char firstName[] = "John Smith";
  printf("UserName is: %s\n", firstName);
  printf("\n");

  // "Hello World" is a string of characters.
  char greetings[] = "Hello World!";
  printf("Greeting: %s\n", greetings);

  // Access Strings first character (0) in greetings:
  printf("Single character H: %c\n", greetings[0]);  // H

  // Modify Strings
  greetings[0] = 'J';
  printf("%s\n", greetings);
  printf("\n");

  // Loop Through a String
  char carName[] = "Volvo";  // including the \0 character
  int length = sizeof(carName) / sizeof(carName[0]);

  for (int i = 0; i < length; ++i) {
    if (carName[i]) {
      printf("%c\n", carName[i]);
    }
  }
  printf("\n");

  // "string literal" to create a string variable. This is the easiest way to create a string in C.
  char greeting[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
  printf("%s\n", greeting);
  printf("\n");

  char greet[] = "Hello World!";  // including the \0 character:

  printf("%lu\n", sizeof(greet));     // Outputs 13 characters
  printf("%lu\n", sizeof(greeting));  // Outputs 13 characters
  printf("\n");

  // The sequence (\\) inserts a single backslash in a string:
  char singleBackslash[] = "The character \\ is called backslash.";
  printf("%s\n", singleBackslash);
  printf("\n");

  // The sequence (\') inserts a single quote in a string:
  char singleQuote[] = "It\'s alright.";
  printf("%s\n", singleQuote);
  printf("\n");

  // The sequence \"  inserts a double quote in a string:
  char doubleQuote[] = "We are the so-called \"Vikings\" from the north.";
  printf("%s\n", doubleQuote);
  printf("\n");

  // The sequence (\t) inserts a tab in a string:
  char tab[] = "Hello\tWorld!";
  printf("%s\n", tab);
  printf("\n");

  // The sequence (\0) inserts a "null terminating character" in a string:
  char characterEnd[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  printf("%s\n", characterEnd);
  printf("\n");

  // Real-Life
  // Use strings to create a simple welcome message :
  char message[] = "Good to see you,";
  char fname[] = "John Doe";

  printf("%s %s!\n", message, fname);
  return 0;
}
