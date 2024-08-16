/*
 * Both int main(int argc, char *argv[])
 * and int main(int argc, char **argv)
 * mean the same in terms of how they
 * function and how the C compiler interprets them.
 * argc is the count of command-line arguments,
 * and argv is an array of strings
 *
 * argc(1) - The number of arguments passed to main (the program).
 * argv(0) - An array of pointers to NUL-terminated strings (the arguments).
 *
 * The caller passes the arguments; the caller of main is the C runtime system.
 * The first element in argv (argv[0]) is the name of the program.
 *
 * Conclusion
 * There is no practical difference between int main(int argc, char *argv[])
 * and int main(int argc, char **argv) in C. They are just two ways to write
 * the same thing, and the choice between them is a matter of style or personal preference
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char **argv) {
    printf("argc = %d\n", argc);
    printf("Let's see what is in argv[]:\n");
    printf("\n");

    /* use const char *str1[20] when handling multiple strings,
     * such as a list of command-line arguments or multiple string literals
     * arguments is used to store up to 20 command-line arguments.
     */

    const char *arguments[20];
    int i;
    for (i = 0; i < argc && i < 20; i++) {
        arguments[i] = argv[i];
    }

    for (i = 0; i < argc && i < 20; i++) {
        printf("argc[%d] = %s\n", i, arguments[i]);
    }

    return 0;
}
