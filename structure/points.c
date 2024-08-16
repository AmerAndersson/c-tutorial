
/*
 * C structures are special, large variables which contain several named variables inside.
 * Structures are the basic foundation for objects and classes in C.
 *  Structures are used for:
 *
 * - Serialization of data
 * - Passing multiple arguments in and out of functions through a single argument
 * - Data structures such as linked lists, binary trees, and more
 */
#include <stdio.h>
#include <string.h>

/* This defines a new type Point, and create a typedef for it
which is a synonym for the anonymous struct containing x and y.*/
typedef struct {
    int x;
    int y;
} Point;

/* draw function takes a struct Point as an argument
 and prints the coordinates of the point. */
void draw(Point p);

/**
 Structures can also hold pointers - which allows them to hold strings, or pointers to other structures.
 Define a vehicle structure in the following manner:
 */
typedef struct {
    char* brand;
    char* model;
    int year;
} vehicle;

/* define the person struct here using the typedef syntax */
typedef struct {
    char* name;
    int age;
} Person;

// Main Function:
int main(void) {
    // Create a struct point variable p and initialize it
    Point p;
    p.x = 10;
    p.y = 5;

    // The draw function is called with p as the argument
    draw(p);
    printf("\n");

    // Since brand is a char pointer,
    // the vehicle type can contain a string
    // (which, in this case, indicates the brand of the vehicle).
    vehicle myCar = {"Ford", "Mustang", 1969};

    printf("%s %s %d\n", myCar.brand, myCar.model, myCar.year);
    printf("\n");

    // The name and age fields of john are assigned values
    Person john;

    /* testing code */
    john.name = "John";
    john.age = 27;
    printf("%s is %d years old.\n", john.name, john.age);
    printf("\n");

    return 0;
}

/* draw function takes a struct point as an argument
 and prints the coordinates of the point. */
void draw(Point p) {
    printf("Drawing point at (%d, %d)\n", p.x, p.y);
}
