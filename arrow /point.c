
/**
 * Usage with structures
 * dot operator ., which can be combined using the arrow operator ->.
 * p1.x and p1.y use the dot operator because p1 is a regular variable of type struct Point. In contrast, p2->x and p2->y use the arrow operator because p2 is a pointer to a struct Point.
 */
#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main(void) {
    struct Point p1 = {10, 20};  // Regular variable of type struct Point
    struct Point *p2 = &p1;      // Pointer to p1

    // Accessing members of p1 using the dot operator
    printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y);

    // Accessing members of the structure pointed by p2 using the arrow operator
    printf("p2->x = %d, p2->y = %d\n", p2->x, p2->y);

    return 0;
}
