#include <stdio.h>

#define LEAP 1

int main(int argc, char const *argv[]) {
    // Array to store the days of the months in a leap year
    int days[31 + 28 + LEAP + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31];

    // Number of days in each month for a leap year
    int month_days[] = {31, 28 + LEAP, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Initialize the days array (for demonstration purposes)
    int i, j, day_counter = 1;
    for (i = 0; i < 12; ++i) {
        for (j = 0; j < month_days[i]; ++j) {
            days[day_counter - 1] = day_counter;
            day_counter++;
        }
    }

    // Print the days array (for demonstration purposes)
    int length = sizeof(days) / sizeof(days[0]);
    for (i = 0; i < length; ++i) {
        printf("%d ", days[i]);
    }

    return 0;
}
