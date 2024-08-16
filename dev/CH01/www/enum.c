#include <stdio.h>

int average(int, int);

enum week {
    Mon = 10,
    Tue,
    Wed,
    Thur,
    Fri = 10,
    Sat = 16,
    Sun
};
int main(void) {
    int marks1 = 50, marks2 = 60;
    float avg = average(marks1, marks2);
    printf("The value of marks is %f\n", avg);
    printf("\n");

    printf("The value of enum week: %d\n", Mon);
    return 0;
}
int average(int marks1, int marks2) {
    return (float)(marks1 + marks2) / 2;
}