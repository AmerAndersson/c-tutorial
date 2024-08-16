
/*
* Implementation of Trie (Prefix Tree) in C
* The Trie data structure is a tree-based data structure that is used to store the set of strings.
* Trie is also known as Prefix Tree or Digital Tree. Trie is used to store the strings in alphabetical order.

- Every Node can have a maximum of 26 children (i.e. a to z are 26 alphabets).
- The root Node is always a Null node.
- Each Node stores only one alphabet.
- Every Node is stored in an alphabetical Order
- Searching for words is done with the help of prefixes of words.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This structure represents a node in the Trie.
 * It has an array of TrieNode pointers to children (26, all are lowercase English letters)
 * and a boolean flag that indicates whether this given node corresponds to the last letter from
 * some word or not.

 * Trie Initialization in C
 * The above function dynamically allocates memory for a fresh TrieNode
 * and sets the isendofword flag to false along with resetting all child pointers as null.
 * At first, the Trie’s node is newly created.
 */
#define ALPHABET_SIZE 26

struct GeeksForGeeksTrieNode {
    struct GeeksForGeeksTrieNode *children[ALPHABET_SIZE];
    bool isendofword;
};
typedef struct GeeksForGeeksTrieNode GeeksForGeeksTrieNode;

GeeksForGeeksTrieNode *createNode() {
    GeeksForGeeksTrieNode *node = (GeeksForGeeksTrieNode *)malloc(sizeof(GeeksForGeeksTrieNode));
    node->isendofword = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

/**
 * This method enables to insertion of a key into the Trie whereby
 * it systematically examines each bit in the key, identifies where the bit lies within the children array,
 * and generates a new node if the relevant child node does not exist but then it denotes the final node
 * that terminates a word.
 */
void insert(GeeksForGeeksTrieNode *root, const char *key) {
    GeeksForGeeksTrieNode *current = root;
    for (int i = 0; i < strlen(key); i++) {
        int index = key[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isendofword = true;
}

/**
 * The Trie search() function looks for a key. To find that key,
 * it examines all characters of the key, and checks whether each character’s child node exists
 * inside this node’s children array field which contains pointers to its offspring as elements;
 * False should be returned if any character does not appear in children or if last character’s node
 * did not indicate it was a word else True would have been returned just like before.
 */
bool search(GeeksForGeeksTrieNode *root, const char *key) {
    GeeksForGeeksTrieNode *current = root;
    for (int i = 0; i < strlen(key); i++) {
        int index = key[i] - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    return (current != NULL && current->isendofword);
}

bool isempty(GeeksForGeeksTrieNode *root) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != NULL) {
            return false;
        }
    }
    return true;
}
/**
 * The above code initiative is responsible for creating the deletehelper function which
 * removes a key from Trie: it goes down this data structure recursively looking for a node
 * assigned to the same character as determined by the last key character.
 * Then it denotes that the node is not longer where a word ends by clearing this property out
 * before starting to remove all children below node by node until either it finds another node branches
 * off  from the current one or there aren’t any other words connected thereto anymore.
 * deletekey on the other hand serving as an interface method passes a key to be deleted
 * from Trie to a deletehelper function which does the actual removal of the node holding
 * it together with any related values if appropriate.
 */

GeeksForGeeksTrieNode *deleteHelper(GeeksForGeeksTrieNode *root, const char *key, int depth) {
    if (root == NULL) {
        return NULL;
    }
    if (depth == strlen(key)) {
        if (root->isendofword) {
            root->isendofword = false;
        }
        if (isempty(root)) {
            free(root);
            root = NULL;
        }
        return root;
    }
    int index = key[depth] - 'a';
    root->children[index] = deleteHelper(root->children[index], key, depth + 1);
    if (isempty(root) && !root->isendofword) {
        free(root);
        root = NULL;
    }
    return root;
}

void deletekey(GeeksForGeeksTrieNode *root, const char *key) {
    deleteHelper(root, key, 0);
}

int main(void) {
    /*
     * In this code, as we entered the ‘hello’ and ‘world’ in the trie,
     * the output for searching of ‘hello’ and ‘world’ will be True i.e.
     * ‘Found’ but for ‘geeks’ it will be ‘Not Found’. After deleting the ‘hello’ from trie ,
     *  search result for trie will also be ‘Not Found’.
     */
    GeeksForGeeksTrieNode *root = createNode();

    insert(root, "hello");
    insert(root, "world");

    printf("%s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("%s\n", search(root, "world") ? "Found" : "Not Found");
    printf("%s\n", search(root, "geeks") ? "Found" : "Not Found");

    deletekey(root, "hello");
    printf("%s\n", search(root, "hello") ? "Found" : "Not Found");

    return 0;
}
