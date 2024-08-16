# getchar & putchar

```c
 function copyInputToOutput
 A simple C function that uses `getchar` and `putchar`. function that reads characters from input and prints them to output until it encounters the end-of-file (EOF) character:

 - `getchar()` reads the next character from the standard input (typically the keyboard) and returns it as an `int`.

- The expression `(c = getchar()) != EOF` reads a character, assigns it to `c`, and then checks if `c` is not equal to `EOF`. `EOF` is a special constant that indicates the end of input.

 - If `c` is not `EOF`, the loop body executes `putchar(c)`, which prints the character stored in `c` to the standard output (typically the screen).

- This process continues until `getchar()` returns `EOF`, indicating that there are no more characters to read.

Summary:
- `getchar()` reads a single character from the input.
- `putchar()` writes a single character to the output.

The problem is distinguishing the end of input from valid data. The solution is that getchar returns a distinctive value when there is no more input, a value that cannot be confused with any real character. This value is called EOF, 
for `end of file'. We must declare c to be a type big enough to hold any value that getchar returns. We can't use char since c must be big enough to hold EOF in addition to any possible char. Therefore we use int.

EOF is an integer defined in <stdio.h>, but the specific numeric value doesn't matter as long as it is not the same as any char value. By using the symbolic constant, we are assured that nothing in the program depends on the specific numeric value.

int v1 = 1, v2 = 1;

    printf("V1 = %d\n", ++v1); // v1 = 2
    printf("V2 = %d\n", v2++); // v2 1
```

