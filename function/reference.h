// REFERENCE_H

#ifndef REFERENCE_H
#define REFERENCE_H

// param is a pointer here which point to a memory-address
// outside the function scope.
void add_one(int *param);

// Define the point structure with two integer members: x&y
typedef struct {
    int x;
    int y;
} Point;

/*
 * The move function takes a pointer to a Point structure
 * and increments the x&y values using the -> operator
 * to access the members of the structure.
 */
void move(Point *p);

/* person is a struct containing a name (a pointer to a character string)
and an age (an integer).*/
typedef struct {
    char *name;
    int age;
} Person;

/* Declares the birthday function, which takes a pointer to a Person struct as its argument.*/
void birthday(Person *p);

#endif
