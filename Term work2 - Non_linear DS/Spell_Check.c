#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure to represent a node in the BST
typedef struct Node {
    char word[50];
    struct Node* left;
    struct Node* right;
} Node;
Node* dictionary;
// Function to create a new node
Node* createNode(const char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a word into the BST
Node* insert(Node* root, const char* word) {
    if (root == NULL) {
        return createNode(word);
    }

    int comparisonResult = strcmp(word, root->word);
    if (comparisonResult < 0) {
        root->left = insert(root->left, word);
    } else if (comparisonResult > 0) {
        root->right = insert(root->right, word);
    }

    return root;
}

// Function to perform pre-order traversal of the BST
void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf("%s ", root->word);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform spell check on a word using the BST
bool spellCheck(Node* root, const char* word) {
    if (root == NULL) {
        return false;
    }

    int comparisonResult = strcmp(word, root->word);
    if (comparisonResult == 0) {
        return true;
    } else if (comparisonResult < 0) {
        return spellCheck(root->left, word);
    } else {
        return spellCheck(root->right, word);
    }
}
void check_word(const char* wordToCheck){
// Spell check a word
    //const char* wordToCheck = "banana";
    if (spellCheck(dictionary, wordToCheck)) {
        printf("%s is spelled correctly.\n", wordToCheck);
    } else {
        printf("%s is misspelled.\n", wordToCheck);
    }
}
int main() {
    // Create the dictionary BST
    dictionary = NULL;
    dictionary = insert(dictionary, "apple");
    dictionary = insert(dictionary, "banana");
    dictionary = insert(dictionary, "cat");
    dictionary = insert(dictionary, "dog");
    dictionary = insert(dictionary, "elephant");

    // Perform pre-order traversal of the dictionary
    printf("Dictionary words: ");
    preOrderTraversal(dictionary);
    printf("\n");

    check_word("banana");
    check_word("aple");
    return 0;
}
