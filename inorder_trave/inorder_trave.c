/**
 Inorder traversal is a type of depth-first traversal used in binary trees. In an inorder traversal, the nodes are recursively visited in the following order:

Visit the left subtree
Visit the root node
Visit the right subtree
This traversal is particularly useful for binary search trees (BST) because it visits the nodes in ascending order.

Inorder Traversal Algorithm
The inorder traversal can be implemented using both recursive and iterative approaches. Below, I'll provide examples of both in C.

Recursive Inorder Traversal
The recursive approach is straightforward and follows the natural recursive definition of the inorder traversal.

Recursive Inorder Traversal:

If the current node is NULL, return.
Recursively visit the left subtree.
Print the value of the current node.
Recursively visit the right subtree.
Iterative Inorder Traversal:
*/
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function for inorder traversal
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);   // Visit the left subtree
    printf("%d ", root->val);       // Visit the root node
    inorderTraversal(root->right);  // Visit the right subtree
}

int main(void) {
    // Creating a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder Traversal binary trees signal ");
    inorderTraversal(root);  // Expected output: 4 2 5 1 3
    free(root);              // Release it using free:

    // To avoid using a dangling pointer, set it to NULL
    root = NULL;

    // Now root is safe to use in checks, and won't cause undefined behavior
    if (root == NULL) {
        printf("root is NULL, safe to use in checks.\n");
    }
    printf("\n");
    return 0;
}
