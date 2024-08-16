#include <stdio.h>

int main(void) {
    int price, qty, ttl;

    printf("Enter price and quantity: ");
    scanf("%d %d", &price, &qty);

    ttl = price * qty;

    printf("Total : %d\n", ttl);
    printf("\n");

    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("You entered an integer: %d\n", num);
    printf("\n");

    int num1, num2;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("You entered two integers : %d and %d\n", num1, num2);
    printf("\n");

    float num3;

    printf("Enter a number: ");
    scanf("%f", &num3);

    printf("You entered a floating-point number: %.3f\n", num3);
    return 0;
}
