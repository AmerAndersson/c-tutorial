#include <stdio.h>

/**
 * - Defined using Data types:
 *
 * char, int, short, long or long long.
 *
 * unsigned char, unsigned int,
 * unsigned short,
 * unsigned long,
 * unsigned long long.
 *
 * Unsigned integers - whole numbers which can only be positive.
 *
 * - Defined using:
 *
 * float and double.
 * Floating point numbers - real numbers (numbers with fractions).
 *
 * A char can range only from -128 to 127,
 * A long can range from -2,147,483,648 to 2,147,483,647
 *
 * (long and other numeric data types may have another range on different computers,
 * for example: - from
 * –9,223,372,036,854,775,808 to
 * 9,223,372,036,854,775,807 on 64-bit computer).
 *
 * - Structures
 */

/*
Arrays can only have one type of variable,
because they are implemented as a sequence of values in the computer's memory.
Because of that, accessing a specific array cell is very efficient.
*/
int main(void) {
    /* Defines  one-dimensional an array of 10 integers */
    int numbers[10];

    /* populate the array */
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;
    numbers[5] = 60;
    numbers[6] = 70;

    /* print the 7th number from the array, which has an index of 6 */
    printf("The 7th number in the array is %d\n", numbers[6]);

    /* The grade average will be 85 */
    int grade[10];
    int averages;

    grade[0] = 80;
    grade[1] = 90;
    grade[2] = 85;

    averages = (grade[0] + grade[1] + grade[2]) / 3;
    printf("The average of the 3 grades is: %d\n", averages);

    /* Form of multidimensional array is the two-dimensional array.
    A table which will have rows[x] columns[y]
    The form a[x][y], where 'a' is the name of the array, and 'x' and 'y'
    are the indexes that uniquely identify, or show, each element in 'a'.
           --------------------------------------------
          | column 0 | column 1 | column 2 | column 3 |
          |--------------------------------------------
    Row 0 |  a[0][0] | a[0][1]  |  a[0][2] | a[0][3]  |
          |-------------------------------------------
    Row 1 |  a[1][0] | a[1][1]  |  a[1][2] | a[1][3]  |
          |-------------------------------------------
    Row 2 |  a[2][0] | a[2][1]  |  a[2][2] | a[2][3]  |
          |-------------------------------------------
    */

    printf("==== Multidimensional Arrays ====\n");
    /* Initializing Two-Dimensional Arrays */
    int a[3][4] = {
        {0, 1, 2, 3},  /*  initializers for row indexed by 0 */
        {4, 5, 6, 7},  /*  initializers for row indexed by 1 */
        {8, 9, 10, 11} /*  initializers for row indexed by 2 */
    };

    int n, m;
    for (n = 0; n < 3; n++) {
        for (m = 0; m < 4; m++) {
            printf("a = %d\n", a[n][m]);
        }
    }
    printf("\n");

    /* The inside braces, which indicates the wanted row, are optional.
    The following initialization is the same to the previous example */
    int b[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    printf("b = %d\n", b[1][3]);

    printf("\n");

    char vowels[2][5] = {
        {'A', 'E', 'I', 'O', 'U'},
        {'a', 'e', 'i', 'o', 'u'}};
    for (n = 0; n < 2; n++) {
        for (m = 0; m < 5; m++) {
            printf("v = %c\n", vowels[n][m]);
        }
    }
    printf("\n");

    /* Let us try to find out the average marks of a group of five students for two subjects, Mathematics and Physics. To do this, we use a two-dimensional array called grades. The marks corresponding to Mathematics would be stored in the first row (grades[0]), whereas those corresponding to Physics would be stored in the second row (grades[1]) */

    // Declare the 2D array grades with known dimensions
    int grades[2][5];
    float average;
    int i, j;

    // Initialize the array with values
    grades[0][0] = 80;
    grades[0][1] = 70;
    grades[0][2] = 65;
    grades[0][3] = 89;
    grades[0][4] = 90;

    grades[1][0] = 85;
    grades[1][1] = 80;
    grades[1][2] = 80;
    grades[1][3] = 82;
    grades[1][4] = 87;

    // subjects (rows) students (columns)
    int row_subjects = 2;
    int col_students = 5;

    // Outer loop iterates over subjects (rows):
    // Inner loop iterates over students (columns):
    for (i = 0; i < row_subjects; i++) {
        average = 0;
        for (j = 0; j < col_students; j++) {
            average += grades[i][j];
        }

        // Calculate the average  marks for subject i,
        // by dividing the total by the number of students
        average /= col_students;
        printf("The average marks obtained in subject row[%d] is: %.2f\n", i, average);
    }
    printf("\n");

    int marks[10] = {50, 55, 67, 73, 45, 21, 39, 70, 49, 51};
    int i, sum = 0;
    float avg;
    int length = sizeof(marks) / sizeof(0);
    for (i = 0; i <= length; i++) {
        sum += marks[i];
    }

    avg = (float)sum / 10;
    printf("Average: %.4f", avg);

    return 0;
}