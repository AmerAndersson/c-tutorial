#include <stdio.h>
/**
 * Create a union that stores an array of 21 characters
 * and 6 ints (6 since 21 / 4 == 5, but 5 * 4 == 20 so you need 1
 * more for the purpose of this exercise), you will set the integers to 6 given values
 * and then print out the character array both as a series of chars and as a string
 *
 * Explanation:
 * The union IntCharUnion is defined as before with chars and ints arrays.
 * Initialization: We manually assign the integer values to the ints array of
 * the union. This  avoids the narrowing
 * conversion error. Printing Characters: The same code is used to print the
 * characters and the string, ensuring we see the expected result.
 *
 * Output:
 * When you run this code, the output will be similar to before,
 * showing both the individual *characters and the whole
 * string stored in the union. The exact characters printed will
 * reflect the memory *representation of the given integers as characters.
 */
union IntCharUnion {
    char chars[21];
    int ints[6];
};

int main(void) {
    // initializer lists like this are assigned to the first member of the union/struct!
    union IntCharUnion intCharacters;

    // Assign values to the first member of the union ints array
    // There are 6 ints
    intCharacters.ints[0] = 1853169737;
    intCharacters.ints[1] = 1936876900;
    intCharacters.ints[2] = 1684955508;
    intCharacters.ints[3] = 1768838432;
    intCharacters.ints[4] = 561213039;
    intCharacters.ints[5] = 0;  // Ensure null-terminated string

    /* testing code */
    printf("[");
    // Only go to 18 because 1 byte is for the terminating 0 and we don't 
    // print the last in the loop.
    // Print out the character array as individual characters and as a string.
    for (int i = 0; i < 19; ++i) printf("%c, ", intCharacters.chars[i]);
    printf("%c]\n", intCharacters.chars[19]);

    printf("%s\n", intCharacters.chars);

    return 0;
}
