#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define TABLE_SIZE 100
typedef struct {
    int transactionId;
    char description[50];
    double amount;
} Transaction;
typedef struct {
    int key;
    Transaction* transaction;
} Node;
// Function to calculate the hash value for a given key
int hash(int key) {
    return key % TABLE_SIZE;
}
// Function to initialize the hash table
void initHashTable(Node* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}
// Function to insert a transaction into the hash table
void insertTransaction(Node* hashTable[], Transaction* transaction) {
    int key=transaction->transactionId;
    int index=hash(key);
    while (hashTable[index]!=NULL) {
        index=(index+1)%TABLE_SIZE;
    }
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->key=key;
    newNode->transaction=transaction;
    hashTable[index]=newNode;
}
// Function to search for a transaction in the hash table
Transaction* searchTransaction(Node* hashTable[], int transactionId) {
    int key = transactionId;
    int index = hash(key);
    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            return hashTable[index]->transaction;
        }
        index=(index+1)%TABLE_SIZE;
    }
    return NULL;
}
void main() {
    Node* hashTable[TABLE_SIZE];
    initHashTable(hashTable);

    // Create and insert some transactions into the hash table
    Transaction transaction1 = {1001, "Purchase", 25.50};
    insertTransaction(hashTable, &transaction1);

    Transaction transaction2 = {1002, "Withdrawal", 50.0};
    insertTransaction(hashTable, &transaction2);

    Transaction transaction3 = {1003, "Deposit", 75.25};
    insertTransaction(hashTable, &transaction3);

    // Search for a transaction by its ID
    int searchId = 1002;
    Transaction* searchedTransaction = searchTransaction(hashTable, searchId);

    if (searchedTransaction != NULL) {
        printf("Transaction Found!\n");
        printf("Transaction ID: %d\n", searchedTransaction->transactionId);
        printf("Description: %s\n", searchedTransaction->description);
        printf("Amount: %.2f\n", searchedTransaction->amount);
    } else {
        printf("Transaction not found.\n");
    }
}
