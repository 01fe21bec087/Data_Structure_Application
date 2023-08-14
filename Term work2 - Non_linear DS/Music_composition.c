#include <stdio.h>
struct Node{        //Skeleton for each note played
    char pitch;
    int duration;
    struct Node* left;
    struct Node* right;
};
typedef struct Node* NODE;
//Create each note played
NODE createNode(char pitch, int duration) {
    NODE newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->pitch=pitch;
    newNode->duration=duration;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
//Traversing the AVL Tree
void Postorder(NODE root) {
    if (root==NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("Music note: %c (Duration: %d)\n", root->pitch, root->duration);
}

void main() {
    NODE root=createNode('G',2);
    root->left=createNode('G',1);
    root->right=createNode('A',2);
    root->left->left=createNode('C',1);
    root->right->left=createNode('G',2);
    root->left->right=createNode('C',2);
    root->right->right=createNode('A',1);
    // Compose music by traversing the tree
    Postorder(root);
}
