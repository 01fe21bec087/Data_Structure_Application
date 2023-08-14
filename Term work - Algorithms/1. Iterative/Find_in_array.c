//Find a key element in array using for loop
/*
Input format:
First line contains number of array elements to be entered
Subsequent lines contain the array elements
Last line is the key element
*/
#include<stdio.h>
#define MAX 100
void read(int array[],int n)
{
    for(int i=0;i<n;i++){           //f(n)=n+1
        scanf("%d",&array[i]);
    }
}
int search(int array[], int n,int key)
{
    int j,found=0;
    for(j=0;j<n;j++)
    {
        if(array[j]==key)
        {
            found=1;
            break;
        }
    }
    if(found==1)
        return j;
    else
        return -1;
}
void main()
{
    int array[MAX];
    int n,key;
    scanf("%d",&n);
    read(array,n);
    scanf("%d",&key);
    int index=search(array,n,key);
    printf("%d\n",index);
}
