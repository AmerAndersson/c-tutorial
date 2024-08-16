#include <stdio.h>

int main(void) {
    int c;

    /*
    - getchar() reads a character from the input.
    - The result of c != EOF is computed and stored in expression_result.
    - The value of expression_result is printed, showing either 0 (false) or 1 (true).
    - If expression_result is 0 (meaning c == EOF), the loop breaks.
    - Otherwise, the character c is printed using putchar(c).
    */
    while (1) {
        int expression_result = ((c = getchar()) != EOF);
        // This will print 0 or 1
        printf("getchar() != EOF: %d\n", expression_result);
        if (expression_result == 0) {
            break;
        }
        // putchar prints a character each time:
        putchar(c);
    }

    printf("The value of EOF is: %d\n", EOF);  // The value of EOF is: -1
    return 0;
}
