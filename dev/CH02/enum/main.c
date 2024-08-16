#include <stdio.h>

// level
enum level { LOW = 1,
             MEDIUM,
             HIGH };
// escape sequences
enum escapes { BELL = '\a',
               BACKSPACE = '\b',
               TAB = '\t',
               NEWLINE = '\n',
               VTAB = '\v',
               RETURN = '\r' };

// Months of years
enum months { JAN = 1,
              FEB,
              MAR,
              APR,
              MAY,
              JUN,
              JUL,
              AUG,
              SEP,
              OCT,
              NOV,
              DEC };

// Current state
enum state { WORKING = 1,
             FAILED,
             FREEZED };

enum state curr_state = 1;

// find state
enum state find_state(void) {
    return curr_state;
}

// Day of the week
enum week { Sunday,
            Monday,
            Tuesday,
            Wednesday,
            Thursday,
            Friday,
            Saturday };

int main(int argc, char const *argv[]) {
    // demonstrate day of the week
    enum week days = Thursday;
    printf("The day number is thursday:  %d\n", days);
    printf("\n");

    // check if working or not
    (find_state() == WORKING) ? printf("IT'S WORKING\n") : printf("NOT WORKING\n");
    printf("\n");

    // prints value of  escape sequences
    printf("BELL = %d BACKSPACE = %d TAB = %d NEWLINE = % d VTAB = % d RETURN = % d\n ",
           BELL, BACKSPACE, TAB, NEWLINE, VTAB, RETURN);
    printf("\n");

    // level
    enum level myVar = MEDIUM;

    switch (myVar) {
        case 1:
            printf("Low Level\n");
            break;
        case 2:
            printf("Medium level\n");
            break;
        case 3:
            printf("High level\n");
            break;
    }
    printf("\n");

    // Months of the state
    int i;
    for (i = JAN; i <= DEC; i++) {
        printf("%d ", i);
    }
    return 0;
}
