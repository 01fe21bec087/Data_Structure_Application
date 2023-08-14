#include <stdio.h>
#include <stdbool.h>
// skeleton representing a circuit node
struct Node {
    int id;
    bool isFaulty;      //boolean
    struct Node* neighbors[8];
    int numNeighbors;
};
typedef struct Node *NODE;

NODE createNode(int id, bool isFaulty) {
    NODE newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->id=id;
    newNode->isFaulty=isFaulty;
    newNode->numNeighbors=0;
    return newNode;
}
void addNeighbor(NODE node, NODE neighbor) {
    node->neighbors[node->numNeighbors++]=neighbor;
}
// Depth-First Search for circuit fault diagnosis
void Diagnosis(NODE node) {
    if (node == NULL)
        return;

    // Check if the current node is faulty
    if (node->isFaulty) {
        printf("Fault detected at node %d\n", node->id);
        return;
    }
    // Traverse neighbors recursively
    for (int i = 0; i < node->numNeighbors; i++) {
        Diagnosis(node->neighbors[i]);
    }
}

void main() {
    // Create circuit nodes
    NODE node1 = createNode(1, false);
    NODE node2 = createNode(2, false);
    NODE node3 = createNode(3, true);
    NODE node4 = createNode(4, false);
    NODE node5 = createNode(5, false);

    // Connect circuit nodes
    addNeighbor(node1, node2);
    addNeighbor(node2, node3);
    addNeighbor(node3, node4);
    addNeighbor(node4, node5);

    // Perform circuit fault diagnosis
    Diagnosis(node1);
}
