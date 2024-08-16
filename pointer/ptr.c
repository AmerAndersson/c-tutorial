/**
 * Prerequisite: Pointers in C, Double Pointer (Pointer to Pointer) in C
 * A pointer is used to point to a memory location of a variable.
 * A pointer stores the address of a variable.
 *
 * Similarly, a chain of pointers is when there are multiple levels of pointers.
 * Simplifying, a pointer points to address of a variable, double-pointer points
 * to a variable and so on. This is called multiple indirections.
 */

#include <stdio.h>

int main(void) {
    // C program for chain of pointer
    int var = 10;

    // Pointer level-1
    // Declaring pointer points to variable var
    int* ptr1;

    // Storing address of variable var,
    // pointer points to variable ptr1
    ptr1 = &var;

    // Pointer level-2
    // Declaring pointer points to variable *ptr1
    int** ptr2;

    // Storing address of pointer variable
    // ptr1 to level -2 pointer ptr2
    ptr2 = &ptr1;

    // Pointer level-3
    // Declaring pointer to double pointer **ptr2
    int*** ptr3;

    // Storing address of level-2 pointer
    // ptr2 to level-3 pointer ptr3
    ptr3 = &ptr2;
    // Displaying values
    printf("Value of var = %d\n", var);
    printf("The memory address of var = %p\n", &var);

    // Dereference:
    printf("Value of var using single pointer = %d\n", *ptr1);
    printf("The memory address of var using ptr1 = %p\n", ptr1);

    // Dereference:
    printf("Value of var using double pointer = %d\n", **ptr2);
    printf("The memory address of ptr1 using ptr2 = %p\n", ptr2);

    // Dereference:
    printf("Value of var using double pointer = %d\n", ***ptr3);
    printf("The memory address of ptr2 using ptr3 = %p\n", ptr3);
    printf("\n");

    // defining single and double pointers
    int a = 5;
    int* ptr = &a;
    int** d_ptr = &ptr;

    // size of single pointer
    printf("Size of normal int : %lu\n", sizeof(a));
    // size of single pointer
    printf("Size of normal Pointer: %lu\n", sizeof(ptr));

    // size of double pointer
    printf("Size of Double Pointer: %lu\n", sizeof(d_ptr));
    printf("\n");

    /**
     * Example 2: Consider below-given code where we have taken float data type of the variable, so now we have to take same data type for the chain of pointers too. As the pointer and the variable, it is pointing to should have the same data type.
     */

    float vars = 23.564327;

    // Declaring pointer variables upto level_4
    float *ptr01, **ptr02, ***ptr03, ****ptr04;

    // Initializing pointer variables
    ptr01 = &vars;
    ptr02 = &ptr01;
    ptr03 = &ptr02;
    ptr04 = &ptr03;

    // Printing values
    printf("Value of var = %.5f\n", vars);
    printf("Value of var using level-1: pointer = %.5f\n", *ptr01);
    printf("Value of var using level-2: pointer = %.5f\n", **ptr02);
    printf("Value of var using level-3: pointer = %.5f\n", ***ptr03);
    printf("Value of var using level-4: pointer = %.5f\n", ****ptr04);
    printf("\n");

    /**
     * Example 3: Updating variable using chained pointer
    As we already know that a pointer points to address location of a variable so when we access the value of pointer it’ll point to the variable’s value. Now to update the value of variable, we can use any level of pointer as ultimately every pointer is directly or indirectly pointing to that variable only. It’ll directly change the value present at the address location of variable.
     */

    // Initializing integer variable
    int var1 = 10;

    // Declaring pointer variables upto level-3
    int *ptr001, **ptr002, ***ptr003;

    // Initializing pointer variables
    ptr001 = &var1;
    ptr002 = &ptr001;
    ptr003 = &ptr002;

    // Printing values BEFORE update
    printf("Before:\n");
    printf("Value of var = %d\n", var1);
    printf("Value of var using level-1:pointer = %d\n", *ptr001);
    printf("Value of var using level-2:pointer = %d\n", **ptr002);
    printf("Value of var using level-3:pointer = %d\n", ***ptr003);
    printf("\n");

    printf("The memory address = %p\n", &var1);
    printf("The memory address level-1:pointer = %p\n", ptr001);
    printf("The memory address level-2:pointer = %p\n", ptr002);
    printf("The memory address using level-3:pointer = %p\n", ptr003);
    printf("\n");

    // Updating var's value using level-3 pointer
    ***ptr003 = 35;
    printf("\n");

    // Printing values AFTER update
    printf("After:\n");
    printf("Value of var = %d\n", var1);
    printf("Value of var using level-1: pointer = %d\n", *ptr001);
    printf("Value of var using level-2: pointer = %d\n", **ptr002);
    printf("Value of var using level-3: pointer = %d\n", ***ptr003);
    printf("\n");

    /*
     * Pointers are also variables and play a very important role in C programming language.
     * They are used for several reasons, such as
     *
     * - Strings
     * - Dynamic memory allocation
     * - Sending function arguments by reference
     * - Building complicated data structures
     * - Pointing to functions
     * - Building special data structures (i.e. Tree, Tries, etc...)
     * */

    // In C, strings are arrays of characters,
    // and pointers are often used to manipulate strings efficiently.

    // ptrs is a pointer to the first character of the string str.
    // Pointers allow you to traverse and manipulate strings easily.
    char str[] = "Hello, World!";
    char* ptrs = str;

    return 0;
}
