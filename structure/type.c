#include <stdio.h>

// Define the structure and create a typedef alias
typedef struct TrieNode {
    char data;
    struct TrieNode* children[26];
    int isEndOfWord;
} TrieNode;

int main(void) {
    // Using the alias to declare a variable of type struct TrieNode
    TrieNode node;
    node.data = 'a';
    node.isEndOfWord = 0;
    for (int i = 0; i < 26; i++) {
        node.children[i] = NULL;
    }

    printf("Node data: %c\n", node.data);
    return 0;
}
