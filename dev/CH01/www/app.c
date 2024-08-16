#include <stdio.h>

struct student {
    int rollno;
    char *name;
    int m1, m2, m3;
    float percent
};
typedef struct student STUDENT;
STUDENT s1 = {1, "Raju", 50, 60, 70, 60.00};
int main() {
    // Example of Label Identifier
    int x = 0;
begin:
    x++;
    if (x >= 10)
        goto end;
    printf("%d\n", x);
    goto begin;

end:
    return 0;
}
