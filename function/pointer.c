/*
 * Function Pointers:
 * Now it is time to do something even more interesting with pointers,
 * using them to point to and call functions.
 *
 * Why point to a function?
 * The first question that may come to your mind is why would we use pointers
 * to call a function when we can simply call a function by its name: function();
 * - that's a great question! Now imagine the sort function where you need to sort an array.
 * Sometimes you want to order array elements in an ascending order or descending order.
 * How would you choose? Function pointers!
 *
 * Function Pointer Syntax
 * void (*pf)(int);
 * I agree with you. This definitely is very complicated, or so you may think.
 * Let's re-read that code and try to understand it point by point.
 * Read it inside-out. *pf is the pointer to a function. void is the return type of that
 * function, and finally int is the argument type of that function. Got it? Good.
 *
 * Let's insert pointers into the function pointer and try to read it again:
 * char* (*pf)(int*);
 * Again: 1. *pf is the function pointer. 2. char* is the return type of that function. 3.
 * int* is the type of the argument.
 *
 * Why do we use function pointers? 1.
 * To allow programmers to use libraries for different usages -> "Flexibility"
 */
#include <stdio.h>
#include <stdlib.h>  //for qsort()

/**
 * To create an array of pointers to functions and call each function using
 * its pointer from the array, you need to define the array of function pointers
 * and then use a loop to call each function. Here is the completed code:
 */
void f1(int var);
void f2(int var);
void f3(int var);

int compares(const void* l, const void* r);
/*
 * Remember sort() we talked about earlier? We can do the same with it.
 * Instead of ordering a set in an ascending way we
 * can do the opposite using our own comparison function as follows:
 */
int compare(const void* left, const void* right);

// A normal function with an int parameter and void return type
void fun(int arg);

int main(void) {
    printf("\n");
    printf("--------------------------------------------------------\n");
    // pf is a pointer to function fun()
    void (*pf)(int);
    pf = &fun;
    printf("We're about to call fun() using a pointer!\n");

    // Invoking fun() using pf
    (pf)(5);
    printf("Wow that was cool. Back to main now!\n\n");
    printf("\n");
    printf("--------------------------------------------------------\n");

    int (*cmp)(const void*, const void*);
    cmp = &compare;

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    qsort(array, sizeof(array) / sizeof(*array), sizeof(*array), cmp);

    size_t c = 0;
    while (c < sizeof(array) / sizeof(*array)) {
        printf("%d \t", array[c]);
        c++;
    }
    printf("\n");
    printf("--------------------------------------------------------\n");

    int values[] = {40, 10, 100, 90, 20, 25};
    int n;
    qsort(values, 6, sizeof(int), compares);
    for (n = 0; n < 6; n++) printf("%d \t", values[n]);
    printf("\n");
    printf("--------------------------------------------------------\n");
    /*
     * This line declares an array of function pointers named functions,
     * which can point to functions that take an int argument and return void.
     * The array is initialized with the addresses of f1, f2, and f3.
     */
    void (*functions[])(int) = {f1, f2, f3};

    /*
     * Inside the while loop, this line calls the function at index i in the functions array, * passing i as the
     * argument to the function. This effectively calls f1(0), f2(1), and f3(2)
     * during the loop iterations.
     *
     * This loop iterates from 0 to 2, calling each function in the array
     * with the current loop index as the argument.
     */
    int i = 0;
    while (i < 3) {
        functions[i](i);
        ++i;
    }
    printf("\n");
    printf("--------------------------------------------------------\n");

    return 0;
}
// A normal function with an int parameter and void return type
void fun(int arg) {
    printf("This is fun being called and arg is: %d\n", arg);
    printf("Whoops leaving the function now!\n");
}
/*
 * Remember sort() we talked about earlier? We can do the same with it.
 * Instead of ordering a set in an ascending way we
 * can do the opposite using our own comparison function as follows:
 */
int compare(const void* left, const void* right) {
    //...
    return (*(int*)right - *(int*)left);
}
int compares(const void* l, const void* r) {
    //..
    return (*(int*)l - *(int*)r);
}

/**
 * To create an array of pointers to functions and call each function using
 * its pointer from the array, you need to define the array of function pointers
 * and then use a loop to call each function. Here is the completed code:
 */
void f1(int var) {
    //..
    printf("this is f1 and var is: %d\n", var);
}
void f2(int var) {
    //..
    printf("this is f2 and var is: %d\n", var);
}
void f3(int var) {
    //..
    printf("this is f3 and var is: %d\n", var);
}
