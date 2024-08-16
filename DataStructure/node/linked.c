/**
 * Building Complicated Data Structures
 * Pointers are used to build complex data structures such as:
 *  linked lists, stacks, queues, and graphs.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Linked List Implementation
 * The Node struct is used to create nodes for a singly linked list.
 * Basic operations like insertion and traversal:
 *
 * A linked list node:
 * next is a pointer to the next node in the linked list.
 */
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to traverse and print the linked list
void traverseList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Linked List : Using pointers to create and manage nodes and perform list operations.
    struct Node *head = NULL;
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);

    printf("Linked List: ");
    traverseList(head);

    // Free memory (not shown here for simplicity)
    free(head);
    return 0;
}
