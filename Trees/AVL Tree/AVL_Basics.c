//AVL Tree basics
/*
Author: Abhinav Sushil Pawar
Date: 10-06-2023
*/
#include <stdio.h>
// Create Node - Skeleton
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
  int height;
};
typedef struct Node *NODE;

// Calculate height of a node N
int height(NODE N)
{
  if (N==NULL)
    return 0;
  return N->height;
}
//function to return the largest of two integers
int max(int a, int b)
{
  return (a > b)?a:b;
}
// Create a new node
NODE getnode(int data)
{
  NODE newnode = (NODE)malloc(sizeof(struct Node));
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->height = 1;
  return(newnode);
}
// Right rotate
NODE rightRotate(NODE y)
{
  NODE x = y->left;
  NODE T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}
// Left rotate
NODE leftRotate(NODE x) {
  NODE y = x->right;
  NODE T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  return y;
}
// Get the balance factor
int balanceFactor(NODE node) {
  if (node == NULL)    return 0;
  return height(node->left) - height(node->right);
}
// Insert node
NODE insertNode(NODE node, int data) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (getnode(data));

  if (data < node->data)
    node->left = insertNode(node->left, data);
  else if (data > node->data)
    node->right = insertNode(node->right, data);
  else
    return node;

  // Update the balance factor of each node and Balance the tree
  node->height = 1 + max(height(node->left),height(node->right));
  int balance = balanceFactor(node);
  if(balance > 1 && data < node->left->data)
    return rightRotate(node);
  if(balance < -1 && data > node->right->data)
    return leftRotate(node);

  if(balance > 1 && data > node->left->data) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  if(balance < -1 && data < node->right->data) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  return node;
}
NODE minValueNode(NODE node) {
  NODE cur=node;
  while(cur->left!=NULL)
    cur=cur->left;
  return cur;
}
// Delete a nodes
NODE deleteNode(NODE root, int data) {
  // Find the node and delete it
  if(root == NULL)
    return root;

  if(data < root->data)
    root->left = deleteNode(root->left, data);
  else if(data > root->data)
    root->right = deleteNode(root->right, data);
  else
  {
    if((root->left == NULL) || (root->right == NULL))
    {
      NODE temp = root->left ? root->left : root->right;
      if(temp == NULL)
      {
        temp = root;
        root = NULL;
      }
      else
        *root = *temp;
      free(temp);
    }
    else
    {
      NODE temp = minValueNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  if (root == NULL)
    return root;
  // Update the balance factor of each node and balance the tree
  root->height = 1 + max(height(root->left),height(root->right));
  int balance = balanceFactor(root);
  if (balance > 1 && balanceFactor(root->left) >= 0)
    return rightRotate(root);
  if (balance > 1 && balanceFactor(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  if (balance < -1 && balanceFactor(root->right) <= 0)
    return leftRotate(root);
  if (balance < -1 && balanceFactor(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}
// Print the tree
void printPreOrder(NODE root) {
  if (root != NULL) {
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}
void main() {
  NODE root = NULL;
  int ch,item;
  while(1)
  {
      printf("\n\n 1:Insert node \t 2:Delete node \t 3:Display tree \t 4:Exit \n");
      printf("Enter choice: ");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1: printf("Enter item to insert: ");
                  scanf("%d",&item);
                  root = insertNode(root,item);
                  break;
          case 2: printf("Enter item to delete: ");
                  scanf("%d",&item);
                  root = deleteNode(root,item);
                  break;
          case 3: printf("Displaying tree: ");
                  printPreOrder(root);
                  break;
          case 4: printf("Exiting...\n\n");
                  exit(0);
         default: printf("Invalid choice!\n");
                  break;
      }
  }/*
  root = insertNode(root, 2);
  root = insertNode(root, 1);
  root = insertNode(root, 7);
  root = insertNode(root, 4);
  root = insertNode(root, 5);
  root = insertNode(root, 3);
  root = insertNode(root, 8);
  printPreOrder(root);

  root = deleteNode(root, 3);
  printf("\nAfter deletion: ");
  printPreOrder(root);*/
}
