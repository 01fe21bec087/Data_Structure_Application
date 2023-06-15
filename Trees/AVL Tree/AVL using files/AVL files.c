//AVL Tree using files
/*
Author: Abhinav Sushil Pawar
Date: 10-06-2023 & 14-06-2023
Constraints: Maxmimum MAXRAND (100) number of unique random numbers can be generated
*/
#include <stdio.h>
#include<stdlib.h>
#define MAXRAND 100
// Create Node - Skeleton
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
  int height;
};
typedef struct Node *NODE;

// Calculate height of a node N
int height(NODE node)
{
  if (node==NULL)
    return 0;
  return node->height;
}
//function to return the largest of two integers
int max(int a, int b)
{
  return (a>b)?a:b;
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
  y->height = max(height(y->left), height(y->right))+1;
  x->height = max(height(x->left), height(x->right))+1;
  return x;
}
// Left rotate
NODE leftRotate(NODE x) {
  NODE y = x->right;
  NODE T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left), height(x->right))+1;
  y->height = max(height(y->left), height(y->right))+1;
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
// Print the tree in pre-order fashion
void preorder(NODE root,FILE* fppre,char prefile[])
{
  if (root != NULL) {
    printf("%d ", root->data);
    append_to_file(fppre,prefile,root->data);
    preorder(root->left,fppre,prefile);
    preorder(root->right,fppre,prefile);
  }
}
//Display of binary tree in left node, root node, right node order, and adding to file
void inorder(NODE root,FILE* fpin, char infile[])
{
    if(root!=NULL)
    {
        inorder(root->left,fpin,infile);
        printf("%d ",root->data);
        append_to_file(fpin,infile,root->data);
        inorder(root->right,fpin,infile);
    }
}
//Display of binary tree in left node,right node,root node order, and adding to file
void postorder(NODE root,FILE* fppost,char postfile[])
{
    if(root!=NULL)
    {
        postorder(root->left,fppost,postfile);
        postorder(root->right,fppost,postfile);
        printf("%d ",root->data);
        append_to_file(fppost,postfile,root->data);
    }
}
//Function to add integer data to file
void append_to_file(FILE* fptr,char filename[],int data)
{
    fptr=fopen(filename,"a");
    if(fptr==NULL)
        printf("'%s' File creation error!\n",filename);
    else
    {
        fprintf(fptr,"%d\n",data);
        //printf("Entered data %d to file '%s' successfully\n",data,filename);
    }
    fclose(fptr);
}
//Function to generate random numbers and adding to file
void random_number_generate(FILE* fptr,char filename[])
{
    int min,max,random,temp;
    askagain:
        printf("\nEnter range (min,max): ");
        scanf("%d%d",&min,&max);
        if((max-min)<MAXRAND){
            printf("Not possible to create unique random numbers in this range. Enter (max-min)>%d\n",MAXRAND);
            goto askagain;
        }
    for(int i=0;i<MAXRAND;i++)
    {
       Create:
       random=rand()%(max+1);
        if(random>=min && random<=max)      //ensuring random number generated is within specified range
        {
            fptr=fopen(filename,"r");
            while(!EOF)                     //Unique random number generator
            {
                fscanf(fptr,"%d",&temp);
                if(random==temp)
                {
                    fclose(fptr);
                    goto Create;
                }
            }
            fclose(fptr);
            append_to_file(fptr,filename,random);
        }
        else
            goto Create;
    }
    printf("%d unique random numbers generated successfully!\n",MAXRAND);
}
//Function to read number from input file
NODE read_from_file(FILE* fptr,char filename[],NODE root,int count,FILE* fpinsert,char insertfile[])
{
    fptr=fopen(filename,"r");
    int data;
    if(fptr==NULL)      //File reading error
    {
        printf("'%s' File reading error!\n",filename);
    }
    else
    {
       // printf("'%s' File reading successfully\n",filename);
       for(int i=0;i<count;i++)
            fscanf(fptr,"%d",&data);
        printf("%d read from '%s' file\n",data,filename);
        root=insertNode(root,data);
        append_to_file(fpinsert,insertfile,data);
    }
    return root;
}
//Function to cleat a given file
void flush(FILE* fptr, char filename[])
{
    fptr=fopen(filename,"w");
    fclose(fptr);
    printf("Clearing '%s' file...\n",filename);
}

void main()
{
    FILE *fprandom,*fpinsert,*fpdelete,*fppre, *fpin, *fppost;
    char inputfile[]="Input_file.txt",insertfile[]="Insert_file.txt",deletefile[]="Delete_file.txt",prefile[]="Tree_PreOrder_file.txt",infile[]="Tree_InOrder_file.txt",postfile[]="Tree_PostOrder_file.txt";
    flush(fprandom,inputfile);
    flush(fpinsert,insertfile);
    flush(fpdelete,deletefile);
    flush(fppre,prefile);
    flush(fpin,infile);
    flush(fppost,postfile);

    random_number_generate(fprandom,inputfile);
    NODE root = NULL;
    int ch,item,count=0;
    while(1)
    {
        printf("\n\n 1:Insert node \t 2:Delete node \t 3:Pre-order \t 4:In-order \t 5:Post-order \t 6:Exit \n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: count++;
                    if(count>MAXRAND){
                        printf("Maximum limit reached. No data items left to enter\n");
                        break;
                    }
                    root=read_from_file(fprandom,inputfile,root,count,fpinsert,insertfile);
                    if(root==NULL) printf("root is %d\n",root);
                    break;
            case 2: printf("Enter item to delete: ");
                    scanf("%d",&item);
                    root = deleteNode(root,item);
                    append_to_file(fpdelete,deletefile,item);
                    break;
            case 3: flush(fppre,prefile);
                    printf("Displaying tree (Pre-order): ");
                    preorder(root,fppre,prefile);
                    break;
            case 4: flush(fpin,infile);
                    printf("Displaying tree (In-order): ");
                    inorder(root,fpin,infile);
                    break;
            case 5: flush(fppost,postfile);
                    printf("Displaying tree (Post-order): ");
                    postorder(root,fppost,postfile);
                    break;
            case 6: printf("Exiting...\n\n");
                    goto Exit;
            default: printf("Invalid choice!\n");
                    break;
        }
    }
    Exit:       //Clearing file, to enter updated tree (when not displayed just before exiting)
        flush(fppre,prefile);
        flush(fpin,infile);
        flush(fppost,postfile);
        preorder(root,fppre,prefile);
        inorder(root,fpin,infile);
        postorder(root,fppost,postfile);
}
