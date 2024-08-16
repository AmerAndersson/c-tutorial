/**
 * Static
 * static is a keyword in the C programming language.
 * It can be used with variables and functions.

 * What is a static variable?
 * By default, variables are local to the scope in which they are defined.
 * Variables can be declared as static to increase their scope up to file containing them.
 * As a result, these variables can be accessed anywhere inside a file.
 *
 * We will see that count is not updated because it is removed from memory
 * as soon as the  function completes. If static is used however,
 * we get the desired result:
 *
 * What is a static function?
 * By default, functions are global in C. If we declare a function with static,
 * the scope of that function is reduced to the file containing it.
 *
 * A static function in C is a function whose scope is limited to the file in
 * which it is declared. This means that the function cannot be called or
 * referenced outside of that file, making it private to that file.

 * - Key points about static functions:

 * - Scope: The function is only visible within the file where it is defined.
 * - Linkage: It has internal linkage, meaning it cannot be linked from other files.
 *
 * Static vs Global?
 * While static variables have scope over the file containing them making
 * them accessible only inside a given file, global variables can be accessed
 * outside the file too.
 */
#include <stdio.h>

// Consider the following scenario – where we want
// to count the runners participating in a race:
int runner();

// If another file tries to use func(), it will result in a linker error.
// Static function definition
static void func(void);

// try to find the sum of some numbers by using the static keyword.
// Do not pass any variable representing the running total to the sum() function.
int sum(int num);

int main(void) {
    printf("Count: %d\n", runner());  // Output: Count: 1
    printf("Count: %d\n", runner());  // Output: Count: 2
    printf("Count: %d\n", runner());  // Output: Count: 3
    printf("Count: %d\n", runner());  // Output: Count: 4
    printf("Count: %d\n", runner());  // Output: Count: 5

    func();  // This works

    printf("%d\n", sum(55));  // 55 100 150
    printf("%d\n", sum(45));
    printf("%d\n", sum(50));
    return 0;
}
// Consider the following scenario – where we want
// to count the runners participating in a race:
// If static is used however, we get the desired result:
int runner() {
    static int count = 0;  // Static variable initialization
    count++;
    return count;
}

// If another file tries to use func(), it will result in a linker error.
// Static function definition
static void func(void) {
    printf("I am a static function.\n");
}

// try to find the sum of some numbers by using the static keyword.
// Do not pass any variable representing the running total to the sum() function.
int sum(int num) {
    static int total = 0;  // Static variable to hold the running total
    total += num;          // Add the current number to the running total
    return total;          // Return the running total
}