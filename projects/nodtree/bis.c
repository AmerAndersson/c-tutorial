#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to print the nodes in a level order
void printLevelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // Create an array to serve as the queue
    struct Node** queue = (struct Node**)malloc(100 * sizeof(struct Node*));
    int front = 0;
    int rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    while (front < rear) {
        // Dequeue the front node
        struct Node* currentNode = queue[front++];

        // Print the data of the dequeued node
        printf("%d ", currentNode->data);

        // Enqueue the left child if it exists
        if (currentNode->left != NULL) {
            queue[rear++] = currentNode->left;
        }

        // Enqueue the right child if it exists
        if (currentNode->right != NULL) {
            queue[rear++] = currentNode->right;
        }
    }

    // Free the allocated memory for the queue
    free(queue);
}

// Function to insert nodes in level order
struct Node* insertLevelOrder(int arr[], struct Node* root, int i, int n) {
    if (i < n) {
        struct Node* temp = createNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int main() {
    // Construct a binary tree
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node* root = insertLevelOrder(arr, root, 0, n);

    // Print level order traversal
    printf("Level Order Traversal of binary tree is: ");
    printLevelOrder(root);

    return 0;
}
