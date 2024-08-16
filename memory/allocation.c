/*
 * Dynamic allocation of memory is a very important subject in C.
 * It allows building complex data *structures such as linked lists.
 * Allocating memory dynamically helps us to store data without
 * initially knowing the size of the data in the time we wrote the program.
 *
 * To allocate a chunk of memory dynamically, we need to have a pointer ready to store
 * the location of *the newly allocated memory. We can access memory that was allocated
 * to us using that same pointer, *and we can use that pointer to free the memory again,
 * once we have finished using it.
 *
 * Dynamic Memory Allocation: a new person in the person argument,
 * just enough to hold a person struct in memory and then return a
 * pointer of type person to the newly allocated data
 */

#include <stdio.h>
#include <stdlib.h>

/* Define the Person struct*/
typedef struct {
    char name[50];
    int age;
} Person;

Person* create_person(void);

int main(void) {
    // Calling create_person to create a new Person.
    Person* person = create_person();

    // Assign values to the person its fields.
    snprintf(person->name, sizeof(person->name), "John Doe");
    person->age = 30;

    // Print the person's details
    printf("%s is %d years old.\n", person->name, person->age);
    printf("\n");

    /*
     * Free the allocated memory using free(person) to avoid memory leaks.
     * or dangling pointer, set it to NULL. The pointer person is
     * then set to * NULL to prevent it from being a dangling pointer.
     * Now person is safe to use in checks, and won't cause undefined behavior
     */
    free(person);
    person = NULL;
    if (person == NULL) {
        printf("person is NULL, safe to use in checks.\n");
    }

    return 0;
}
/*
 * The create_person function dynamically allocates memory for a  Person struct
 * using malloc and returns a pointer to this newly allocated memory.
 */
Person* create_person(void) {
    /* Memory is allocated for a Person struct.*/
    Person* person = (Person*)malloc(sizeof(Person));

    /*
     * Check if memory allocation was successful
     * If malloc returns NULL, it means the allocation failed,
     * and we print an error message and exit the program.
     */
    if (person == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); /* indicates allocation failure.*/
    }

    return person;
}
