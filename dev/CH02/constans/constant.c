/**
Data Types and Sizes, there are only a few basic data types in C:
char: -> a single byte, capable of holding one character in the local character set
int:  -> an integer, typically reflecting the natural size of integers on the host machine
float: -> single-precision floating point
double: -> double-precision floating point
short int sh; -> apply to integers:
long int counter; -> apply to integers:
The word int can be omitted in such declarations, and typically it is.
*/
#include <stdio.h>

// where ooo is one to three octal digits(0...7) or by
// '\xhh' where hh is one or more hexadecimal digits(0...9, a... f, A... F)

#define VTAB1 '\013' /* ASCII vertical tab */
#define BELL1 '\007' /* ASCII bell character */
#define VTAB2 '\xb'  /* ASCII vertical tab */
#define BELL2 '\x7'  /* ASCII bell character */

int main(int argc, char const *argv[]) {
    printf("VTAB = %c\n", VTAB1);
    printf("BELL = %c\n", BELL1);
    printf("VTAB = %o\n", VTAB2);
    printf("BELL = %o\n", BELL2);
    return 0;
}
