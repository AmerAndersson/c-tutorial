#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /*
    The while (1) creates an infinite loop.

    The if (i >= 10) checks the first condition and breaks the loop
    if i is not less than 10.

    The if (i % 2 != 0) checks the second condition and uses
    continue to skip the rest of

    If both conditions are satisfied, the loop body executes,
    printing the value of i and then increments i
    */

    int i = 0;
    while (1) {
        if (i >= 10) {
            break;
        }
        if (i % 2 != 0) {
            i++;  // Increment i and continue to next iteration if i is odd
            continue;
        }
        printf("%d\n", i);
        i++;  // Increment i at the end of the loop
    }

    return 0;
}