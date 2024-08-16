/*
Created a Structure ‘Movie_info’. Further, we have assigned a pointer object to the structure and allocated memory to it in a dynamic manner using the C 
malloc() function.
Arrow operator to access the data member of a C Structure
*/

#include <stdio.h>

struct Movie_info {
    char *name;
    char *ACC;
};

int main(void) {
    struct Movie_info *M;
    M = (struct Movie_info *)
        malloc(sizeof(struct Movie_info));

    M->name = "Python with JournalDev";
    M->ACC = "A";

    printf("Movie Information:");
    printf("\nName: %s", M->name);
    printf("\nACC: %s", M->ACC);
    return 0;
}
