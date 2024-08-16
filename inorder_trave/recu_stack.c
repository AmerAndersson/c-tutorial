/**
 Inorder traversal is a type of depth-first traversal used in binary trees. In an inorder traversal, the nodes are recursively visited in the following order:

Visit the left subtree
Visit the root node
Visit the right subtree
This traversal is particularly useful for binary search trees (BST) because it visits the nodes in ascending order.

Recursive Inorder Traversal:

If the current node is NULL, return.
Recursively visit the left subtree.
Print the value of the current node.
Recursively visit the right subtree.
Iterative Inorder Traversal:

Use a stack to keep track of nodes.
Start from the root and push all left nodes onto the stack.
Pop a node from the stack, print its value, and switch to its right node.
Repeat the process until both the stack is empty and the current node is NULL.
The recursive method is more intuitive and concise, while the iterative method is more complex but avoids the potential stack overflow issues that can arise with deep recursion.
*/

// Iterative Inorder Traversal
// The iterative approach uses a stack to simulate the recursive call stack.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Define the structure for a stack node
struct StackNode {
    struct TreeNode* treeNode;
    struct StackNode* next;
};

// Function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to push a tree node onto the stack
void push(struct StackNode** top, struct TreeNode* treeNode) {
    struct StackNode* newStackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newStackNode->treeNode = treeNode;
    newStackNode->next = *top;
    *top = newStackNode;
}

// Function to pop a tree node from the stack
struct TreeNode* pop(struct StackNode** top) {
    if (*top == NULL) {
        return NULL;
    }
    struct StackNode* temp = *top;
    struct TreeNode* treeNode = temp->treeNode;
    *top = (*top)->next;
    free(temp);
    return treeNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* top) {
    return top == NULL;
}

// Iterative function for inorder traversal
void inorderTraversal(struct TreeNode* root) {
    struct StackNode* stack = NULL;
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        // Current must be NULL at this point
        current = pop(&stack);
        printf("%d ", current->val);  // Visit the root node

        // Visit the right subtree
        current = current->right;
    }
}

int main(void) {
    // Creating a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder Traversal binary trees stack: ");
    inorderTraversal(root);  // Expected output: 4 2 5 1 3

    // To avoid using a dangling pointer, set it to NULL
    root = NULL;

    // Now root is safe to use in checks, and won't cause undefined behavior
    if (root == NULL) {
        printf("root is NULL, safe to use in checks.\n");
    }
    printf("\n");
    return 0;
}
