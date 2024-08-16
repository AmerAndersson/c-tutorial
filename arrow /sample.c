#include <stdio.h>
/**
 * Usage with structures
 * defines a structure Sample with an integer member a,
 * creates an object obj of that structure,
 * uses a pointer ptr to assign the value 5 to obj.a
 * using the arrow operator, and outputs the assigned value to the standard output.
 */

struct Sample {
    int a;
};

int main(void) {
    struct Sample obj;
    struct Sample* ptr = &obj;
    ptr->a = 5;  // Using arrow operator
    printf("ptr->a: %d\n", ptr->a);
    return 0;
}
