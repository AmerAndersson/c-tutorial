/*
 * Linked list
 * In linked list implementations, the arrow operator
 * is used to traverse through the nodes by accessing the next node’s address.
 *
 * In the linked list example, head is a pointer to a Node type,
 * and head->data and head->next are used to access members of the structure.
 *
 * The arrow operator -> is vital in managing objects and structures
 * through pointers, especially in complex data structures.
 * It ensures code readability by providing a clear and concise way
 * to dereference pointers when accessing member elements, encapsulating
 * the dereference operation (*ptr). into a straightforward ptr-> expression.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to print linked list data
void print(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void) {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    if (!head) {  // Check for null pointer
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);  // Exit with an error code
    }

    head->data = 1;
    head->next = NULL;

    print(head);

    // Free the dynamically allocated memory
    free(head);

    return 0;
}