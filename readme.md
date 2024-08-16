```c
-----------------------------------------
Sr.No.	            Macro & Description
-----------------------------------------
1	void va_start(va_list ap, parmN)
This macro enables access to variadic function arguments.

2	type va_arg(va_list ap, type)
This macro retrieves the next argument in the parameter list of the function with type type.

3	void va_end(va_list ap)
This macro allows to end traversal of the variadic function arguments.

4	void va_copy( va_list dest, va_list src )
This macro makes a copy of the variadic function arguments.
```
Explanation:
Static Variable: The static int total = 0; declaration ensures that total retains its value across multiple calls to the sum function.
Updating the Total: Each time the sum function is called, it adds the input num to the total.
Returning the Total: The updated total is then returned.
Output:
When you run this program, the output will be:

Copy code
55 100 150 
Here's how it works step-by-step:

On the first call sum(55), total is initialized to 0 and then updated to 55.
On the second call sum(45), total is now 55, and it is updated to 100 (55 + 45).
On the third call sum(50), total is now 100, and it is updated to 150 (100 + 50).
Thus, the function correctly maintains the running total using the static variable.

A callback function is a function passed into another function as an argument, which is then invoked inside the outer function to complete some kind of routine or action.


Summary
Pointers in C are versatile and powerful, enabling efficient memory management, dynamic memory allocation, the creation of complex data structures, and the implementation of function pointers. Their ability to directly manipulate memory addresses makes them an indispensable tool for C programmers.

These examples demonstrate the implementation functionality of pointers in various contexts:

Binary Tree: Using pointers to create and manage nodes and perform tree operations.
Linked List: Using pointers to create and manage nodes and perform list operations.
Dynamic Memory Allocation: Allocating and using dynamic memory for arrays.
String Manipulation: Using pointers to traverse and manipulate strings.
Each example shows how pointers enable efficient memory management and manipulation in C programming.


```
 the tree
        (1)
       /   \
    NULL    NULL


 2 and 3 become the left and right children of 1
        (1)
       /   \
      2    3
     /\   /\
    0  0  0  0


4 and 5 become the left and right children of 2
         (1)
        /     \
       (2)    (3)
      /   \   / \
     (4)  0  0  (5)
```

```c
1. A minus(-) sign tells left alignment.

2. A number after % specifies the minimum field width to be printed if the characters are less than the size of the width the remaining space is filled with space and if it is greater then it is printed as it is without truncation.

3. A period( . ) symbol separates field width with precision.
Precision tells the minimum number of digits in an integer, the maximum number of characters in a string, and the number of digits after the decimal part in a floating value.

// C Program to demonstrate the formatting methods.
#include <stdio.h>
int main()
{
    char str[] = "Hello, World";
    printf("%20s\n", str);
    printf("%-20s\n", str);
    printf("%20.5s\n", str);
    printf("%-20.5s\n", str);
    return 0;
}

%x format specifier is used for printing unsigned integers in hexadecimal format
```
```c
gcc -std=c17 -Wall -Wextra -pedantic-errors main.c -o  main
```