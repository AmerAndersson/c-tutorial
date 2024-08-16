#include <stdio.h>

enum Level
{
    LOW,
    MEDIUM,
    HIGH
};

enum LevelS
{
    LOWS = 25,
    MEDIUMS = 50,
    HIGHS = 75
};

int main()
{
    // Create an enum variable and assign a value to it
    enum Level myVal = MEDIUM;

    // Print the enum variable
    printf("%d\n", myVal);

    // Create an enum variable and assign a value to it
    enum LevelS myVar = LOWS;

    printf("%d", myVar);

    return 0;
}