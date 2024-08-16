/**
 * Function arguments by reference
Function arguments are passed by value, by which means they are copied in and out of functions.

But what if we pass pointers to values instead of the values themselves? This will allow us to give functions control over the variables and structures of the parent functions and not just a copy of them, thus directly reading and writing the original object.
 */
#include "reference.h"

// param is a pointer here which point to a memory-address
// outside the function scope.
void add_one(int *param) {
    // this will effectively increment the value of param
    (*param)++;
}

/*
 * The move function takes a pointer to a Point structure
 * and increments the x&y values using the -> operator
 * to access the members of the structure.
 */
void move(Point *ps) {
    ps->x++;
    ps->y++;
}
/* Defines the birthday function, which increments the age
of the Person by one pointed to by p. */
void birthday(Person *p) {
    p->age++;
}
