#include <stdio.h>
#include <string.h>

// Create a structure
typedef struct MyStructure {
    int myNum;
    char myLetter;
    char myString[30];
} MyStructure;

typedef struct Car {
    char brand[50];
    char model[50];
    int year;
} Car;

// child structure
typedef struct Child {
    int x;
    char c;
} Child;

// parent structure
typedef struct Parent {
    int a;
    struct Child b;
} Parent;

void print_structs(void) {
    // Create different struct variables
    MyStructure s1;
    MyStructure s2;

    // Assign values to different struct variables
    s1.myNum = 13;
    s1.myLetter = 'B';

    s2.myNum = 20;
    s2.myLetter = 'C';

    // Print values
    printf("s1 number: %d\n", s1.myNum);
    printf("s1 letter: %c\n", s1.myLetter);
    printf("\n");

    printf("s2 number: %d\n", s2.myNum);
    printf("s2 letter: %c\n", s2.myLetter);
    printf("\n");

    // Modifying values are especially useful when you copy structure values:
    // Create a structure variable and assign values to it
    MyStructure s3 = {13, 'B', "Some text"};

    // Create another structure variable
    MyStructure s4;

    // Copy s1 values to s4 Copy Structures
    s4 = s3;

    // Change s4 values
    s4.myNum = 30;
    s4.myLetter = 'C';
    strcpy(s4.myString, "Something else");

    // Print values
    printf("%d %c %s\n", s4.myNum, s4.myLetter, s4.myString);
    printf("%d %c %s\n", s4.myNum, s4.myLetter, s4.myString);
    printf("%d %c %s\n", s4.myNum, s4.myLetter, s4.myString);
    printf("\n");

    // Create a structure variable and assign values to it
    MyStructure s5 = {13, 'B', "Some text"};

    // Print values
    printf("%d %c %s\n", s5.myNum, s5.myLetter, s5.myString);
    printf("\n");

    // Create car
    Car car1 = {"BMW", "X5", 1999};
    Car car2 = {"Ford", "Mustang", 1969};
    Car car3 = {"Toyota", "Corolla", 2011};

    printf("%s %s %d\n", car1.brand, car1.model, car1.year);
    printf("%s %s %d\n", car2.brand, car2.model, car2.year);
    printf("%s %s %d\n", car3.brand, car3.model, car3.year);
    printf("\n");

    Parent parm = {25, {195, 'A'}};

    // accessing and printing nested members
    printf("parm.a = %d\n", parm.a);
    printf("parm.b.x = %d\n", parm.b.x);
    printf("parm.b.c = %c\n", parm.b.c);
    printf("\n");
}
