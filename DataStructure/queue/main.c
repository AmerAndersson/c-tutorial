#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Node structure represents each element in the queue. */
typedef struct Node {
    int value;
    struct Node *next;
} Node;

/* Queue structure keeps track of the head, tail, and size of the queue. */
typedef struct {
    Node *head;
    Node *tail;
    int size;
} Queue;

/* Function prototypes for queue operations. */
Queue *create_queue(void);
int size(Queue *queue);
bool is_empty(Queue *queue);
int peek(Queue *queue, bool *status);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void destroy_queue(Queue *queue);

int main(void) {
    /* Create a new queue */
    Queue *queue = create_queue();
    if (is_empty(queue)) printf("Queue is empty.\n");

    enqueue(queue, 4);
    if (!is_empty(queue)) printf("Queue is not empty.\n");

    enqueue(queue, 5);
    enqueue(queue, 6);

    printf("Queue size: %d\n", size(queue));
    bool status = false;
    int value = 0;

    /* Perform peek and dequeue operations and print the results */
    value = peek(queue, &status);
    if (status) printf("Peek successful: %d\n", value);

    value = dequeue(queue, &status);
    if (status) printf("Dequeue successful: %d\n", value);

    value = peek(queue, &status);
    if (status) printf("Peek successful: %d\n", value);

    value = dequeue(queue, &status);
    if (status) printf("Dequeue successful: %d\n", value);

    value = peek(queue, &status);
    if (status) printf("Peek successful: %d\n", value);

    value = dequeue(queue, &status);
    if (status) printf("Dequeue successful: %d\n", value);

    /* Attempt to peek and dequeue from an empty queue */
    value = peek(queue, &status);
    if (!status) printf("Peek unsuccessful.\n");

    value = dequeue(queue, &status);
    if (!status) printf("Dequeue unsuccessful.\n");

    /* Destroy the queue and free memory */
    destroy_queue(queue);

    return 0;
}

/* Creates a new empty queue and returns a pointer to it. */
Queue *create_queue(void) {
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    printf("Memory allocation successful\n");

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

/* Returns the size of the queue. */
int size(Queue *queue) { return queue->size; }

/* Checks if the queue is empty */
bool is_empty(Queue *queue) { return (queue->size == 0); }

/**
 * Returns the value at the front of the queue without removing it.
 * Sets the status flag to indicate success or failure.
 */
int peek(Queue *queue, bool *status) {
    if (is_empty(queue)) {
        *status = false;
        return 0;
    }
    *status = true;
    return queue->head->value;
}

/* Adds a new value to the end of the queue. */
void enqueue(Queue *queue, int value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;

    if (is_empty(queue)) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;
}

/**
 * Removes and returns the value at the front of the queue.
 * Sets the status flag to indicate success or failure.
 */
int dequeue(Queue *queue, bool *status) {
    if (is_empty(queue)) {
        *status = false;
        return 0;
    }
    *status = true;
    int value = queue->head->value;
    Node *oldHead = queue->head;

    if (queue->size == 1) {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head = queue->head->next;
    }

    free(oldHead);
    queue->size--;

    return value;
}

/* Frees all memory associated with the queue and its nodes. */
void destroy_queue(Queue *queue) {
    Node *currentNode = queue->head;

    while (currentNode != NULL) {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }

    free(queue);
    queue = NULL;
    if (queue == NULL) {
        printf("Queue is NULL, safe to use in checks.\n");
    }
}
