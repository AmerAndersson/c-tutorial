/**
 * The provided C code defines a structure Sample with an integer member a, dynamically allocates memory for a Sample structure, assigns the value 5 to its a member using a pointer and the arrow operator, outputs the assigned value, and then frees the allocated memory, handling memory allocation failure with an error message.
 */
#include <stdio.h>
#include <stdlib.h>

struct Sample {
    int a;
};

int main(void) {
    struct Sample* ptr = (struct Sample*)malloc(sizeof(struct Sample));
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    ptr->a = 10;  // Using arrow operator
    printf("ptr->a: %d\n", ptr->a);
    free(ptr);  // Freeing allocated memory
    return 0;
}
