#include <stdio.h>

// Create a structure called myStructure
struct student {
    int rollno;
    char *name;
    int m1, m2, m3;
    float percent;
};

int main(void) {
    struct student s1 = {1, "Raju", 50, 60, 70, 60.00};
    printf("%d %s %d %d %d %.3f\n", s1.rollno, s1.name, s1.m1, s1.m2, s1.m3, s1.percent);
    printf("\n");

    int var = 0x43FF;
    printf("%x\n", var);
    printf("%X\n", var);
    printf("%d\n", var);

    return 0;
}
