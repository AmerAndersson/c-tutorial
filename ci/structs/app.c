#include <stdio.h>
#include <string.h>

/*
 * Structures (also called structs)
 * are a way to group several related variables into one place.
 * Each variable in the structure is known as a member of the structure
 * Unlike an array, a structure can contain many different data types (int, float, char, etc.)
 * Create a Structure  by using the struct keyword
 * and declare each of its members inside curly braces:
 */

// Structure declaration, called myStructure
// Member (char variable)
// Member (int variable)

struct myStructure {
    int myNum;
    char myLetter;
    char myString[30];  // String
};

// To store different information about Cars:
struct Car {
    char brand[50];
    char model[50];
    int year;
};
int main() {
    // To access the structure, and create a variable of it.
    // Create different struct variables
    struct myStructure myS1;
    struct myStructure myS2;
    struct myStructure myS3;

    // Create a structure variable and assign values to it
    struct myStructure myS4 = {15, 'D', "Some text"};

    // To access members of a structure, use the dot syntax (.)
    // Assign values to different struct variables
    myS1.myNum = 13;
    myS1.myLetter = 'A';

    myS2.myNum = 14;
    myS2.myLetter = 'B';

    // Print values
    printf("My number: %d\n", myS1.myNum);
    printf("My letter: %c\n", myS1.myLetter);

    // Print values
    printf("My number: %d\n", myS2.myNum);
    printf("My letter: %c\n", myS2.myLetter);

    // Assign a value to the string using the strcpy function
    strcpy(myS3.myString, "Hello World!");
    // Print the value
    printf("My string: %s\n", myS3.myString);
    printf("------------------------------\n");
    // Print values
    printf("Print values: %d %c %s\n", myS4.myNum, myS4.myLetter, myS4.myString);

    // Copy Structures
    struct myStructure myS5;
    myS5 = myS4;
    // Print values
    printf("Copy Structures: %d %c %s\n", myS5.myNum, myS5.myLetter, myS5.myString);

    // Change s2 values
    myS5.myNum = 30;
    myS5.myLetter = 'C';
    strcpy(myS5.myString, "Something else");
    // Print values
    printf("Print values: %d %c %s\n", myS4.myNum, myS4.myLetter, myS4.myString);
    // Print values
    printf("Change myS5 values: %d %c %s\n", myS5.myNum, myS5.myLetter, myS5.myString);
    printf("------------------------------\n");

    // To store different information about Cars:
    struct Car car1 = {"BMW", "X5", 1999};
    struct Car car2 = {"Ford", "Mustang", 1969};
    struct Car car3 = {"Toyota", "Corolla", 2011};
    printf("BMW: %s %s %d\n", car1.brand, car1.model, car1.year);
    printf("Ford: %s %s %d\n", car2.brand, car2.model, car2.year);
    printf("Toyota: %s %s %d\n", car3.brand, car3.model, car3.year);
    printf("------------------------------\n");

    return 0;
}
