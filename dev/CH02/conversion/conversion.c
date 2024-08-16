#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

// Function declaration
int atoi(const char s[]);
void print_string_length();
int lower(int c);

int main(void) {
    // Test cases
    const char *test1 = "123";
    const char *test2 = "   456";
    const char *test3 = "-789";
    const char *test4 = " +321";
    const char *test5 = "2147483648";   // Greater than INT_MAX
    const char *test6 = "-2147483649";  // Less than INT_MIN
    const char *test7 = "abc";
    const char *test8 = "123abc";
    const char *test9 = "-123abc456";

    // Printing results
    printf("atoi(\"123\") = %d\n", atoi(test1));
    printf("atoi(\"   456\") = %d\n", atoi(test2));
    printf("atoi(\"-789\") = %d\n", atoi(test3));
    printf("atoi(\" +321\") = %d\n", atoi(test4));
    printf("atoi(\"2147483648\") = %d\n", atoi(test5));
    printf("atoi(\"-2147483649\") = %d\n", atoi(test6));
    printf("atoi(\"abc\") = %d\n", atoi(test7));
    printf("atoi(\"123abc\") = %d\n", atoi(test8));
    printf("atoi(\"-123abc456\") = %d\n", atoi(test9));
    printf("\n");

    // getting length of string
    print_string_length();
    printf("\n");

    /* lower: convert c to lower case; ASCII only */
    char letter = 'A';
    int result = lower(letter);
    printf("c= %d\n", result);

    return 0;
}
// Type Conversions
int atoi(const char s[]) {
    int i = 0, n = 0, sign = 1;

    // Skip leading whitespace
    while (isspace(s[i])) {
        i++;
    }

    // Check for optional sign
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Convert digits to integer
    while (s[i] >= '0' && s[i] <= '9') {
        // Check for overflow
        if (n > (INT_MAX - (s[i] - '0')) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        n = 10 * n + (s[i] - '0');
        i++;
    }

    return sign * n;
}
/* lower: convert c to lower case; ASCII only */
int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

void print_string_length() {
    // Declare string
    char a[20] = "Program";
    char b[20] = {'P', 'r', 'o', 'g', 'r', 'a', 'm', '\0'};

    // using the %zu format specifier to print size_t
    printf("Length of string a = %zu \n", strlen(a));
    printf("Length of string b = %zu \n", strlen(b));
}