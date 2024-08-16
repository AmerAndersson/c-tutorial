/**
 * Function arguments by reference
Function arguments are passed by value, by which means they are copied in and out of functions.

But what if we pass pointers to values instead of the values themselves? This will allow us to give functions control over the variables and structures of the parent functions and not just a copy of them, thus directly reading and writing the original object.
 */
#include <stdio.h>
#include "reference.h"

// Main Function:
int main(void) {
    int param = 1;
    printf("Before: %d\n", param);
    // receives a pointer to the param as an argument,
    // and pass by reference.
    // Calling the add_one() Function:
    // Passes the address of param to the add_one() Function.
    // This allows the Function to modify the original ps variable directly.
    add_one(&param);
    printf("After: %d\n", param);
    printf("\n");

    // Declare a variable ps of type Point and
    // initializes it with x = 1 and y = 1
    Point ps = {0, 0};

    // Before Move: Prints the initial coordinates of the point.
    printf("Before move: x = %d, y = %d\n", ps.x, ps.y);

    // Calling the Move Function
    // Passes the address of ps to the Move Function.
    // This allows the Function to modify the original ps variable directly.
    move(&ps);

    // Prints the coordinates of the point after calling the move function.
    printf("After move: x = %d, y = %d\n", ps.x, ps.y);
    printf("\n");

    // Declare a variable ps of type john
    // Initializes a person named john with an age of 27.
    Person john;
    john.name = "John";
    john.age = 27;

    // Print John's current age.
    printf("%s is %d years old.\n", john.name, john.age);
    birthday(&john);  // calling the birthday() passing the address of john.
    // Print John's new age after the birthday() has incremented it.
    printf("Happy birthday! %s is now %d years old.\n", john.name, john.age);
    return 0;
}
