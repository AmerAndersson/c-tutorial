To compile the file `hello.c` with `gcc`, use the following command:
`gcc -Wall hello.c -o hello`

This compiles the source code in `hello.c` to machine code and stores it in an executable file `hello`.The output file for the machine code is specified using the `-o` option. This option is usually given as the last argument on the command line. If it is omitted, the output is written to a default file called `a.out`.

Note that if a file with the same name as the executable file already exists in the current directory it will be overwritten. The option `-Wall` turns on all the most commonly-used compiler `warnings—it is recommended that you always use this option!` There are many other warning options which will be discussed in later chapters, but `-Wall` is the most important. GCC will not produce any warnings unless they are enabled. Compiler warnings are an essential aid in detecting problems when programming in C and C++.
In this case, the compiler does not produce any warnings with the ‘-Wall’ option, since the program is completely valid. Source code which does not produce any warnings is said to compile cleanly.


Clearly, it is very dangerous to develop a program without checking for compiler warnings. If there are any functions which are not used correctly they can cause the program to crash, or to produce incorrect results. Turning on the compiler warning option ‘-Wall’ will catch many of the commonest errors which occur in C programming.

## Compiling multiple source files
Incidentally, the difference between the two forms of the include state- ment #include "FILE.h" and #include <FILE.h> is that the former searches for ‘FILE.h’ in the current directory before looking in the sys- tem header file directories. The include statement #include <FILE.h> searches the system header files, but does not look in the current direc- tory by default

To compile these source files with gcc, use the following command:
 $ gcc -Wall main.c hello.c -o hello 

## Compiling files independently 
If a program is stored in a single file then any change to an individual function requires the whole program to be recompiled to produce a new executable. The recompilation of large source files can be very time- consuming.

When programs are stored in independent source files, only the files which have changed need to be recompiled after the source code has been modified. In this approach, the source files are compiled separately and then linked together—a two stage process. In the first stage, a file is compiled without creating an executable. The result is referred to as an object file, and has the extension ‘.o’ when using GCC.

In the second stage, the object files are merged together by a separate program called the linker. The linker combines all the object files together to create a single executable.
An object file contains machine code where any references to the mem- ory addresses of functions (or variables) in other files are left undefined. This allows source files to be compiled without direct reference to each other. The linker fills in these missing addresses when it produces the executable.

## Creating object files from source files

The command-line option ‘-c’ is used to compile a source file to an object file. For example, the following command will compile the source file ‘main.c’ to an object file:
$ gcc -Wall -c main.c 

## Compiling 
gcc -Wall -c main.c 
gcc -Wall -c hello.c 

##  Link order of object files
gcc main.o hello.o -o hello 

./hello


This produces an object file ‘main.o’ containing the machine code for the main function. It contains a reference to the external function hello, but the corresponding memory address is left undefined in the object file at this stage (it will be filled in later by linking).

The corresponding command for compiling the hello function in the source file ‘hello.c’ is:
$ gcc -Wall -c hello.c 

This produces the object file ‘hello.o’.
Note that there is no need to use the option ‘-o’ to specify the name of the output file in this case. When compiling with ‘-c’ the compiler automatically creates an object file whose name is the same as the source file, with ‘.o’ instead of the original extension. 

There is no need to put the header file ‘hello.h’ on the command line, since it is automatically included by the #include statements in ‘main.c’ and ‘hello.c’. 

## Creating executables from object files
The final step in creating an executable file is to use gcc to link the object files together and fill in the missing addresses of external functions. To link object files together, they are simply listed on the command line:
    $ gcc main.o hello.o -o hello 

This is one of the few occasions where there is no need to use the ‘-Wall’ warning option, since the individual source files have already been success- fully compiled to object code. Once the source files have been compiled, linking is an unambiguous process which either succeeds or fails (it fails only if there are references which cannot be resolved).

To perform the linking step gcc uses the linker ld, which is a separate program. On GNU systems the GNU linker, GNU ld, is used. Other systems may use the GNU linker with GCC, or may have their own linkers. The linker itself will be discussed later (see Chapter 11 [How the compiler works], page 81). By running the linker, gcc creates an executable file from the object files.
The resulting executable file can now be run:
    $ ./hello
    Hello, world!

It produces the same output as the version of the program using a single source file in the previous section.

## Link order of object files
On Unix-like systems, the traditional behavior of compilers and linkers is to search for external functions from left to right in the object files specified on the command line. This means that the object file which contains the definition of a function should appear after any files which call that function.
In this case, the file ‘hello.o’ containing the function hello should be specified after ‘main.o’ itself, since main calls hello:
$ gcc main.o hello.o -o hello (correct order)

With some compilers or linkers the opposite ordering would result in an
error,
$ cc hello_fn.o main.o -o hello (incorrect order) main.o: In function ‘main’:
main.o(.text+0xf): undefined reference to ‘hello’
because there is no object file containing hello after ‘main.o’.
Most current compilers and linkers will search all object files, regard- less of order, but since not all compilers do this it is best to follow the convention of ordering object files from left to right. 

This is worth keeping in mind if you ever encounter unexpected prob- lems with undefined references, and all the necessary object files appear to be present on the command line.



## Recompiling and relinking
To show how source files can be compiled independently we will edit the main program ‘main.c’ and modify it to print a greeting to everyone instead of world:
      
The updated file ‘main.c’ can now be recompiled with the following com- mand:
    $ gcc -Wall -c main.c
This produces a new object file ‘main.o’. There is no need to create a new object file for ‘hello.c’, since that file and the related files that it depends on, such as header files, have not changed.
The new object file can be relinked with the hello function to create a new executable file:
$ gcc main.o hello.o -o hello
The resulting executable ‘hello’ now uses the new main function to produce the following output:
 $ ./hello
    Hello, everyone!
Note that only the file ‘main.c’ has been recompiled, and then relinked with the existing object file for the hello function. If the file ‘hello_fn.c’ had been modified instead, we could have recompiled ‘hello_fn.c’ to create a new object file ‘hello_fn.o’ and relinked this with the existing file ‘main.o’.(1)
In general, linking is faster than compilation—in a large project with many source files, recompiling only those that have been modified can make a significant saving. The process of recompiling only the modified
files in a project can be automated using GNU Make (see [Further read- ing], page 91).
(1) If the prototype of a function has changed, it is necessary to modify and recompile all of the other source files which use it.

## Linking with external libraries
A library is a collection of precompiled object files which can be linked into programs. The most common use of libraries is to provide system functions, such as the square root function sqrt found in the C math library.
Libraries are typically stored in special archive files with the extension ‘.a’, referred to as static libraries. They are created from object files with a separate tool, the GNU archiver ar, and used by the linker to resolve references to functions at compile-time. We will see later how to create libraries using the ar command (see Chapter 10 [Compiler-related tools], page 73). For simplicity, only static libraries are covered in this section— dynamic linking at runtime using shared libraries will be described in the next chapter.
The standard system libraries are usually found in the directories ‘/usr/lib’ and ‘/lib’.(2) For example, the C math library is typically stored in the file ‘/usr/lib/libm.a’ on Unix-like systems. The corre- sponding prototype declarations for the functions in this library are given in the header file ‘/usr/include/math.h’. The C standard library itself is stored in ‘/usr/lib/libc.a’ and contains functions specified in the ANSI/ISO C standard, such as ‘printf’—this library is linked by default for every C program.
Here is an example program which makes a call to the external function sqrt in the math library ‘libm.a’:

On systems supporting both 64 and 32-bit executables the 64-bit versions of the libraries will often be stored in ‘/usr/lib64’ and ‘/lib64’, with the 32-bit versions in ‘/usr/lib’ and ‘/lib’.

## Setting search paths
In the last chapter, we saw how to link to a program with functions in the C math library ‘libm.a’, using the short-cut option ‘-lm’ and the header file ‘math.h’.
A common problem when compiling a program using library header files is the error:
FILE.h: No such file or directory
This occurs if a header file is not present in the standard include file
directories used by gcc. A similar problem can occur for libraries: /usr/bin/ld: cannot find library
This happens if a library used for linking is not present in the standard library directories used by gcc.
By default, gcc searches the following directories for header files: /usr/local/include/
    /usr/include/
and the following directories for libraries:
    /usr/local/lib/
    /usr/lib/
The list of directories for header files is often referred to as the include path, and the list of directories for libraries as the library search path or link path.
The directories on these paths are searched in order, from first to last in the two lists above.(1) For example, a header file found in ‘/usr/local/include’ takes precedence over a file with the same name in ‘/usr/include’. Similarly, a library found in ‘/usr/local/lib’ takes precedence over a library with the same name in ‘/usr/lib’.

The compiler options ‘-I’ and ‘-L’ add new directories to the beginning of the include path and library search path respectively 


## Environment variables
The search paths for header files and libraries can also be controlled through environment variables in the shell. These may be set au- tomatically for each session using the appropriate login file, such as ‘.bash_profile’.
Additional directories can be added to the include path using the envi- ronment variable C_INCLUDE_PATH (for C header files) or CPLUS_INCLUDE_ PATH (for C++ header files). For example, the following commands will add ‘/opt/gdbm-1.8.3/include’ to the include path when compiling C programs:
    $ C_INCLUDE_PATH=/opt/gdbm-1.8.3/include
    $ export C_INCLUDE_PATH
This directory will be searched after any directories specified on the com- mand line with the option ‘-I’, and before the standard default directories ‘/usr/local/include’ and ‘/usr/include’. The shell command export is needed to make the environment variable available to programs out- side the shell itself, such as the compiler—it is only needed once for each
22 An Introduction to GCC
variable in each shell session, and can also be set in the appropriate login file.
Similarly, additional directories can be added to the link path using the environment variable LIBRARY_PATH. For example, the following com- mands will add ‘/opt/gdbm-1.8.3/lib’ to the link path:
    $ LIBRARY_PATH=/opt/gdbm-1.8.3/lib
    $ export LIBRARY_PATH
This directory will be searched after any directories specified on the com- mand line with the option ‘-L’, and before the standard default directories ‘/usr/local/lib’ and ‘/usr/lib’.
With the environment variable settings given above the program ‘dbmain.c’ can be compiled without the ‘-I’ and ‘-L’ options,
    $ gcc -Wall dbmain.c -lgdbm
because the default paths now use the directories specified in the environ- ment variables C_INCLUDE_PATH and LIBRARY_PATH.



# .bash_profile
C_INCLUDE_PATH (for C header files)
CPLUS_INCLUDE_ PATH (for C++ header files)


$ C_INCLUDE_PATH=/opt/gdbm-1.8.3/include
$ export C_INCLUDE_PATH

# LIBRARY_PATH

$ LIBRARY_PATH=/opt/gdbm-1.8.3/lib
$ export LIBRARY_PATH 

# Extended search paths
Following the standard Unix convention for search paths, several direc- tories can be specified together in an environment variable as a colon separated list:

DIR1 :DIR2 :DIR3 :...
The directories are then searched in order from left to right. A single dot
`.` can be used to specify the current directory.(2)
For example, the following settings create default include and link paths for packages installed in the current directory ‘.’ and the ‘include’ and ‘lib’ directories under ‘/opt/gdbm-1.8.3’ and ‘/net’ respectively:
    $ C_INCLUDE_PATH=.:/opt/gdbm-1.8.3/include:/net/include
    $ LIBRARY_PATH=.:/opt/gdbm-1.8.3/lib:/net/lib

## Shared libraries and static libraries
The simplest way to set the load path is through the environment variable LD_LIBRARY_PATH. For example, the following commands set the load path to ‘/opt/gdbm-1.8.3/lib’ so that ‘libgdbm.so’ can be found:
    $ LD_LIBRARY_PATH=/opt/gdbm-1.8.3/lib
    $ export LD_LIBRARY_PATH
    $ ./a.out
    Storing key-value pair... done.
The executable now runs successfully, prints its message and creates a DBM file called ‘test’ containing the key-value pair ‘testkey’ and ‘testvalue’.
To save typing, the LD_LIBRARY_PATH environment variable can be set once for each session in the appropriate login file, such as ‘.bash_profile’ for the GNU Bash shell.
Several shared library directories can be placed in the load path, as a colon separated list DIR1:DIR2:DIR3:...:DIRN. For example, the fol-


lowing command sets the load path to use the ‘lib’ directories under
‘/opt/gdbm-1.8.3’ and ‘/opt/gtk-1.4’:
$ LD_LIBRARY_PATH=/opt/gdbm-1.8.3/lib:/opt/gtk-1.4/lib
    $ export LD_LIBRARY_PATH
If the load path contains existing entries, it can be extended using the syn- tax LD_LIBRARY_PATH=NEWDIRS:$LD_LIBRARY_PATH. For example, the following command adds the directory ‘/opt/gsl-1.5/lib’ to the load path shown above:
    $ LD_LIBRARY_PATH=/opt/gsl-1.5/lib:$LD_LIBRARY_PATH
    $ echo $LD_LIBRARY_PATH
    /opt/gsl-1.5/lib:/opt/gdbm-1.8.3/lib:/opt/gtk-1.4/lib


It is possible for the system administrator to set the LD_LIBRARY_PATH variable for all users, by adding it to a default login script, such as ‘/etc/profile’. On GNU systems, a system-wide path can also be de- fined in the loader configuration file ‘/etc/ld.so.conf’.
Alternatively, static linking can be forced with the ‘-static’ option to gcc to avoid the use of shared libraries:
    $ gcc -Wall -static -I/opt/gdbm-1.8.3/include/
        -L/opt/gdbm-1.8.3/lib/ dbmain.c -lgdbm
This creates an executable linked with the static library ‘libgdbm.a’ which can be run without setting the environment variable LD_LIBRARY_ PATH or putting shared libraries in the default directories:

    $ ./a.out
    Storing key-value pair... done.


As noted earlier, it is also possible to link directly with individual library files by specifying the full path to the library on the command line. For example, the following command will link directly with the static library ‘libgdbm.a’,
    $ gcc -Wall -I/opt/gdbm-1.8.3/include
        dbmain.c /opt/gdbm-1.8.3/lib/libgdbm.a
and the command below will link with the shared library file ‘libgdbm.so’: $ gcc -Wall -I/opt/gdbm-1.8.3/include
        dbmain.c /opt/gdbm-1.8.3/lib/libgdbm.so
In the latter case it is still necessary to set the library load path when running the executable.


## -pedantic

The flags `-ansi -Wextra -pedantic-errors` and `-ansi -Wextra -pedantic` are used with GCC (GNU Compiler Collection) to control the behavior of the compiler, particularly in how it handles standards compliance and warnings.

Here's a breakdown of each flag and the differences between the two sets of flags:

1. **`-ansi`**:
   - This flag instructs the compiler to adhere to the ANSI C standard, which is equivalent to the ISO C90 standard. It disables certain GNU extensions that might be available by default in the compiler.

2. **`-Wextra`**:
   - This flag enables additional warning messages that are not covered by the default `-Wall` flag. These warnings help catch potential issues in the code that may not necessarily be errors but are often best practices to address.

3. **`-pedantic`**:
   - This flag enforces strict compliance with the ISO C and ISO C++ standards. It causes the compiler to issue warnings for any code that does not adhere strictly to these standards, even if the code might be acceptable as an extension in some compilers.

4. **`-pedantic-errors`**:
   - This flag is similar to `-pedantic` but is more stringent. It not only issues warnings for non-standard code but also treats these warnings as errors. This means that any code that does not comply strictly with the standards will cause the compilation to fail.

### Differences

- **Warnings vs. Errors**:
  - `-ansi -Wextra -pedantic`: This set of flags will cause the compiler to generate warnings for any code that does not comply with the strict standards, but the compilation process will continue, and the output will still be generated (unless there are other errors).
  - `-ansi -Wextra -pedantic-errors`: This set of flags will cause the compiler to treat these warnings as errors, halting the compilation process if any non-standard code is detected.

### Summary

- Use `-ansi -Wextra -pedantic` if you want to ensure that your code is compliant with the standards and you want to be informed about non-compliant code through warnings, but you still want the compilation to succeed.
- Use `-ansi -Wextra -pedantic-errors` if you want to enforce strict compliance with the standards to the point that any deviation will stop the compilation process, ensuring that the code is strictly standard-compliant.


## Defining macros

The gcc option ‘-DNAME’ defines a preprocessor macro NAME from the command line. If the program above is compiled with the command-line option ‘-DTEST’, the macro TEST will be defined and the resulting executable will print both messages:
     $ gcc -Wall -DTEST dtest.c
     $ ./a.out
     Test mode
     Running...
If the same program is compiled without the ‘-D’ option then the “Test mode” message is omitted from the source code after preprocessing, and the final executable does not include the code for it:
     $ gcc -Wall dtest.c
     $ ./a.out
     Running...
gcc -Wall -DTEST test.c

##Define 

➜ cpp -dM /dev/null
#define _LP64 1
#define __APPLE_CC__ 6000
#define __APPLE__ 1
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_CONSUME 1
#define __ATOMIC_RELAXED 0
#define __ATOMIC_RELEASE 3
#define __ATOMIC_SEQ_CST 5
#define __BIGGEST_ALIGNMENT__ 16
#define __BITINT_MAXWIDTH__ 128
#define __BLOCKS__ 1
#define __BOOL_WIDTH__ 8
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#define __CHAR16_TYPE__ unsigned short
#define __CHAR32_TYPE__ unsigned int
#define __CHAR_BIT__ 8
#define __CLANG_ATOMIC_BOOL_LOCK_FREE 2
#define __CLANG_ATOMIC_CHAR16_T_LOCK_FREE 2
#define __CLANG_ATOMIC_CHAR32_T_LOCK_FREE 2
#define __CLANG_ATOMIC_CHAR_LOCK_FREE 2
#define __CLANG_ATOMIC_INT_LOCK_FREE 2
#define __CLANG_ATOMIC_LLONG_LOCK_FREE 2
#define __CLANG_ATOMIC_LONG_LOCK_FREE 2
#define __CLANG_ATOMIC_POINTER_LOCK_FREE 2
#define __CLANG_ATOMIC_SHORT_LOCK_FREE 2
#define __CLANG_ATOMIC_WCHAR_T_LOCK_FREE 2
#define __CONSTANT_CFSTRINGS__ 1
#define __DBL_DECIMAL_DIG__ 17
#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
#define __DBL_DIG__ 15
#define __DBL_EPSILON__ 2.2204460492503131e-16
#define __DBL_HAS_DENORM__ 1
#define __DBL_HAS_INFINITY__ 1
#define __DBL_HAS_QUIET_NAN__ 1
#define __DBL_MANT_DIG__ 53
#define __DBL_MAX_10_EXP__ 308
#define __DBL_MAX_EXP__ 1024
#define __DBL_MAX__ 1.7976931348623157e+308
#define __DBL_MIN_10_EXP__ (-307)
#define __DBL_MIN_EXP__ (-1021)
#define __DBL_MIN__ 2.2250738585072014e-308
#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
#define __DYNAMIC__ 1
#define __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ 140000
#define __ENVIRONMENT_OS_VERSION_MIN_REQUIRED__ 140000
#define __FINITE_MATH_ONLY__ 0
#define __FLT16_DECIMAL_DIG__ 5
#define __FLT16_DENORM_MIN__ 5.9604644775390625e-8F16
#define __FLT16_DIG__ 3
#define __FLT16_EPSILON__ 9.765625e-4F16
#define __FLT16_HAS_DENORM__ 1
#define __FLT16_HAS_INFINITY__ 1
#define __FLT16_HAS_QUIET_NAN__ 1
#define __FLT16_MANT_DIG__ 11
#define __FLT16_MAX_10_EXP__ 4
#define __FLT16_MAX_EXP__ 16
#define __FLT16_MAX__ 6.5504e+4F16
#define __FLT16_MIN_10_EXP__ (-4)
#define __FLT16_MIN_EXP__ (-13)
#define __FLT16_MIN__ 6.103515625e-5F16
#define __FLT_DECIMAL_DIG__ 9
#define __FLT_DENORM_MIN__ 1.40129846e-45F
#define __FLT_DIG__ 6
#define __FLT_EPSILON__ 1.19209290e-7F
#define __FLT_HAS_DENORM__ 1
#define __FLT_HAS_INFINITY__ 1
#define __FLT_HAS_QUIET_NAN__ 1
#define __FLT_MANT_DIG__ 24
#define __FLT_MAX_10_EXP__ 38
#define __FLT_MAX_EXP__ 128
#define __FLT_MAX__ 3.40282347e+38F
#define __FLT_MIN_10_EXP__ (-37)
#define __FLT_MIN_EXP__ (-125)
#define __FLT_MIN__ 1.17549435e-38F
#define __FLT_RADIX__ 2
#define __FXSR__ 1
#define __GCC_ASM_FLAG_OUTPUTS__ 1
#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
#define __GCC_ATOMIC_INT_LOCK_FREE 2
#define __GCC_ATOMIC_LLONG_LOCK_FREE 2
#define __GCC_ATOMIC_LONG_LOCK_FREE 2
#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
#define __GCC_HAVE_DWARF2_CFI_ASM 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1
#define __GNUC_MINOR__ 2
#define __GNUC_PATCHLEVEL__ 1
#define __GNUC_STDC_INLINE__ 1
#define __GNUC__ 4
#define __GXX_ABI_VERSION 1002
#define __INT16_C_SUFFIX__
#define __INT16_FMTd__ "hd"
#define __INT16_FMTi__ "hi"
#define __INT16_MAX__ 32767
#define __INT16_TYPE__ short
#define __INT32_C_SUFFIX__
#define __INT32_FMTd__ "d"
#define __INT32_FMTi__ "i"
#define __INT32_MAX__ 2147483647
#define __INT32_TYPE__ int
#define __INT64_C_SUFFIX__ LL
#define __INT64_FMTd__ "lld"
#define __INT64_FMTi__ "lli"
#define __INT64_MAX__ 9223372036854775807LL
#define __INT64_TYPE__ long long int
#define __INT8_C_SUFFIX__
#define __INT8_FMTd__ "hhd"
#define __INT8_FMTi__ "hhi"
#define __INT8_MAX__ 127
#define __INT8_TYPE__ signed char
#define __INTMAX_C_SUFFIX__ L
#define __INTMAX_FMTd__ "ld"
#define __INTMAX_FMTi__ "li"
#define __INTMAX_MAX__ 9223372036854775807L
#define __INTMAX_TYPE__ long int
#define __INTMAX_WIDTH__ 64
#define __INTPTR_FMTd__ "ld"
#define __INTPTR_FMTi__ "li"
#define __INTPTR_MAX__ 9223372036854775807L
#define __INTPTR_TYPE__ long int
#define __INTPTR_WIDTH__ 64
#define __INT_FAST16_FMTd__ "hd"
#define __INT_FAST16_FMTi__ "hi"
#define __INT_FAST16_MAX__ 32767
#define __INT_FAST16_TYPE__ short
#define __INT_FAST16_WIDTH__ 16
#define __INT_FAST32_FMTd__ "d"
#define __INT_FAST32_FMTi__ "i"
#define __INT_FAST32_MAX__ 2147483647
#define __INT_FAST32_TYPE__ int
#define __INT_FAST32_WIDTH__ 32
#define __INT_FAST64_FMTd__ "lld"
#define __INT_FAST64_FMTi__ "lli"
#define __INT_FAST64_MAX__ 9223372036854775807LL
#define __INT_FAST64_TYPE__ long long int
#define __INT_FAST64_WIDTH__ 64
#define __INT_FAST8_FMTd__ "hhd"
#define __INT_FAST8_FMTi__ "hhi"
#define __INT_FAST8_MAX__ 127
#define __INT_FAST8_TYPE__ signed char
#define __INT_FAST8_WIDTH__ 8
#define __INT_LEAST16_FMTd__ "hd"
#define __INT_LEAST16_FMTi__ "hi"
#define __INT_LEAST16_MAX__ 32767
#define __INT_LEAST16_TYPE__ short
#define __INT_LEAST16_WIDTH__ 16
#define __INT_LEAST32_FMTd__ "d"
#define __INT_LEAST32_FMTi__ "i"
#define __INT_LEAST32_MAX__ 2147483647
#define __INT_LEAST32_TYPE__ int
#define __INT_LEAST32_WIDTH__ 32
#define __INT_LEAST64_FMTd__ "lld"
#define __INT_LEAST64_FMTi__ "lli"
#define __INT_LEAST64_MAX__ 9223372036854775807LL
#define __INT_LEAST64_TYPE__ long long int
#define __INT_LEAST64_WIDTH__ 64
#define __INT_LEAST8_FMTd__ "hhd"
#define __INT_LEAST8_FMTi__ "hhi"
#define __INT_LEAST8_MAX__ 127
#define __INT_LEAST8_TYPE__ signed char
#define __INT_LEAST8_WIDTH__ 8
#define __INT_MAX__ 2147483647
#define __INT_WIDTH__ 32
#define __LAHF_SAHF__ 1
#define __LDBL_DECIMAL_DIG__ 21
#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
#define __LDBL_DIG__ 18
#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
#define __LDBL_HAS_DENORM__ 1
#define __LDBL_HAS_INFINITY__ 1
#define __LDBL_HAS_QUIET_NAN__ 1
#define __LDBL_MANT_DIG__ 64
#define __LDBL_MAX_10_EXP__ 4932
#define __LDBL_MAX_EXP__ 16384
#define __LDBL_MAX__ 1.18973149535723176502e+4932L
#define __LDBL_MIN_10_EXP__ (-4931)
#define __LDBL_MIN_EXP__ (-16381)
#define __LDBL_MIN__ 3.36210314311209350626e-4932L
#define __LITTLE_ENDIAN__ 1
#define __LLONG_WIDTH__ 64
#define __LONG_LONG_MAX__ 9223372036854775807LL
#define __LONG_MAX__ 9223372036854775807L
#define __LONG_WIDTH__ 64
#define __LP64__ 1
#define __MACH__ 1
#define __MMX__ 1
#define __NO_INLINE__ 1
#define __NO_MATH_ERRNO__ 1
#define __NO_MATH_INLINES 1
#define __OBJC_BOOL_IS_BOOL 0
#define __OPENCL_MEMORY_SCOPE_ALL_SVM_DEVICES 3
#define __OPENCL_MEMORY_SCOPE_DEVICE 2
#define __OPENCL_MEMORY_SCOPE_SUB_GROUP 4
#define __OPENCL_MEMORY_SCOPE_WORK_GROUP 1
#define __OPENCL_MEMORY_SCOPE_WORK_ITEM 0
#define __ORDER_BIG_ENDIAN__ 4321
#define __ORDER_LITTLE_ENDIAN__ 1234
#define __ORDER_PDP_ENDIAN__ 3412
#define __PIC__ 2
#define __POINTER_WIDTH__ 64
#define __PRAGMA_REDEFINE_EXTNAME 1
#define __PTRDIFF_FMTd__ "ld"
#define __PTRDIFF_FMTi__ "li"
#define __PTRDIFF_MAX__ 9223372036854775807L
#define __PTRDIFF_TYPE__ long int
#define __PTRDIFF_WIDTH__ 64
#define __REGISTER_PREFIX__
#define __SCHAR_MAX__ 127
#define __SEG_FS 1
#define __SEG_GS 1
#define __SHRT_MAX__ 32767
#define __SHRT_WIDTH__ 16
#define __SIG_ATOMIC_MAX__ 2147483647
#define __SIG_ATOMIC_WIDTH__ 32
#define __SIZEOF_DOUBLE__ 8
#define __SIZEOF_FLOAT__ 4
#define __SIZEOF_INT128__ 16
#define __SIZEOF_INT__ 4
#define __SIZEOF_LONG_DOUBLE__ 16
#define __SIZEOF_LONG_LONG__ 8
#define __SIZEOF_LONG__ 8
#define __SIZEOF_POINTER__ 8
#define __SIZEOF_PTRDIFF_T__ 8
#define __SIZEOF_SHORT__ 2
#define __SIZEOF_SIZE_T__ 8
#define __SIZEOF_WCHAR_T__ 4
#define __SIZEOF_WINT_T__ 4
#define __SIZE_FMTX__ "lX"
#define __SIZE_FMTo__ "lo"
#define __SIZE_FMTu__ "lu"
#define __SIZE_FMTx__ "lx"
#define __SIZE_MAX__ 18446744073709551615UL
#define __SIZE_TYPE__ long unsigned int
#define __SIZE_WIDTH__ 64
#define __SSE2_MATH__ 1
#define __SSE2__ 1
#define __SSE3__ 1
#define __SSE4_1__ 1
#define __SSE_MATH__ 1
#define __SSE__ 1
#define __SSP__ 1
#define __SSSE3__ 1
#define __STDC_HOSTED__ 1
#define __STDC_NO_THREADS__ 1
#define __STDC_UTF_16__ 1
#define __STDC_UTF_32__ 1
#define __STDC_VERSION__ 201710L
#define __UINT16_C_SUFFIX__
#define __UINT16_FMTX__ "hX"
#define __UINT16_FMTo__ "ho"
#define __UINT16_FMTu__ "hu"
#define __UINT16_FMTx__ "hx"
#define __UINT16_MAX__ 65535
#define __UINT16_TYPE__ unsigned short
#define __UINT32_C_SUFFIX__ U
#define __UINT32_FMTX__ "X"
#define __UINT32_FMTo__ "o"
#define __UINT32_FMTu__ "u"
#define __UINT32_FMTx__ "x"
#define __UINT32_MAX__ 4294967295U
#define __UINT32_TYPE__ unsigned int
#define __UINT64_C_SUFFIX__ ULL
#define __UINT64_FMTX__ "llX"
#define __UINT64_FMTo__ "llo"
#define __UINT64_FMTu__ "llu"
#define __UINT64_FMTx__ "llx"
#define __UINT64_MAX__ 18446744073709551615ULL
#define __UINT64_TYPE__ long long unsigned int
#define __UINT8_C_SUFFIX__
#define __UINT8_FMTX__ "hhX"
#define __UINT8_FMTo__ "hho"
#define __UINT8_FMTu__ "hhu"
#define __UINT8_FMTx__ "hhx"
#define __UINT8_MAX__ 255
#define __UINT8_TYPE__ unsigned char
#define __UINTMAX_C_SUFFIX__ UL
#define __UINTMAX_FMTX__ "lX"
#define __UINTMAX_FMTo__ "lo"
#define __UINTMAX_FMTu__ "lu"
#define __UINTMAX_FMTx__ "lx"
#define __UINTMAX_MAX__ 18446744073709551615UL
#define __UINTMAX_TYPE__ long unsigned int
#define __UINTMAX_WIDTH__ 64
#define __UINTPTR_FMTX__ "lX"
#define __UINTPTR_FMTo__ "lo"
#define __UINTPTR_FMTu__ "lu"
#define __UINTPTR_FMTx__ "lx"
#define __UINTPTR_MAX__ 18446744073709551615UL
#define __UINTPTR_TYPE__ long unsigned int
#define __UINTPTR_WIDTH__ 64
#define __UINT_FAST16_FMTX__ "hX"
#define __UINT_FAST16_FMTo__ "ho"
#define __UINT_FAST16_FMTu__ "hu"
#define __UINT_FAST16_FMTx__ "hx"
#define __UINT_FAST16_MAX__ 65535
#define __UINT_FAST16_TYPE__ unsigned short
#define __UINT_FAST32_FMTX__ "X"
#define __UINT_FAST32_FMTo__ "o"
#define __UINT_FAST32_FMTu__ "u"
#define __UINT_FAST32_FMTx__ "x"
#define __UINT_FAST32_MAX__ 4294967295U
#define __UINT_FAST32_TYPE__ unsigned int
#define __UINT_FAST64_FMTX__ "llX"
#define __UINT_FAST64_FMTo__ "llo"
#define __UINT_FAST64_FMTu__ "llu"
#define __UINT_FAST64_FMTx__ "llx"
#define __UINT_FAST64_MAX__ 18446744073709551615ULL
#define __UINT_FAST64_TYPE__ long long unsigned int
#define __UINT_FAST8_FMTX__ "hhX"
#define __UINT_FAST8_FMTo__ "hho"
#define __UINT_FAST8_FMTu__ "hhu"
#define __UINT_FAST8_FMTx__ "hhx"
#define __UINT_FAST8_MAX__ 255
#define __UINT_FAST8_TYPE__ unsigned char
#define __UINT_LEAST16_FMTX__ "hX"
#define __UINT_LEAST16_FMTo__ "ho"
#define __UINT_LEAST16_FMTu__ "hu"
#define __UINT_LEAST16_FMTx__ "hx"
#define __UINT_LEAST16_MAX__ 65535
#define __UINT_LEAST16_TYPE__ unsigned short
#define __UINT_LEAST32_FMTX__ "X"
#define __UINT_LEAST32_FMTo__ "o"
#define __UINT_LEAST32_FMTu__ "u"
#define __UINT_LEAST32_FMTx__ "x"
#define __UINT_LEAST32_MAX__ 4294967295U
#define __UINT_LEAST32_TYPE__ unsigned int
#define __UINT_LEAST64_FMTX__ "llX"
#define __UINT_LEAST64_FMTo__ "llo"
#define __UINT_LEAST64_FMTu__ "llu"
#define __UINT_LEAST64_FMTx__ "llx"
#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
#define __UINT_LEAST64_TYPE__ long long unsigned int
#define __UINT_LEAST8_FMTX__ "hhX"
#define __UINT_LEAST8_FMTo__ "hho"
#define __UINT_LEAST8_FMTu__ "hhu"
#define __UINT_LEAST8_FMTx__ "hhx"
#define __UINT_LEAST8_MAX__ 255
#define __UINT_LEAST8_TYPE__ unsigned char
#define __USER_LABEL_PREFIX__ _
#define __VERSION__ "Apple LLVM 15.0.0 (clang-1500.3.9.4)"
#define __WCHAR_MAX__ 2147483647
#define __WCHAR_TYPE__ int
#define __WCHAR_WIDTH__ 32
#define __WINT_MAX__ 2147483647
#define __WINT_TYPE__ int
#define __WINT_WIDTH__ 32
#define __amd64 1
#define __amd64__ 1
#define __apple_build_version__ 15000309
#define __block __attribute__((__blocks__(byref)))
#define __clang__ 1
#define __clang_literal_encoding__ "UTF-8"
#define __clang_major__ 15
#define __clang_minor__ 0
#define __clang_patchlevel__ 0
#define __clang_version__ "15.0.0 (clang-1500.3.9.4)"
#define __clang_wide_literal_encoding__ "UTF-32"
#define __code_model_small__ 1
#define __core2 1
#define __core2__ 1
#define __llvm__ 1
#define __nonnull _Nonnull
#define __null_unspecified _Null_unspecified
#define __nullable _Nullable
#define __pic__ 2
#define __seg_fs __attribute__((address_space(257)))
#define __seg_gs __attribute__((address_space(256)))
#define __strong
#define __tune_core2__ 1
#define __unsafe_unretained
#define __weak __attribute__((objc_gc(weak)))
#define __x86_64 1
#define __x86_64__ 1




/*
 * Here is a simple program containing an invalid memory access bug,
 * which we will use to produce a core file:
 * gcc -c -save-temps core.c
 *
 * In the GNU Bash shell the command ulimit -c controls the maximum size of core files.
 * If the size limit is zero, no core files are produced.
 * The current size limit can be shown by typing the following command.
 * ulimit -c
 *  ulimit -c unlimited
 */