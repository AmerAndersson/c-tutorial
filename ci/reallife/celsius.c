#include <stdio.h>

// Function to convert Fahrenheit to Celsius
float toCelsius(float fahrenheit);
struct Car
{
    char brand[50];
    char model[50];
    int year;
};

struct Student
{
    // Student data
    int studentID;
    int studentAge;
    float studentFee;
    char studentGrade;
};

int main()
{
    // Set a fahrenheit value
    float f_value = 98.8;

    // Call the function with the fahrenheit value
    float result = toCelsius(f_value);

    // Print the fahrenheit value
    printf("Fahrenheit: %.2f\n", f_value);

    // Print the result
    printf("Convert Fahrenheit to Celsius: %.2f\n", result);
    printf("----------------------------\n");

    struct Car car1 = {"BMW", "X5", 1999};
    struct Car car2 = {"Ford", "Mustang", 1969};
    struct Car car3 = {"Toyota", "Corolla", 2011};

    printf("%s %s %d\n", car1.brand, car1.model, car1.year);
    printf("%s %s %d\n", car2.brand, car2.model, car2.year);
    printf("%s %s %d\n", car3.brand, car3.model, car3.year);
    printf("----------------------------\n");

    // Student data to store  different data of a college student:
    struct Student s1 = {13, 25, 75.25, 'A'};
    struct Student s2 = {12, 20, 60.23, 'B'};
    struct Student s3 = {11, 21, 50.25, 'C'};
    struct Student s4 = {10, 19, 40.24, 'D'};
    printf("ID: %d Age: %d Fee: %.2f Grade: %c\n", s1.studentID, s1.studentAge, s1.studentFee, s1.studentGrade);
    printf("ID: %d Age: %d Fee: %.2f Grade: %c\n", s2.studentID, s2.studentAge, s2.studentFee, s2.studentGrade);
    printf("ID: %d Age: %d Fee: %.2f Grade: %c\n", s3.studentID, s3.studentAge, s3.studentFee, s3.studentGrade);
    printf("ID: %d Age: %d Fee: %.2f Grade: %c\n", s4.studentID, s4.studentAge, s4.studentFee, s4.studentGrade);

    return 0;
}
// Function to convert Fahrenheit to Celsius
float toCelsius(float fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}