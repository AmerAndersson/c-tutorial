// C program to print Integer data types.
#include <stdio.h>

void swap(int *x, int *y);  // pass by reference
void swaps(int a, int b);   // pass by value

int main(void) {
    int x = 10;
    int y = 15;

    printf("&x before: %d\n&y before: %d\n", x, y);
    printf("\n");

    swap(&x, &y);
    printf("&x after: %d\n&y after: %d\n", x, y);
    printf("\n");

    int a = 20;
    int b = 25;

    printf("a before: %d\nb before: %d\n", a, b);
    printf("\n");

    swaps(x, y);
    printf("a after: %d\nb after: %d\n", a, b);
    printf("\n");

    return 0;
}
void swaps(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
