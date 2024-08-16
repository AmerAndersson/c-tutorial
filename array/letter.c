/**
 * The five letters A, E, I, O and U are called vowels.
 * All other alphabets except these 5 vowels are called consonants.
 * This program assumes that the user will always enter an alphabet character.
 */

#include <ctype.h>
#include <stdio.h>

int main(void) {
    char c;
    int lowercase_vowel, uppercase_vowel;
    printf("Enter an alphabet: ");
    scanf("%c", &c);

    // evaluates to 1 if variable c is a lowercase vowel
    lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

    // evaluates to 1 if variable c is a uppercase vowel
    uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    // Show error message if c is not an alphabet
    if (!isalpha(c))
        printf("Error! Non-alphabetic character.\n");
    else if (lowercase_vowel || uppercase_vowel)
        printf("%c is a vowel.\n", c);
    else
        printf("%c is a consonant.\n", c);

    return 0;
}
