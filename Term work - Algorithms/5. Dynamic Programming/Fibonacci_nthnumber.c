//Finding nth element in Fibonacci Series using Dynamic Programming
#include<stdio.h>

struct node             //Structure declaration
{
    int data;
    struct node *next;
};
typedef struct node *NODE;            //alias name for structure
NODE head, newnode, temp, cur,next,prev,beforeprev;          //Global declaration
NODE head=NULL;

NODE getnode()              //Creating a new node
{
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)           //Overflow condition    (maximum memory reached)
    {
        printf ("Memory not allocated for node! \n");
        exit(0);
    }
    newnode->next=NULL;     //assigning link of created node to NULL
    return newnode;
}

NODE insertend(int num)             //Insert newnode at the end of SLL
{
    newnode=getnode();              //Creating newnode
    newnode->data=num;              //assign data into node
    if(head==NULL)                  //SLL is empty
    {
        head=newnode;               //newnnode is the first node
    }
    else                            //SLL exists
    {
        temp=head;
        while(temp->next!=NULL)    //traverse till the end of SLL
            temp=temp->next;
        temp->next=newnode;         //last node
    }
    return(newnode);
}

void display_SLL(NODE head)
{
    if(head==NULL)                 //empty SLL
    {
        printf ("No data available in Linked list!");
        return;
    }
    temp=head;
    printf("Displaying numbers from nodes: ");
    do                              //traversing throughout the SLL (since it is not empty)
    {
        printf ("%d ",temp->data);
        temp=temp->next;
    }while(temp!=NULL);
}
int fibonacci(int n)
{
    beforeprev=NULL;
    prev=insertend(0);
    cur=insertend(1);
    for (int i=2;i<=n;i++)
    {
        int buffer_fib = cur->data + prev->data;
        beforeprev=prev;
        prev=cur;
        cur=insertend(buffer_fib);
    }
    return (cur->data);
}

int main ()
{
    int n,nth_fib;
    scanf("%d",&n);
    nth_fib=fibonacci(n);
    display_SLL(head);
    printf("\n%d\n", nth_fib);
}
