#include <stdio.h>
#include <math.h>

int main()
{
    // To find the square root of a number, use the sqrt() function:
    int rooti = sqrt(16);
    float rootf = sqrt(16);
    float rootd = sqrt(16);
    printf("Int: %d\n", rooti);
    printf("Float: %.2f\n", rootf);
    printf("Double: %.2lf\n", rootd);

    // Round a Number
    // ceil() function rounds a number upwards to its nearest integer,
    // floor() method rounds a number downwards to its nearest integer,
    float upwards = ceil(1.4);
    float downwards = floor(1.4);
    printf("upwards: %f\n", upwards);
    printf("downwards: %f\n", downwards);

    // pow() function returns the value of x to the power of y (xy):

    return 0;
}