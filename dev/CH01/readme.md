The next program uses the formula oC=(5/9)(oF-32) to print the following table of Fahrenheit temperatures and their centigrade or Celsius equivalents:

we augment each %3d  %6din the printf statement with a width, the numbers printed will be right- justified in their fields


```c 
1 -17 
20 -6 
40 4 
60 15 
80 26 
100 37 
120 48 
140 60 
160 71 
180 82 
200 93 
220 104 
240 115 
260 126 
280 137 
300 148
-----------------------
%d print as decimal integer
%6d print as decimal integer, at least 6 characters wide
%f print as floating point
%6f print as floating point, at least 6 characters wide
%.2f print as floating point, 2 characters after decimal point
%6.2f print as floating point, at least 6 wide and 2 after decimal point

%o for octal,
%x for hexadecimal, 
%c for character, 
%s for character string
%% for percent sign: %
```

 * Character Input and Output: (getchar and putchar)
 * Consider a family of related programs for processing character data
 * The model of input and output supported by the standard library is very simple.
 * Text input or output, regardless of where it originates or where it goes to,
 * is dealt with as streams of characters. A text stream is a sequence of characters divided
 * into lines; each line consists of zero or more characters followed by a newline character.s
 

#include <stdio.h>

int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        if (getchar() == EOF)
            break;
        printf(" %d\n", c);
    }
    printf("%d %u %x- at EOF\n", c, c, c);

    return 0;
}

```c
The while loop reads characters one by one until the end of file (EOF) is reached.
Each character read increments the character count nc.
If a newline character \n is read, increment the line count nl.
If a space ' ', newline \n, or tab \t character is read, set the state to OUT (outside a word).
If a character other than a space, newline, or tab is read and the state was OUT, set the state to IN (inside a word) and increment the word count nw.

Summary
This program reads input from the standard input (usually the keyboard) character by character. It counts the total number of characters, lines, and words in the input. It uses the state variable to differentiate between being inside a word and outside a word, ensuring that words are counted correctly even with varying spaces and newlines. The results are printed at the end of the input.

Input and Output Formatting
C language provides some tools using which we can format the input and output. They are generally inserted between the % sign and the format specifier symbol Some of them are as follows:

A minus(-) sign tells left alignment.
A number after % specifies the minimum field width to be printed if the characters are less than the size of the width the remaining space is filled with space and if it is greater then it is printed as it is without truncation.
A period( . ) symbol separates field width with precision.
Precision tells the minimum number of digits in an integer, the maximum number of characters in a string, and the number of digits after the decimal part in a floating value.

In order to stop the compilation right after this step, we can use the option "-E" with the gcc command on the source file, and press Enter.
gcc -E main.c

We can stop the compilation process after this step by using the option "-c" with the gcc command, and pressing Enter.

Note that the "main.o" file is not a text file, hence its contents would not be readable when you open this file with a text editor.
gcc -c main.c

The compiler generates the IR code (Intermediate Representation) from the preprocessed file, so this will produce a ".s" file. That being said, other compilers might produce assembly code at this step of compilation.

gcc -S main.c
```