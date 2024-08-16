
/*
 * C structures are special, large variables which contain several named variables inside.
 * Structures are the basic foundation for objects and classes in C.
 *  Structures are used for:
 *
 * - Serialization of data
 * - Passing multiple arguments in and out of functions through a single argument
 * - Data structures such as linked lists, binary trees, and more
 */
#include <stdio.h>


#include "lib.h"

int main(int argc, const char *argv[]) {
    if (argc > 1) {
        printf("Hello %s!\n", argv[1]);
    } else {
        printf("No greeting for you");
    }
    printf("\n");

    // Calling function to print different struct values
    print_structs();

    return 0;
}
