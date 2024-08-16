#include <stdio.h>
#include <stdlib.h>

/*
 * Each node in a Binary Tree has three parts:

 * Data
 * Pointer to the left child
 * Pointer to the right child
 *
 * Building Special Data Structures (e.g., Trees, Tries)
 * Pointers are crucial for constructing hierarchical data structures
 * like trees and tries. A  binary tree node can be defined as:
 *
 * Binary Tree Implementation
 * The TreeNode struct is used to create nodes for a binary tree.
 * How you might implement basic operations such as insertion and traversal:
 */

/* A binary tree node can be defined as */
/* left and right are pointers to the left and right child nodes */
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode *createNode(int data) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Function to insert a node in the binary tree */
struct TreeNode *insertNode(struct TreeNode *root, const int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

/* Function to perform inorder traversal */
void inorderTraversal(const struct TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main(void) {
    /* Binary Tree: Using pointers to create and manage nodes and perform tree operations. */
    struct TreeNode *root = NULL;
    root = insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 20);
    insertNode(root, 3);
    insertNode(root, 7);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    /* Free memory */
    free(root);
    return 0;
}
