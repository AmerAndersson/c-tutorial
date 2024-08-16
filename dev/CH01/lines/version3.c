
#include <stdio.h>

/* count lines in input ; 3nd version */
int main(void) {
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF) {  //  (-1)
        if (c == '\n') {
            ++nl;
        }
    }
    printf("%d\n", nl);

    return 0;
}
