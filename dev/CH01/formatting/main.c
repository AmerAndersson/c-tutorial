// C Program to illustrate the format specifier.
#include <stdio.h>

int main(void) {
    // Character Format Specifier – %c
    char c;
    // using %c for character input
    scanf("Enter some character: %c", &c);
    // using %c for character output
    printf("The entered character: %c", &c);
    printf("\n");

    // Integer Format Specifier (signed) – %d
    int x;
    // taking integer input
    scanf("Enter the two integers: %d", &x);
    // printing integer output
    printf("Printed using %%d: %d\n", x);
    printf("Printed using %%i: %3i\n", x);
    printf("\n");

    // Unsigned Integer Format Specifier – %u
    unsigned int var;
    scanf("Enter an integer: %u", &var);

    printf("Entered Unsigned Integer: %u", var);
    // trying to print negative value using %u
    printf("Printing using %%u: %u\n", var);
    printf("\n");

    // Floating-point format specifier – %f
    float a = 12.67;
    printf("Using %%f: %f\n", a);
    printf("Using %%e: %e\n", a);
    printf("Using %%E, %E\n", a);
    printf("\n");

    // Unsigned Octal number for integer – %o
    int o = 67;
    printf("%o\n", o);
    printf("\n");

    // Unsigned Hexadecimal for integer – %x
    int xa = 15454;
    printf("%x\n", xa);
    printf("%X\n", xa);
    printf("\n");

    // String Format Specifier – %s
    char a[] = "hello world";
    printf("%s\n", a);
    printf("\n");

    // working of %s with scanf()is a little bit different
    // from its working with printf()
    char str[50];
    // taking string as input
    scanf("Enter the String: %s", str);
    printf("Entered String: %s", str);
    printf("\n");

    // Scan sets: example: scanf(%s[A-Z,_,a,b,c]s,str);
    char str[128];
    printf("Enter a string: ");
    scanf("%[A-Z]s", str);
    printf("You entered: %s\n", str);
    printf("\n");

    // Address Format Specifier – %p
    int ptr = 10;
    printf("The Memory Address of a: %p\n", (void*)&ptr);
    printf("\n");

    // Example of I/O Formatting
    char str[] = "hello world";
    printf("%20s\n", str);
    printf("%-20s\n", str);
    printf("%20.5s\n", str);
    printf("%-20.5s\n", str);
    printf("\n");

    // defining variable
    int number;

    printf("Enter any number: ");
    // using address operator & in scanf() to get the value
    // entered by the user in the console
    scanf("%d", &number);

    // print the entered number
    printf("The entered number is: %d\n", number);
    printf("\n");

    // declaring a variable
    int x = 100;

    // printing the address of the variable
    printf("The address of x is %p\n", &x);
    printf("\n");

    // integer variable
    int xs = 10;
    // integer pointer
    int* ptrX;
    // pointer initialization with the address of xs
    ptrX = &xs;

    // accessing value of xs using pointer
    printf("Value of x: %d\n", *ptrX);
    printf("\n");
    return 0;
}
