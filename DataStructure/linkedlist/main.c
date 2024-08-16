/*
 * Introduction Linked lists
 * Linked lists are the best and simplest example of a dynamic data structure that
 * uses pointers for its implementation. However, understanding pointers is crucial
 * to understanding how linked lists work,
 *
 * Essentially, linked lists function as an array that can grow and shrink as needed,
 * from any point in the array.
 *
 *   - Linked lists have a few advantages over arrays:
 *
 *   1. Items can be added or removed from the middle of the list
 *   2. There is no need to define an initial size
 *
 *  - What is a linked list?
 * A linked list is a set of dynamically allocated nodes, arranged in such a way
 * that each node contains one value and one pointer.
 * The pointer always points to the next member of the list. If the pointer is NULL,
 * then it is the last node in the list.
 * A linked list is held using a local pointer variable which points to the first item of the list.
 * If that pointer is also NULL, then the list is considered to be empty.
 **/

#include <stdio.h>
#include <stdlib.h>

/* Define a linked list */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

void print_list(Node *head);
void push(Node *head, int data);
void push_front(Node **head, int data);
int pop(Node **head);
int remove_last(Node **head);  // Changed function signature to take a double pointer
int remove_by_index(Node **head, int n);

int main(void) {
    /* Create a local variable which points to the first item of the list (called head).*/
    Node *head = NULL;

    // Pushing elements to the front of the list
    push_front(&head, 2);
    push_front(&head, 1);

    // Printing the list
    print_list(head);

    // Popping the first element
    printf("Popped: %d\n", pop(&head));

    // Removing the last element
    printf("Removed last: %d\n", remove_last(&head));

    // Clean up the remaining list
    while (head != NULL) {
        pop(&head);
    }

    return 0;
}

/*
 * Iterating over a list
 * Let's build a function that prints out all the items of a list. To do this, we need to use a current pointer that
 * will keep track of the node we are currently printing. After printing the value of the node, we set the current
 * pointer to the next node, and print again, until we've reached the end of the list (the next node is NULL).
 */
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

/*
 * Adding an item to the end of the list
 * To iterate over all the members of the linked list,
 * we use a pointer called current. We set it to start from the head
 * and then in each step, we advance the pointer to the next item in the list,
 * until we reach the last item.
 */
void push(Node *head, int data) {
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (Node *)malloc(sizeof(Node));
    /* Check if memory allocation was successful */
    if (current == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); /* indicates allocation failure.*/
    }
    current->next->data = data;
    current->next->next = NULL;
}

/*
 * Adding an item to the beginning of the list (pushing to the list)
 * To add to the beginning of the list, we will need to do the following:
 *
 *  - Create a new item and set its value
 *  - Link the new item to point to the head of the list
 *  - Set the head of the list to be our new item
 *  - This will effectively create a new head to the list with a new value, and keep the rest of the list linked to it.
 *
 * Since we use a function to do this operation, we want to be able to modify the head variable.
 * To do this, we must pass a pointer to the pointer variable (a double pointer)
 * so we will be able to modify the pointer itself.
 */
void push_front(Node **head, int data) {
    Node *new_node;
    new_node = (Node *)malloc(sizeof(Node));
    /* Check if memory allocation was successful */
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); /* indicates allocation failure.*/
    }
    printf("Memory allocation successful\n");
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

/*
 * Removing the first item (popping from the list)
 * To pop a variable, we will need to reverse this action:
 *
 *  - Take the next item that the head points to and save it
 *  - Free the head item
 *  - Set the head to be the next item that we've stored on the side
 */
int pop(Node **head) {
    int retval = -1;
    Node *next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->data;
    free(*head);
    *head = next_node;

    return retval;
}

/*
 * Removing the last item of the list
 * Removing the last item from a list is very similar to adding it to the end of the list,
 * but with one big exception - since we have to change one item before the last item,
 * we actually have to look two items ahead and see if the next item
 * is the last one in the list:
 */
int remove_last(Node **head) {
    int retval = -1;

    /* if the list is empty */
    if (*head == NULL) {
        return -1;
    }

    /* if there is only one item in the list */
    if ((*head)->next == NULL) {
        retval = (*head)->data;
        free(*head);
        *head = NULL;
        return retval;
    }

    /* get to the second to last node in the list */
    Node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->data;
    free(current->next);
    current->next = NULL;
    return retval;
}

/*
 * Removing a specific item
 * To remove a specific item from the list, either by its index
 * from the beginning of the list or by its value, we will
 * need to go over all the items, continuously looking ahead to find out
 * if we've reached the node before the item we wish
 * to remove. This is because we need to change the location to where the previous node points to as well.
 *
 * Here is the algorithm:
 *
 *  - Iterate to the node before the node we wish to delete
 *  - Save the node we wish to delete in a temporary pointer
 *  - Set the previous node's next pointer to point to the node after the node we wish to delete
 *  - Delete the node using the temporary pointer
 *
 * There are a few edge cases we need to take care of, so make sure you understand the code.
 */
int remove_by_index(Node **head, int n) {
    int i = 0;
    int retval = -1;
    Node *current = *head;
    Node *temp_node = NULL;

    if (n == 0) {
        return pop(head);
    }

    for (i = 0; i < n - 1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    if (current->next == NULL) {
        return -1;
    }

    temp_node = current->next;
    retval = temp_node->data;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

/**
 * Changes made:

Removed the data parameter from print_list.
Renamed push that adds at the beginning of the list to push_front.
Fixed the main function to correctly allocate and initialize nodes.
Corrected the logic in remove_last to handle the list correctly.
Made sure to free all allocated memory to avoid memory leaks.
This version of the code should work as intended, handling various linked list operations correctly.
 */