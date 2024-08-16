#include <stdio.h>

int main()
{
    // create, open, read, and write to files by declaring a
    // pointer of type FILE, and use the fopen() function:
    // FILE *fptr fptr = fopen(filename, mode);

    FILE *fptr;
    // Create a file
    fptr = fopen("../src/filename.txt", "w");

    // Close the file
    fclose(fptr);
    return 0;
}