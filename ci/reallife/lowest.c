#include <stdio.h>
#include <string.h>

int main()
{
    // Create a program that finds the lowest age among different ages:
    // An array storing different ages
    int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};

    // Get the length of the array
    int length = sizeof(ages) / sizeof(ages[0]);

    // Create a 'lowest age' variable and assign the first array element of ages to it
    int lowestAge = ages[0];

    // Loop through the elements of the ages array to find the lowest age
    for (int i = 0; i < length; i++)
    {

        // Check if the current age is smaller than current the 'lowest age'
        if (lowestAge > ages[i])
        {

            // If the smaller age is found, update 'lowest age' with that element
            lowestAge = ages[i];
        }
    }

    // Output the value of the lowest age
    printf("The lowest age in the array is: %d\n", lowestAge);
    printf("----------------------------\n");

    char message[] = "Good to see you,";
    char fname[] = "John";

    printf("%s %s!\n", message, fname);
    printf("----------------------------\n");

    int number = 2;
    // Print the multiplication table for the number 2
    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", number, i, number * i);
    }
    printf("----------------------------\n");

    int v;

    for (v = 0; v <= 10; v = v + 2)
    {
        printf("%d\n", v);
    }
    printf("----------------------------\n");
    for (int c = 0; c <= 100; c += 10)
    {
        printf("%d\n", c);
    }
    printf("----------------------------\n");
    // Create a program that counts the number of characters found in a specific word:
    char word[] = "Computer";
    printf("The word '%s' has %lu characters in it.\n", word, strlen(word));
    printf("----------------------------\n");
    // Create a string
    char fullName[30];

    // Ask the user to input some text (full name)
    printf("Type your full name and press enter:\n");

    // Get the text
    fgets(fullName, sizeof(fullName), stdin);

    // Output the text
    printf("Hello %s", fullName);
    return 0;
}