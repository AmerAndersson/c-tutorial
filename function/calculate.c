/*
 * In C, arguments are copied by value to functions,
 * which means that we cannot change the arguments
 * to affect their value outside of the function. To do that, we must use pointers,
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate_sum(int x, int y);
void user_info(char name[], int age);

// The function foo we defined receives one argument,
// which is bar. The function receives an integer,
// multiplies it by two, and returns the result.
int foo(int bar);

// Return sum of elements in A[0..N-1]
// using recursion.
int find_sum(int A[], int N);

/*
Using recursion
When the sum() function is called, it adds parameter k to the sum of all numbers smaller than k and returns the result. When k becomes 0, the function just returns 0. When running, the program follows these steps:

10 + sum(9)
10 + ( 9 + sum(8) )
10 + ( 9 + ( 8 + sum(7) ) )
...
10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + sum(0)
10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + 0
*/
int sum(int k);

// This function checks if the provided integer is greater than 10.
// If number is greater than 10, it prints "number is big"
void print_big(int number);
// THEN MAIN FUNCTION:
int main(void) {
    char s1[20] = "53875";
    char s2[10] = "Hello";
    char s3[10] = "World";

    int res;
    res = pow(8, 4);
    printf("Using math.h, The value is : %d\n", res);

    long int a = atol(s1);
    printf("Using stdlib.h, the string to long int: %ld\n", a);

    strcpy(s2, s3);
    printf("Using string.h, the strings s2 and s3: %s\t%s\n", s2, s3);
    printf("\n");

    int result1 = calculate_sum(5, 3);
    int result2 = calculate_sum(8, 2);
    int result3 = calculate_sum(15, 15);

    printf("Result1 is: %d\n", result1);
    printf("Result2 is: %d\n", result2);
    printf("Result3 is: %d\n", result3);
    printf("\n");

    user_info("Liam", 3);
    user_info("Jenny", 14);
    user_info("Smith", 30);
    user_info("David", 10);
    user_info("John", 20);
    user_info("Adam", 40);
    printf("\n");

    // find the square root of a number:
    printf("%.3f\n", sqrt(16));
    // returns the value of x to the power of y (xy):
    printf("%.3f\n", pow(4, 3));
    // rounds a number upwards to its nearest integer:
    printf("%.3f\n", ceil(1.4));
    // rounds a number downwards to its nearest integer:
    printf("%.3f\n", floor(1.4));
    printf("\n");

    int product = foo(2);
    /* calling foo from main */
    printf("The value of foo is %d\n", product);
    printf("\n");

    int result = sum(10);
    printf("Result = %d\n", result); /* print hello world*/
    printf("\n");

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int N = sizeof(A) / sizeof(A[0]);
    printf("The sum = %d\n", find_sum(A, N));
    printf("\n");

    // an array of integers is defined and iterated over.
    int array[10] = {1, 11, 2, 22, 3, 33, 4, 44, 5, 55};
    int i;  // iterator variable i

    // Get the length of the array
    int length = sizeof(array) / sizeof(0);

    // Loop through the elements of the array
    // For each integer in the array, print_big is called.
    for (i = 0; i < length; i++) {
        print_big(array[i]);
    }
    return 0;
}
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The function foo we defined receives one argument,
// which is bar. The function receives an integer,
// multiplies it by two, and returns the result.
int foo(int bar) {
    return bar * 2;
}
/*
When the sum() function is called, it adds parameter k to the sum of all numbers smaller than k and returns the result. When k becomes 0, the function just returns 0. When running, the program follows these steps:

10 + sum(9)
10 + ( 9 + sum(8) )
10 + ( 9 + ( 8 + sum(7) ) )
...
10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + sum(0)
10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + 0
*/
int sum(int k) {
    if (k > 0) {
        return k + sum(k - 1);
    } else {
        return 0;
    }
}

// Return sum of elements in A[0..N-1]
// using recursion.
int find_sum(int A[], int N) {
    if (N <= 0)
        return 0;
    return (find_sum(A, N - 1) + A[N - 1]);
}
// This function checks if the provided integer is greater than 10.
// If number is greater than 10, it prints "number is big"

void print_big(int number) {
    // Inside the function,
    if (number > 10) {
        printf("%d is big\n", number);  // Print x is big
    }
}

void user_info(char name[], int age) {
    printf("Hello %s! You are %d years old.\n", name, age);
}

int calculate_sum(int x, int y) {
    return x + y;
}
