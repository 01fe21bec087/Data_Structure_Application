#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE head, newnode, temp, cur,next,prev;          //Global declaration
NODE head=NULL;

NODE getnode()
{
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf ("Memory not allocated for node! \n");
        exit(0);
    }
    newnode->next=NULL;
    return newnode;
}
void findmiddle(NODE head)
{
    NODE middle=head,fast=head,slow=head;
    if(head==NULL)
        printf("SLL is empty\n");
    else
    {
        while(fast!=NULL && fast->next!=NULL)   // && fast->next->next!=NULL)   --> if first number of the middle two nos is to be assigned (in case of even number of numbers)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        middle=slow;
    }
    printf("Middle element is %d\n",middle->data);
}

void display_SLL(NODE head)
{
    if(head==NULL)
    {
        printf ("No data available in Linked list!");
    }
    temp=head;
    printf("\n\nDisplaying numbers from nodes:\n");
    do
    {
        printf ("%d\t",temp->data);
        temp=temp->next;
    }while(temp->next!=NULL);
    printf ("%d ",temp->data);
}

NODE reverse_nodes(NODE head,int n)
{
    cur=head;
    prev=head;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head=prev;
}
NODE insertend(int num)
{
    newnode=getnode();
    newnode->data=num;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
    //printf("Entered the element %d in a node\n",newnode->data);
    return(head);
}

void main()
{
    int choice,num,middle;
    while(1)
    {
    printf("\n1:Insert\n2:Findmiddle\n3:Display\n4:exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: scanf("%d",&num);
                newnode=insertend(num);    break;
        case 2: findmiddle(head);
                break;
        case 3: display_SLL(head);break;
        case 4: exit(0); break;
        default: printf("invalid choice!\n");
    }
    }
}
