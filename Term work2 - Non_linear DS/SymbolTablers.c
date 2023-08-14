#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100
typedef struct {
    char name[50];
    int value;
} Entry;
void initSymbolTable(Entry symbolTable[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        strcpy(symbolTable[i].name, "");
        symbolTable[i].value = 0;
    }
}
void insertEntry(Entry symbolTable[], const char* name, int value) {
    int index = 0;
    while (strcmp(symbolTable[index].name, "") != 0) {
        index++;
        if (index == MAX_SIZE) {
            printf("Symbol table is full!\n");
            return;
        }
    }
    strcpy(symbolTable[index].name, name);
    symbolTable[index].value = value;
    printf("Inserted entry: %s\n", name);
}

// Function to search for an entry in the symbol table
bool searchEntry(Entry symbolTable[], const char* name, int* value) {
    int index = 0;
    while (strcmp(symbolTable[index].name, "") != 0) {
        if (strcmp(symbolTable[index].name, name) == 0) {
            *value = symbolTable[index].value;
            return true;
        }
        index++;
    }
    return false;
}

int main() {
    Entry symbolTable[MAX_SIZE];
    initSymbolTable(symbolTable);

    // Insert some entries into the symbol table
    insertEntry(symbolTable, "x", 10);
    insertEntry(symbolTable, "y", 20);
    insertEntry(symbolTable, "z", 30);

    // Search for an entry in the symbol table
    const char* searchName = "y";
    int searchValue = 0;
    if (searchEntry(symbolTable, searchName, &searchValue)) {
        printf("Found entry: %s = %d\n", searchName, searchValue);
    } else {
        printf("Entry not found: %s\n", searchName);
    }

    return 0;
}
