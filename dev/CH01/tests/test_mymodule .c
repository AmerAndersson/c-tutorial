// test_mymodule.c
#include <assert.h>
#include <stdio.h>

#include "mymodule.h"

void test_add() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
    assert(add(0, 0) == 0);
}

void test_subtract() {
    assert(subtract(5, 3) == 2);
    assert(subtract(-1, 1) == -2);
    assert(subtract(0, 0) == 0);
}

int main() {
    test_add();
    test_subtract();
    printf("All tests passed!\n");
    return 0;
}
