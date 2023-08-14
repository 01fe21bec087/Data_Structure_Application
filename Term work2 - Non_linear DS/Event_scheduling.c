#include <stdio.h>
#include<string.h>
//Skeleton for each event with date and title
struct Tree{
    int date;
    char title[20];
    struct Tree *left;
    struct Tree *right;
};
typedef struct Tree *TREE;
char Title[20];
TREE getnode(int date){
    TREE newnode=(TREE)malloc(sizeof(struct Tree));
    newnode->left=NULL;
    newnode->right=NULL;
    strcpy(newnode->title,Title);
    newnode->date=date;
    return newnode;
}
TREE insert(TREE root,int date){
    if(root==NULL)  {
        root=getnode(date);
        return root;
    }
    if(date < root->date)
        root->left=insert(root->left,date);
    if(date > root->date)
        root->right=insert(root->right,date);
    return root;
}
//Display of binary tree in left node,root node ,right node order
inorder(TREE root){
    if(root!=NULL){
        inorder(root->left);
        printf("Event title: %s; date: %d \n",root->title,root->date);
        inorder(root->right);
    }
}
void main()
{
    TREE root=NULL;
    while(1)
    {
        int ch,date;
        printf("\n 1:Insert to tree \n 2:Display: In-Order \n 3.Exit \n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter event title: ");
                    scanf("%s",&Title);//gets(Title);
                    printf("\nEnter date: ");
                    scanf("%d",&date);
                    root=insert(root,date);
                    break;
            case 2: printf("\nIn-Order\n");
                    inorder(root);
                    break;
            case 3: exit(0);
            default: printf("\nInvalid choice!\n");
            break;
        }
    }
}
