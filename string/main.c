/*
 * Defining strings
 * Strings in C are actually arrays of characters.
 * Although using pointers in C is an advanced subject, fully explained later on,
 * we will use pointers to a character array to define simple strings, in the following manner:
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    // This method creates a string which we can only use for reading.
    // If we wish to define a string which can be manipulated,
    // we will need to define it as a local character array:
    char name1[] = "John Smith";
    /* is the same as */
    char name2[11] = "John Smith";

    // pointers to a character array
    // String formatting with printf
    char* name = "John Smith";
    int age = 27;

    /* prints out 'John Smith is 27 years old.' */
    printf("%s is %d years old.\n", name, age);
    printf("\n");

    // String Length
    // The function 'strlen' returns the length of the string
    // which has to be passed as an argument:
    char* greeting = "Hello World!";
    printf("Length of string a %zu\n", strlen(greeting));

    char* a = "Program";
    char b[20] = {'P', 'r', 'o', 'g', 'r', 'a', 'm', '\0'};

    // using the %zu format specifier to print size_t
    printf("Length of string a = %zu \n", strlen(a));
    printf("Length of string b = %zu \n", strlen(b));
    printf("\n");
    /*
     * String comparison
     * The function strncmp compares between two strings,
     * returning the number 0 if they are equal, or a different number if they are different.
     * The arguments are the two strings to be compared, and the maximum comparison length.
     */

    char* names = "John";

    if (strncmp(names, "John", 4) == 0) {
        printf("Hello, John!\n");
    } else {
        printf("You are not John. Go away.\n");
    }
    printf("\n");

    /**
     * String Concatenation
     * The function 'strncat' appends first n characters of src string to
     * the destination string where n is min(n,length(src));
     * The arguments passed are destination string, source string,
     * and n - maximum number of characters to be appended. For Example:
     */

    char dest[20] = "Hello";
    char src[20] = "World";
    strncat(dest, src, 3);
    printf("%s\n", dest);
    strncat(dest, src, 20);
    printf("%s\n", dest);
    printf("\n");

    // Define the string first_name with the value John using the pointer notation,
    // and define the string last_name with the value Doe using the local array notation.

    /* define first_name using pointer notation */
    char* first_name = "John";
    /* define last_name using local array notation */
    char last_name[4] = "Doe";

    char fully_name[100];

    last_name[0] = 'B';
    sprintf(fully_name, "%s %s", first_name, last_name);
    if (strncmp(fully_name, "John Boe", 100) == 0) {
        printf("Done!\n");
    }
    fully_name[0] = '\0';
    strncat(fully_name, first_name, 4);
    strncat(fully_name, last_name, 20);
    printf("%s\n", fully_name);

    /**
     * str : A pointer to an array of characters where the resulting string will be stored.
     * format : A pointer to a null-terminated string that contains the text to be written
     * to the string str.
     * This string may contain format specifiers that dictate how subsequent
     * arguments are converted and formatted into the resulting string.
     */
    char buffer[100];
    int age = 30;
    char name[] = "John";
    sprintf(buffer, "%s is %d years old.", name, age);
    printf("%s\n", buffer);

    char buffer[100];
    float pi = 3.14159;
    sprintf(buffer, "The value of pi is %.2f.", pi);
    printf("%s\n", buffer);

    return 0;
}
