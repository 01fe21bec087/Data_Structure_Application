//Binary Search tree
/*
Author: Abhinav Sushil Pawar
Date: 07-06-2023
*/
/*
Constraint: Maximum MAXRAND(26*2) number of random letters can be generated
MAXRAND number of Random characters are generated (within the range (max,min)) and stored in file.
n number of these random characters are inserted into tree, and stored in file.
The elements of this tree are traversed in all the three modes (In-order,Pre-order,Post-order), and are stored in individual files.
*/
#include <stdio.h>
#define MAXRAND 26*2
struct Tree
{
    char data;
    struct Tree *left;  //Pointer to the left child nodes of binary tree
    struct Tree *right;  //Pointer to the right child nodes of binary tree
};
typedef struct Tree *TREE;
TREE root=NULL;
//Function to create a new node and assign specified data for a binary tree
TREE getnode(char data)
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
TREE insert(TREE root,char data)
{
    if(root==NULL)  //Base condition for recursion call
    {
        root=getnode(data);  //new node is created with given data and returned as new root
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
        printf("%c ",root->data);
        append_to_file(fpin,infile,root->data);
        inorder(root->right,fpin,infile);
    }
}
//Display of binary tree in root node, left node, right node order, and adding to file
void preorder(TREE root,FILE* fppre,char prefile[])
{
    if(root!=NULL)
    {
        printf("%c ",root->data);
        append_to_file(fppre,prefile,root->data);
        preorder(root->left,fppre,prefile);
        preorder(root->right,fppre,prefile);
    }
}
//Display of binary tree in left node, right node, root node order, and adding to file
postorder(TREE root,FILE* fppost,char postfile[])
{
    if(root!=NULL)
    {
        postorder(root->left,fppost,postfile);
        postorder(root->right,fppost,postfile);
        printf("%c ",root->data);
        append_to_file(fppost,postfile,root->data);
    }
}

void append_to_file(FILE* fptr,char filename[],char data)
{
    fptr=fopen(filename,"a");
    if(fptr==NULL)
    {
        printf("'%s' File creation error!\n",filename);
    }
    else
    {
        fprintf(fptr,"%c\n",data);
        //printf("Entered data %d to file %s successfully\n",data,filename);
    }
    fclose(fptr);
}


void random_letter_generate(FILE* fptr,char filename[])
{
    //Lookup table for all possible letters in English alphabet
    char letter[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int random,flag;
    char reading;
    fptr=fopen(filename,"r");
    for(int i=0;i<MAXRAND;i++)
    {
       Create:
       //flag=0;
       random=rand()%MAXRAND;
       while(!feof(fptr))        //Checking for repetition
       {
           fscanf(fptr,"%c",&reading);
            if(letter[random]==reading)
            {
                goto Create;
                //flag=1;
                //break;
            }
       }
        append_to_file(fptr,filename,letter[random]);
    }
    fclose(fptr);
}

void read_from_file(FILE* fptr,char filename[],int n,FILE* fptree,char treefile[])
{
    fptr=fopen(filename,"r");
    if(fptr==NULL)
    {
        printf("'%s' File reading error!\n",filename);
    }
    else
    {
        char data;
        printf("'%s' File reading successfully\n",filename);
        for(int i=0;i<n;i++)
        {
            fscanf(fptr,"%c ",&data);
            root=insert(root,data);
            append_to_file(fptree,treefile,data);
            printf("%c ",data);
        }
        printf("\nEntered %d numbers from file to tree successfully!\n",n);
    }
}
void flush(FILE* fptr, char filename[])
{
    fptr=fopen(filename,"w");
    fclose(fptr);
    printf("Clearing '%s' file...\n",filename);
}
int main()
{
    FILE *fprandom,*fptree,*fpin,*fppre,*fppost;
    char inputfile[]="RandomNumbers.txt",treefile[]="Treefile.txt",infile[]="In-order.txt",prefile[]="Pre-order.txt",postfile[]="Post-order.txt";

    flush(fprandom,inputfile);
    flush(fptree,treefile);
    flush(fpin,infile);
    flush(fppre,prefile);
    flush(fppost,postfile);

    int ch,n;
    char data;
    random_letter_generate(fprandom,inputfile);

    readagain:
        printf("\nEnter number of random numbers to operate(<%d): ",MAXRAND);
        scanf("%d",&n);
        if(n>MAXRAND)
        {
            printf("Enter value less than %d\n",MAXRAND);
            goto readagain;
        }
    while(1)
    {
        printf("\n1.Insert to tree\n2.In-Order\n3.Pre-order\n4.Post-Order\n5.Exit\n");
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
            break;
        }
    }
    return 0;
}
