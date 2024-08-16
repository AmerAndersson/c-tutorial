// test_mymodule.c
#include "mymodule.h"
#include "unity.h"

void setUp(void) {
    // Set up code, if needed
}

void tearDown(void) {
    // Tear down code, if needed
}

void test_add(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3));
    TEST_ASSERT_EQUAL(0, add(-1, 1));
    TEST_ASSERT_EQUAL(0, add(0, 0));
}

void test_subtract(void) {
    TEST_ASSERT_EQUAL(2, subtract(5, 3));
    TEST_ASSERT_EQUAL(-2, subtract(-1, 1));
    TEST_ASSERT_EQUAL(0, subtract(0, 0));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add);
    RUN_TEST(test_subtract);
    return UNITY_END();
}
