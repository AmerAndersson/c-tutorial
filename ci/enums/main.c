#include <stdio.h>

/*
 * An enum is a special type that represents a group of constants (unchangeable values)
 * To create an enum, use the enum keyword, followed by the name of the enum,
 * and separate the enum items with a comma: Enum is short for "enumerations",
 *  which means "specifically listed
 * Enums are used to give names to constants, which makes the code easier to read and maintain.
 * Use enums when you have values that you know aren't going to change,
 *  like month days, days, colors, deck of cards, etc.
 */

// To create an enum LOW, MEDIUM or HIGH
enum Level
{
    LOW = 1,
    MEDIUM,
    HIGH
};
int main()
{
    // Create an enum variable and assign a value to it
    enum Level myVar = MEDIUM;

    // Print the enum variable
    printf("Medium: %d\n", myVar);

    // Enums are often used in switch statements to check for corresponding value
    switch (myVar)
    {
    case 1:
        printf("Low Level\n");
        break;
    case 2:
        printf("Medium level\n");
        break;
    case 3:
        printf("High level\n");
        break;
    default:
        printf("Your level does match");
    }

    return 0;
}