/*
 * Implement the function remove_by_value which receives
 * a double pointer to the head and removes the first
 * item in the list which has the value val
 *
 *
   Initial Checks:
 *
 *  - If the list is empty (*head == NULL), return -1 as the value is not found.
 *  - Check if the head node has the value val.
    - If it does, update the head pointer to the next node and free - the old head node, then return 0.
 *
 * Traversal:
 *
 *  - Use two pointers: current to track the current node, and previous to track the node before current.
 *  - Traverse the list until you find the node with the value val.
 *
 *  Removing the Node:
 *
 *  - If the value is not found after traversal (current == NULL), return -1.
 *  - If the node is found, adjust the next pointer of the previous node to skip the current node.
 *  - Free the current node and return 0.
 *
 *  Testing:
 *
 *   - The main function creates a test list with values 1, 2, 3, 4.
 *   - remove_by_value is called to remove the node with value 3.
 *   - The print_list function is called to print the updated list to verify
 *   that the node with value 3 has been removed.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

void print_list(Node *head);
int pop(Node **head);
int remove_by_value(Node **head, int val);

int main(void) {
    Node *test_list = (Node *)malloc(sizeof(Node));
    /* Check if memory allocation was successful */
    if (test_list == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); /* indicates allocation failure.*/
    }
    printf("Memory allocation successful\n");

    test_list->val = 1;
    test_list->next = (Node *)malloc(sizeof(Node));
    test_list->next->val = 2;
    test_list->next->next = (Node *)malloc(sizeof(Node));
    test_list->next->next->val = 3;
    test_list->next->next->next = (Node *)malloc(sizeof(Node));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 3);

    print_list(test_list);

    return 0;
}
void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int pop(Node **head) {
    int retval = -1;
    Node *next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_by_value(Node **head, int val) {
    Node *current = *head;
    Node *previous = NULL;

    // Check if the list is empty
    if (current == NULL) {
        return -1;  // Value not found
    }

    // Check if the head node is the one to be removed
    if (current->val == val) {
        *head = current->next;
        free(current);
        return 0;  // Value found and removed
    }

    // Traverse the list to find the node to remove
    while (current != NULL && current->val != val) {
        previous = current;
        current = current->next;
    }

    // If the value was not found
    if (current == NULL) {
        return -1;  // Value not found
    }

    // Remove the node
    previous->next = current->next;
    free(current);

    return 0;  // Value found and removed
}
