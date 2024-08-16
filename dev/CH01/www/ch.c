
/**
--------------------------------------------------------
%6d print as decimal integer, at least 6 characters wide
%f print as floating point
%6f print as floating point, at least 6 characters wide
%.2f print as floating point, 2 characters after decimal point
%6.2f
%o for octal,
%x for hexadecimal,
%c for character,
%s for character string and
%% for itself
-------------------------------------------------------
 */
#include <stdio.h>

// count digits, white space, others
int main(void) {
    float a = 10.34;
    int b = 10;
    char c = 'c';
    char ch[] = "hello";

    printf("%6f\n", a);
    printf("%6d\n", b);
    printf("%.2f\n", a);
    printf("%6.2f\n", a);
    printf("\n");

    printf("%o\n", b);
    printf("%x\n", b);
    printf("%c\n", c);
    printf("%s\n", ch);
    printf(" %.2ff%%\n", a);

    return 0;
}
