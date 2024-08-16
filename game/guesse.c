/*
 * In this exercise, you must construct an if statement inside
 * the guessNumber function statement that checks if the number guess is equal to 555.
 * If that is the case, the *function must print out using printf "Correct.
 * You guessed it!". If guess is less than 555, the function must
 * print out using printf *"Your guess is too low." If guess is greater than 555,
 * the function must print out using printf "Your guess is too high.
 */

#include <stdio.h>

// implement the guessNumber function to meet the specified requirements:
void guessNumber(int guess);

int main(void) {
    guessNumber(500);
    guessNumber(600);
    guessNumber(560);
    guessNumber(670);
    guessNumber(480);
    guessNumber(490);
    guessNumber(555);
    return 0;
}

/*
 * Check if the number guess is equal to 555.
 * If guess is equal to 555, print "Correct. You guessed it!".
 * If guess is less than 555, print "Your guess is too low.".
 * If guess is greater than 555, print "Your guess is too high.".
 */
void guessNumber(int guess) {
    if (guess == 555) {
        printf("Correct. You guessed it!\n");
    } else if (guess < 555) {
        printf("Your guess is too low.\n");
    } else if (guess > 555) {
        printf("Your guess is too high.\n");
    } else {
        printf("Your guess is too high.\n");
    }
}
