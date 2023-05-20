//Find the minimum number of currency notes/coins for the amount in the denominations (given in notes[]) by reading the amount.
#include<stdio.h>
#define MAX 100
int notes[]={2000,500,200,100,50,20,10,5,2,1};     //10
int denomination[MAX];
void Minimum_change(int sum,int n)
{
    for(int i=0;i<n;i++)
    {
        denomination[i]=0;
        while(sum>=notes[i])
        {
            sum=sum-notes[i];
            denomination[i]++;
        }
    }
    display(&notes,&denomination,n);
}
void display(int* notes, int* denomination,int n)
{
    int change=0;
    printf("Notes \t Denomination \n");
    for(int i=0;i<n;i++)
    {
        printf("%d \t %d \n",*notes,*denomination);
        (notes)++;
        (denomination)++;
        change+=*denomination;
    }
    printf("Total number of notes: %d\n",change);
}
void main()
{
    int sum,n=sizeof(notes)/sizeof(notes[0]);
    scanf("%d",&sum);
    Minimum_change(sum,n);
}
