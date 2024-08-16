#include <stdio.h>

//  Real-Life
// Student data to store  different data of a college student:
void studentIdAge(int studentID, int studentAge);
void studentFeeGrade(float studentFee, char studentGrade);

int main()
{
    // Student data
    int studentID = 15;
    int studentAge = 23;
    float studentFee = 75.25;
    char studentGrade = 'B';

    // Print variables
    studentIdAge(studentID, studentAge);
    studentFeeGrade(studentFee, studentGrade);
    return 0;
}

void studentIdAge(int studentID, int studentAge)
{
    printf("StudentId: %d\nStudentAge: %d\n", studentID, studentAge);
}
void studentFeeGrade(float studentFee, char studentGrade)
{
    printf("StudentFee: %.2f\nStudentGrade: %c\n", studentFee, studentGrade);
}

