//Binary Search tree
/*
Author: Abhinav Sushil Pawar
Date: 02-06-2023
*/
/*
Constraint: Maximum MAXRAND(100) number of random numbers can be generated
*/
#include <stdio.h>
//Skeleton
struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};
typedef struct Tree *TREE;
//Function to create a new node and assign specified data for a binary tree
TREE getnode(int data)
{
    TREE newnode=(TREE)malloc(sizeof(struct Tree));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=data;
    return newnode;
}
TREE insert(TREE root,int data)
{
    if(root==NULL)  //Base condition for recursion call
    {
        root=getnode(data);
        return root;
    }
    if(data < root->data)
        root->left=insert(root->left,data);    //inserting the new node into the left subtree
    if(data > root->data)
        root->right=insert(root->right,data);  //inserting the new node into the right subtree
    return root;
}
//Display of binary tree in left node,root node ,right node order
inorder(TREE root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
//Display of binary tree in root node,left node ,right node order
void preorder(TREE root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//Display of binary tree in left node,right node,root node order
postorder(TREE root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void main()
{
    TREE root=NULL;
    while(1)
    {
        int ch,data;
        printf("\n 1:Insert to tree \n 2:Display: In-Order \n 3:Display: Pre-order \n 4:Display: Post-Order \n 5.Exit \n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter data: ");
                    scanf("%d",&data);
                    root=insert(root,data);
                    break;
            case 2: printf("\nIn-Order\n");
                    inorder(root);
                    break;
            case 3: printf("\nPre-Order\n");
                    preorder(root);
                    break;
            case 4: printf("\nPost-Order\n");
                    postorder(root);
                    break;
            case 5: exit(0);
            default: printf("\nInvalid choice!\n");
            break;
        }
    }
}
