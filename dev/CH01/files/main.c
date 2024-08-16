#include <stdio.h>

/*
 * reads characters from input and prints them
 * to output until it encounters the end-of-file (EOF) character
 * Read and Output Characters:

 * The simplest example is a program that copies its input to its output
 * one  character at a time:

 * - read a character
 *  - while (charater is not end-of-file indicator)
 *      - output the character just read read a character.
 *
 * If the assignment of a character to c is put inside
 * the test part of a while loop, the copy program can be written this way:
 *
 * The while gets a character, assigns it to c, and then tests whether
 * the  character was the end- of-file signal. If it was not,
 * the body of the while is executed, printing the character.
 * The while then repeats. When the end of the input is finally reached,
 * the while terminates and so does main.
 */
int main(void) {
    // An integer to store the character
    int c;

    // Read characters until EOF is encountered
    // and then checks if `c` is not equal to `EOF
    while ((c = getchar()) != EOF) {
        putchar(c);  // Output the character each time:
    }
    printf("%d %u %x- at EOF\n", c, c, c);
    return 0;
}
