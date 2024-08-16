/*
* Pointers are also variables and play a very important role in C programming language.
* They are used for several reasons, such as:

*  - Strings
*  - Dynamic memory allocation
*  - Sending function arguments by reference
*  - Building complicated data structures
*  - Pointing to functions
*  - Building special data structures (i.e. Tree, Tries, etc...)

   - What is a pointer?
* A pointer is essentially a simple integer variable which holds a
* memory address that points to a value, instead of holding the actual value itself.

* The computer's memory is a sequential store of data, and a pointer points to a
* specific part of the memory. Our program can use pointers in such a way that
* the pointers point to a large amount of memory - depending on how much we decide
* to read from that point on.

   - Strings as pointers
* We've already discussed strings, but now we can dive in a bit deeper and understand what * strings in C really are (which are called C-Strings to differentiate them from
* other strings when mixed with C++)
*/
#include <stdio.h>
#include <string.h>

int main(void) {
    /**
     * Key Points:
     * String Literals: When assigned to a char*,
     * they are stored in read-only memory.
     *
     * Modifiable Strings: Use a char array if you need to change the string.
     */

    // Using a read-only string literal
    const char* name = "John";

    // Demonstrating string operations
    printf("Name (read-only): %s\n", name);

    // If you need a modifiable string,
    // an array of characters that can be modified.
    char name_modifiable[] = "John";

    printf("Name (modifiable): %s\n", name_modifiable);
    printf("First character[0]: %c\n", name_modifiable[0]);
    printf("Second character[1]: %c\n", name_modifiable[1]);

    // Modifying the string
    name_modifiable[0] = 'J';
    name_modifiable[1] = 'a';
    name_modifiable[2] = 'c';
    name_modifiable[3] = 'k';
    name_modifiable[4] = '\0';  // Ensure null-termination

    printf("Modified name: %s\n", name_modifiable);

    int length = sizeof(name_modifiable) / sizeof(name_modifiable[0]);
    int i;

    for (i = 0; i < length; ++i) {
        printf("%c ", name_modifiable[i]);
    }
    printf("\n");

    // They both have 13 characters (space also counts as a character by the way), including the \0 character:
    char greetings[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
    char greetings2[] = "Hello World!";

    printf("%s\n", greetings);
    printf("%lu\n", sizeof(greetings));
    printf("%lu\n", sizeof(greetings));
    printf("\n");

    // welcome message:
    char message[] = "Good to see you,";
    char fname[] = "John";
    printf("%s %s!\n", message, fname);
    printf("\n");

    /**
     we used sizeof to get the size of a string/array.
     Note that sizeof and strlen behaves differently,
     as sizeof also includes the \0 character when counting:
     */
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("Length is: %lu\n", strlen(alphabet));  // 26
    printf("Size is: %lu\n", sizeof(alphabet));    // 27

    /**
     * It is also important that you know that sizeof will always return the memory size (in bytes), and not the actual string length:
     */
    char alphabets[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("Length is: %zu\n", strlen(alphabets));  // 26
    printf("Size is: %zu\n", sizeof(alphabets));    // 50
    printf("\n");

    // define a local variable x in our stack,
    int x = 1;

    // define a pointer variable, and point it to x using the & operator
    int* ptr_to_x = &x;

    printf("The value x is:\n");
    printf("The value x is %d\n", x);
    printf("The value of x is also %d\n", *ptr_to_x);
    printf("\n");

    printf("The memory address:\n");
    printf("The memory address of x is %p\n", &x);
    printf("The memory address of x is %p\n", ptr_to_x);
    printf("\n");

    printf("size of single pointer:\n");
    printf("Size of normal Pointer: %lu\n", sizeof(x));
    printf("Size of normal Pointer: %lu\n", sizeof(ptr_to_x));
    printf("\n");

    // let's change the variable x
    x++;

    // we just changed the variable again!
    (*ptr_to_x)++;

    // will print out 3
    printf("The value of a is now %d\n", x);
    printf("The value of a is now %d\n", *ptr_to_x);
    printf("\n");

    // define a local variable x in our stack,
    int n = 10;

    // pointer_to_n, and use it to increase the value of n by one:
    int* pointer_to_n = &n;
    (*pointer_to_n)++;

    /* testing code */
    if (pointer_to_n != &n) {
        return 1;
    }
    if (*pointer_to_n != 11) {
        return 1;
    }

    printf("Done!\n");
    printf("\n");

    int arr[5] = {1, 2, 3, 4, 5};
    int* b = arr;

    printf("Address of a[0]: %d value at a[0] : %d\n", b, *b);

    b++;
    printf("Address of a[1]: %d value at a[1] : %d\n", b, *b);

    b++;
    printf("Address of a[2]: %d value at a[2] : %d\n", b, *b);

    b++;
    printf("Address of a[3]: %d value at a[3] : %d\n", b, *b);

    b++;
    printf("Address of a[4]: %d value at a[4] : %d\n", b, *b);

    return 0;
}
