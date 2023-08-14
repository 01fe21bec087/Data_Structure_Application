#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100
typedef struct {
    char url[200];
    char shortenedUrl[10];
} UrlEntry;
typedef struct {
    bool filled;
    UrlEntry entry;
} Node;
// Function to calculate the hash value for the first level of hashing
int hash1(const char* key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}
// Function to calculate the hash value for the second level of hashing
int hash2(const char* key) {
    int prime = 31;
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum = (sum * prime + key[i]) % TABLE_SIZE;
    }
    return sum;
}
// Function to initialize the hash table
void initHashTable(Node* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].filled = false;
    }
}
// Function to insert a URL into the hash table
void insertUrl(Node* hashTable, const char* url, const char* shortenedUrl) {
    UrlEntry entry;
    strcpy(entry.url, url);
    strcpy(entry.shortenedUrl, shortenedUrl);
    int hashValue1 = hash1(shortenedUrl);
    int hashValue2 = hash2(shortenedUrl);
    int index = hashValue1;
    int step = hashValue2;
    while (hashTable[index].filled) {
        index = (index + step) % TABLE_SIZE;
    }
    hashTable[index].entry = entry;
    hashTable[index].filled = true;
    printf("URL inserted: %s => %s\n", url, shortenedUrl);
}

// Function to search for a URL in the hash table
bool searchUrl(Node* hashTable, const char* shortenedUrl, char* url) {
    int hashValue1 = hash1(shortenedUrl);
    int hashValue2 = hash2(shortenedUrl);
    int index = hashValue1;
    int step = hashValue2;
    while (hashTable[index].filled) {
        if (strcmp(hashTable[index].entry.shortenedUrl, shortenedUrl) == 0) {
            strcpy(url, hashTable[index].entry.url);
            return true;
        }
        index = (index + step) % TABLE_SIZE;
    }
    return false;
}

void main() {
    Node hashTable[TABLE_SIZE];
    initHashTable(hashTable);
    // Insert some URLs into the hash table
    insertUrl(hashTable, "https://www.example.com/page1", "abcd");
    insertUrl(hashTable, "https://www.example.com/page2", "efgh");
    insertUrl(hashTable, "https://www.example.com/page3", "ijkl");
    // Search for a URL using the shortened URL
    char searchUrlBuffer[200];
    const char* searchShortenedUrl = "efgh";
    if (searchUrl(hashTable, searchShortenedUrl, searchUrlBuffer)) {
        printf("Found URL: %s\n", searchUrlBuffer);
    } else {
        printf("URL not found.\n");
    }
}
