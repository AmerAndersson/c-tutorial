/*
 * Accessing struct members
 * The C code snippet defines a struct Example with an integer variable x
 * and a member function display(), creates variable obj of Example,
 * uses a pointer ptr  to assign 10 to x and call display(), outputting
 * the value of x using the arrow * operator.
 */

#include <stdio.h>

// Define a struct to hold data
struct Example {
    int x;
    void (*display)(struct Example*);  // Function pointer
};

// Define a function to display the data
void display(struct Example* e) {
    printf("Value of x: %d\n", e->x);
}

int main(void) {
    struct Example obj;
    struct Example* ptr = &obj;
    ptr->display = display;  // Assign the function to the function pointer

    ptr->x = 10;        // Accessing variable using arrow operator
    ptr->display(ptr);  // Accessing function using arrow operator
    return 0;
}
