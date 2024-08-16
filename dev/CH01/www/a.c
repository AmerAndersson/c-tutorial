// The Preprocessor directive
#include <math.h>
#include <stdio.h>

#define PI 3.14159
#define AREA(r) (PI * r * r)

// Function Declaration
float area_of_square(float);

int main(void) {
    int radius = 5;
    float area = AREA(radius);
    printf("%f\n", area);

    float side = 5.50;
    float areas = area_of_square(side);
    printf("Side=%5.2f Area=%5.2f\n", side, areas);

    return 0;
}

// Function Definiton
float area_of_square(float side) {
    float areas = pow(side, 2);
    return areas;
}
