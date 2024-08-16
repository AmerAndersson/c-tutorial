/*
 * C Unions are essentially the same as C Structures,
 * except that instead of containing multiple variables each with
 * their own memory a Union allows for multiple names to the same variable.
 * These names can treat the memory as different
 * types (and the size of the union will be the size of the largest type, + any
 * padding the compiler might decide to give it)
 * A union in C is a data structure that allows you to store different data types in the same memory location.
 */

#include <stdbool.h>
#include <stdio.h>

/*
 * To read a variable's memory in different ways, and read an integer one byte at a time.
 * In this case, the union contains an int named theInt and a char array named bytes
 * with the size equal to that of an int.
 * Both theInt and bytes share the same memory location.
 * This allows you to access the same data as an integer or
 * as individual bytes.
 */

/* Defines a union named intParts: */
union intParts {
    int theInt;
    char bytes[sizeof(int)];
};

/*
 * Combining this with a structure allows you to create a "tagged" union
 * which can be used to store multiple different types, one at a time.
 * Because your program has a lot of them and it takes a bit too much memory
 * for all of the variables.
 *
 * Like this the size of the struct is just the size of the int type + the size of the largest * type in the union (the
 * double). Not a huge gain, only 8 or 16 bytes, but the concept can be applied to
 * similar  structs.
 */
struct Operator {
    int type;
    union {
        int intNum;
        float floatNum;
        double doubleNum;
    };  // an anonymous union, members are on the outer container
};
/*
 * Another, perhaps more useful feature, is when you always
 * have multiple variables of the same type, and you want to be
 * able to use both names (for readability) and indexes (for ease of iteration).
 * A struct which contains the four (common) coins in the United States.
 */
union Coins {
    struct {
        int quarter;
        int dime;
        int nickel;
        int penny;
    };  // anonymous struct acts the same way as an anonymous union, members are on the outer container
    int coins[4];
};

// Input Validation Function: Added a getInput function
// to handle input and check if each value is successfully read as an integer.
bool getInput(int* arr, size_t size);

int main(void) {
    /*
     * Assigning and Printing Using the Union and
     * initializes an instance of the union and sets the integer value:
     * It allows to look at each byte individually without casting
     * a pointer and using pointer arithmetic:
     */
    union intParts parts;
    parts.theInt = 5968145;  // arbitrary number > 255 (1 byte)

    // prints the integer and its individual bytes:
    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n", parts.theInt, parts.bytes[0], parts.bytes[1],
           parts.bytes[2], parts.bytes[3]);

    /* vs
     * Pointer Casting Method
     * The code then demonstrates an alternative method of accessing
     * the individual bytes by casting a pointer:
     *
     *   theInt is assigned the value of parts.theInt.
         (char*)&theInt casts the address of theInt to a char*,
         effectively treating the integer as a series of bytes.
         *((char*)&theInt + 0), *((char*)&theInt + 1), *((char*)&theInt + 2), and
         *((char*)&theInt + 3) access the individual bytes by offsetting the char* pointer.
     */
    int theInt = parts.theInt;
    printf("Int is %i\nThe bytes are [%i, %i, %i, %i]\n", theInt, *((char*)&theInt + 0), *((char*)&theInt + 1),
           *((char*)&theInt + 2), *((char*)&theInt + 3));

    /*
     * or with array syntax which can be a tiny bit nicer sometimes
     * Array Syntax Method shows another way to access the bytes using array syntax
     * ((char*)&theInt)[0], ((char*)&theInt)[1], ((char*)&theInt)[2], and
     * ((char*)&theInt)[3] access the bytes using array indexing.
     */
    printf("Int is %i\nThe bytes are [%i, %i, %i, %i]\n", theInt, ((char*)&theInt)[0], ((char*)&theInt)[1],
           ((char*)&theInt)[2], ((char*)&theInt)[3]);
    printf("\n");

    // intNum is part of the union,
    // but since it's not named you access it directly off the struct itself
    struct Operator op;
    op.type = 0;      // int
    op.intNum = 352;  // intNum is part of the union
    printf("%i %i\n", op.type, op.intNum);
    printf("\n");

    /*
     * since the union makes the variables share the same memory
     * the coins array matches with * each int in the struct (in order).
     *
     * comparing an int with an unsigned long in the for loop condition.
     * The sizeof operator returns a value of type
     * size_t, which is an unsigned type, while int is a signed type
     *
     * Cast the sizeof value to an int.
     * Use size_t for the loop variable.
     */
    union Coins change;

    /* Prompt Message: Prompt the user to enter the number of each type of*/
    printf("Enter the number of quarters, dimes, nickels, and pennies:\n");

    // Validation Check in main: The main function calls getInput and checks its return value.
    // If getInput returns false, the program exits with a non-zero status, indicating an error
    if (!getInput(change.coins, sizeof(change.coins) / sizeof(int))) {
        return 1;  // Exit if input is invalid
    }
    printf("There are %i quarters, %i dimes, %i nickels, and %i pennies\n", change.quarter, change.dime, change.nickel,
           change.penny);
    return 0;
}
// Input Validation Function: Added a getInput function
// to handle input and check if each value is successfully read as an integer.
bool getInput(int* arr, size_t size) {
    // If scanf does not successfully read an integer (!= 1),
    // the function prints an error message and returns false.
    for (size_t i = 0; i < size; ++i) {
        if (scanf("%i", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return false;
        }
    }
    return true;
}
