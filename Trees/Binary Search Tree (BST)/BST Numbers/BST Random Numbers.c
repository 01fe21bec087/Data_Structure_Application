//Binary Search tree
/*
Author: Abhinav Sushil Pawar
Date: 07-06-2023
*/
/*
Constraint: Maximum MAXRAND(100) number of random numbers can be generated
MAXRAND number of Random numbers are generated (within the range (max,min)) and stored in the file "RandomNumbers".
n number of these random numbers are inserted into tree, and stored in file.
The elements of this tree are traversed in all the three modes (In-order,Pre-order,Post-order), and are stored in individual files.
*/
#include <stdio.h>
#define MAXRAND 100
//Skeleton
struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};
typedef struct Tree *TREE;
TREE root=NULL;
//Function to create a new node and assign specified data for a binary tree
TREE getnode(int data)
{
    TREE newnode=(TREE)malloc(sizeof(struct Tree));
    if(newnode==NULL)
    {
        printf ("Memory not allocated for node! \n");
        exit(0);
    }
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
        root->left=insert(root->left,data);  //inserting the new node into the left subtree
    if(data > root->data)
        root->right=insert(root->right,data);  //inserting the new node into the right subtree
    return root;
}
//Display of binary tree in left node, root node, right node order, and adding to file
inorder(TREE root,FILE* fpin, char infile[])
{
    if(root!=NULL)
    {
        inorder(root->left,fpin,infile);
        printf("%d ",root->data);
        append_to_file(fpin,infile,root->data);
        inorder(root->right,fpin,infile);
    }
}
//Display of binary tree in root node,left node ,right node order, and adding to file
void preorder(TREE root,FILE* fppre,char prefile[])
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        append_to_file(fppre,prefile,root->data);
        preorder(root->left,fppre,prefile);
        preorder(root->right,fppre,prefile);
    }
}
//Display of binary tree in left node,right node,root node order, and adding to file
postorder(TREE root,FILE* fppost,char postfile[])
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
    {
        printf("'%s' File creation error!\n",filename);
    }
    else
    {
        fprintf(fptr,"%d\n",data);
        printf("Entered data %d to file %s successfully\n",data,filename);
    }
    fclose(fptr);
}
//Function to generate random numbers and adding to file
void random_number_generate(FILE* fptr,char filename[])
{
    int min,max,random;
    printf("\nEnter range (min,max): ");
    scanf("%d%d",&min,&max);
    for(int i=0;i<MAXRAND;i++)
    {
       Create:
       random=rand()%max;
        if(random>=min && random<=max)      //ensuring random number generated is within specified range
            append_to_file(fptr,filename,random);
        else
            goto Create;
    }
}
//Function to read n numbers from input file, and insert to tree
int read_from_file(FILE* fptr,char filename[],int n,FILE* fptree,char treefile[])
{
    fptr=fopen(filename,"r");
    if(fptr==NULL)      //File reading error
    {
        printf("'%s' File reading error!\n",filename);
    }
    else
    {
        int data;
        printf("'%s' File reading successfully\n",filename);
        for(int i=0;i<n;i++)        //Inserting data into tree one by one
        {
            fscanf(fptr,"%d",&data);
            root=insert(root,data);
            append_to_file(fptree,treefile,data);
        }
        printf("Entered %d numbers from file to tree successfully!\n",n);
    }
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
    FILE *fprandom,*fptree,*fpin,*fppre,*fppost;
    char inputfile[]="RandomNumbers.txt",treefile[]="Treefile.txt",infile[]="In-order.txt",prefile[]="Pre-order.txt",postfile[]="Post-order.txt";

    flush(fprandom,inputfile);
    flush(fptree,treefile);
    flush(fpin,infile);
    flush(fppre,prefile);
    flush(fppost,postfile);

    int ch,data,n;
    random_number_generate(fprandom,inputfile);
    ask_again:  printf("\nEnter number of random numbers to operate(<%d): ",MAXRAND);
                scanf("%d",&n);
                if(n>MAXRAND)
                {
                    printf("Invalid! Enter less than %d\n",MAXRAND);
                    goto ask_again;
                }
    while(1)
    {
        printf("\n 1:Insert to tree \n 2:In-Order \n 3:Pre-order \n 4:Post-Order \n 5.Exit \n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: read_from_file(fprandom,inputfile,n,fptree,treefile);
                    break;
            case 2: printf("\nIn-Order\n");
                    inorder(root,fpin,infile);
                    break;
            case 3: printf("\nPre-Order\n");
                    preorder(root,fppre,prefile);
                    break;
            case 4: printf("\nPost-Order\n");
                    postorder(root,fppost,postfile);
                    break;
            case 5: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
}
