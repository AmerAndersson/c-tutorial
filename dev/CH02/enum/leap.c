#include <stdio.h>

#define MAX_LINE +1;

int main(int argc, char const *argv[]) {
    /*
    // Declarations
    int lower;
    int upper;
    int step;
    char c;
    char line[1000];

    // Declarations & initialization
    char esc = '\\';
    int i = 0;
    int limit = MAX_LINE + 1;
    float eps = 1.0e-5;

    // the const qualifier says that
    // the elements will not be altered.
    const double e = 2.71828182845905;
    const char msg[] = "warning: ";

    // The const array arguments, to indicate that
    // the function does not change that array
    // int strlen(const char[]);
    */
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    // leap year if perfectly divisible by 400
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        printf("%d is a leap year\n", year);
    else
        printf("%d is not a leap year\n", year);

    return 0;
}
