/**
 * stream :A pointer to the FILE object that identifies the stream where the output is to be written.

format : A string that specifies the format of the output. It may contain format specifiers that are replaced by the values specified in the subsequent arguments.

... : Additional arguments that correspond to the format specifiers in the format string.
 */
#include <stdio.h>

// write multiple lines to a file using successive
// calls to fprintf().
int main(void) {
    FILE *file_ptr;

    // Open file in write mode
    file_ptr = fopen("./out/output.txt", "w");
    if (file_ptr == NULL) {
        printf("Error opening file!");
        return 1;
    }
    fprintf(file_ptr, "Hello World, my name is Amer Andersson and Iam Software engineer wit with 5 years experience of c/c++ \n");
    fprintf(file_ptr, "Hello World, my name is Amer Andersson and Iam Software engineer wit with 5 years experience of c/c++ \n");
    fprintf(file_ptr, "Hello World, my name is Amer Andersson and Iam Software engineer wit with 5 years experience of c/c++ \n");
    fprintf(file_ptr, "Hello World, my name is Amer Andersson and Iam Software engineer wit with 5 years experience of c/c++ \n");
    fprintf(file_ptr, "Hello World, my name is Amer Andersson and Iam Software engineer wit with 5 years experience of c/c++ \n");
    fprintf(file_ptr, "Hello World, my name is Amer Andersson and Iam Software engineer wit with 5 years experience of c/c++ \n");
    // Close the file
    fclose(file_ptr);
    return 0;
}
