#include<stdio.h>
#define MAX 1000
int sp=-1;
void push(int stack[],int item)
{
    if(sp==MAX-1)                //overflow
    {
        printf("Stack overflow\n");
        return;
    }
    sp++;
    stack[sp]=item;
}
void display(int stack[])
{
    int item,count=0;
    while(sp!=-1)
    {
        item=pop(stack);
        printf("%d ",item);
        count++;
    }
    printf("\n");
    sp+=count;
}
int pop(int stack[])
{
    if(sp==-1)     //isempty
    {
        printf("Stack underflow\n");
        return;
    }
    int item=stack[sp];
    sp--;
    return item;
}
void reverse(int stack[])
{
    int temp;
    if(sp!=-1)
    {
        temp=pop(stack);
        printf("temp=%d",temp);
        reverse(stack);
        insert_at_bottom(stack,temp);
    }
}
void insert_at_bottom(int stack[],int item)
{
    if(sp==-1)
        push(stack,item);
    else
    {
        int temp=pop(stack);
        insert_at_bottom(stack,item);
        push(stack,temp);
    }
}
void main()
{
    int stack[MAX];
    int n,item;
    scanf("%d",&n);
    for(int i=0;i<n;i++)        //Complexity=n
    {
        scanf("%d",&item);
        push(stack,item);
    }
    display(stack);         //Complexity of this instruction is of order = n
    item=pop(stack);        //Complexity of this instruction is of order = constant
    display(stack);         //Complexity of this instruction is of order = n
    reverse(stack);         //Complexity of this instruction is of order = 2^n +2^n
    display(stack);
}
