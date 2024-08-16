# Type Conversion

printf("Size sizeof(int) %d", sizeof(int))

C is a general-purpose programming language; therefore, it can be used to develop any type of applications. However, its ability to interact with the hardware makes it more suitable for developing system utilities, compilers and device drivers.

C is predominantly used in building embedded systems and networking applications. C is significantly faster as compared to languages like Java or Python because it is directly compiled to the machine code. Hence, it is used in development of gaming applications.

C is a versatile programming language that can be useful in development of a variety of software applications

Operating Systems

Language Compilers

Assemblers

Text Editors

Print Spoolers

Network Drivers

Modern Programs

Databases

Language Interpreters

Utilitie

- For attaining a high level of proficiency in C, you need to be able to master the features such as pointers, structures

## What are the key features of C Programming that make it unique?

C programming language has a lot of important features that make it a unique language.

Compiled language − Unlike many of the modern languages, C is a compiled language. The compiler builds a machine level code that is directly executed by the processor. Hence, it provides a better performance.

Pointer mechanism − C has the ability to directly access the computer’s memory through its pointer mechanism. This leads to its ability to control the hardware – a feature that is useful in developing system utilities and embedded systems.

Functions − You can develop an application in a structured and modular manner with the help of functions. The mechanism of calling functions can be easily plugged into one another.

Extensible − C has the feature of defining a new data type by combining any of the built-in types. You can thus simulate real-life data structures with C code.

Library functions − C software is bundled with a large library of utility functions and macros. There are library functions for IO operations, string handling, mathematical and statistical functions, time related functions etc.

```c
Include Header Files
Include necessary header files that contain declarations of functions, constants, and macros that can be used in one or more source code files. Some popular header files are as −

stdio.h − Provides input and output functions like printf and scanf.
#include <stdio.h>

stdlib.h − Contains functions involving memory allocation, rand function, and other utility functions.
#include <stdlib.h>

math.h − Includes mathematical functions like sqrt, sin, cos, etc.
#include <math.h>

string.h − Includes functions for manipulating strings, such as strcpy, strlen, etc.
#include <string.h>

ctype.h − Functions for testing and mapping characters, like isalpha, isdigit, etc.
#include <ctype.h>

stdbool.h − Defines the boolean data type and values true and false.
#include <stdbool.h>

time.h − Contains functions for working with date and time.
#include <time.h>

limits.h − Defines various implementation-specific limits on integer types.
#include <limits.h>

Macros and Constants
Define any macros or constants that will be used throughout the program. Macros and constants are optional.
```


Applications of C Language
The following are the applications of C language −

System Programming − C language is used to develop system software which are close to hardware such as operating systems, firmware, language translators, etc.

Embedded Systems − C language is used in embedded system programming for a wide range of devices such as microcontrollers, industrial controllers, etc.

Compiler and Interpreters − C language is very common to develop language compilers and interpreters.

Database Systems − Since C language is efficient and fast for low-level memory manipulation. It is used for developing DBMS and RDBMS engines.

Networking Software − C language is used to develop networking software such as protocols, routers, and network utilities.

Game Development − C language is widely used for developing games, gaming applications, and game engines.

Scientific and Mathematical Applications − C language is efficient in developing applications where scientific computing is required. Applications such as simulations, numerical analysis, and other scientific computations are usually developed in C language.

Text Editor and IDEs − C language is used for developing text editors and integrated development environments such as Vim and Emacs.

## Basic types
Here's a table containing commonly used types in C programming for quick access.
-----------------------------------
Type	Size (bytes)	Format Specifier
-----------------------------------
```c
int	at least 2, usually 4	%d, %i
char	1	%c
float	4	%f
double	8	%lf
short int	2 usually	%hd
unsigned int	at least 2, usually 4	%u
long int	at least 4, usually 8	%ld, %li
long long int	at least 8	%lld, %lli
unsigned long int	at least 4	%lu
unsigned long long int	at least 8	%llu
signed char	1	%c
unsigned char	1	%c
long double	at least 10, usually 12 or 16	%Lf
```
