#include <stdio.h>

/*
 * Decision Making. In life, we all have to make decisions.
 * In order to make a decision we weigh out our options and so do our programs.
 * The if statement allows us to check if an expression is true or false,
 * and execute different code according to the result.


 */

int main(void) {
    // Here is the general form of the decision making structures found in C
    int target = 10;
    if (target == 10) {
        printf("Target is equal to 10\n");
    }

    // To evaluate whether two variables are equal, the == operator is used.
    int foo = 1;
    int bar = 2;

    if (foo < bar) {
        printf("foo is smaller than bar.\n");
    }

    if (foo > bar) {
        printf("foo is not equal to bar.\n");
    }
    printf("\n");

    // Sometimes we will have more than two outcomes to choose from.
    // In these cases, we can "chain" multiple if else statements together.
    if (foo < bar) {
        printf("foo is smaller than bar.\n");
    } else if (foo == bar) {
        printf("foo is equal to bar.\n");
    } else {
        printf("foo is greater than bar.\n");
    }

    // Nest if else statements if you like.
    int peanuts_eaten = 22;
    int peanuts_in_jar = 100;
    int max_peanut_limit = 50;

    if (peanuts_in_jar > 80) {
        if (peanuts_eaten < max_peanut_limit) {
            printf("Take as many peanuts as you want!\n");
        }
    } else {
        if (peanuts_eaten > peanuts_in_jar) {
            printf("You can't have anymore peanuts!\n");
        } else {
            printf("Alright, just one more peanut.\n");
        }
    }
    printf("\n");

    // To check if two expressions both evaluate to true, use the AND operator &&.
    // To check if at least one of the expressions evaluate to true, use the OR operator ||.

    int foos = 1;
    int bars = 2;
    int moo = 3;

    if (foos < bars && moo > bars) {
        printf("foo is smaller than bar AND moo is larger than bar.\n");
    }

    if (foos < bars || moo > bars) {
        printf("foo is smaller than bar OR moo is larger than bar.\n");
    }
    printf("\n");

    // The NOT operator ! 
    int targets = 9;
    if (targets != 10) {
        printf("Target is not equal to 10.\n");
    }
    return 0;
}