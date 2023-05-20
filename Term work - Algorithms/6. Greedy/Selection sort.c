// selection sort using greedy algorithm
#include <stdio.h>
#define MAX 1000
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selectionSort(int arr[],int n)
{
    int min_index;
    for(int i=0;i<n-1;i++)
    {
        min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_index])       //sorted the subarray
                min_index=j;                //Ascending order
            if(min_index!=i)
                swap(&arr[min_index],&arr[i]);
        }
    }
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
void read(int* array,int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",array);
        (array)++;
    }
}
/*
void display(int* arr, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",*arr);
        (arr)++;
    }
}
*/
void main()
{
    int n,array[MAX];
    scanf("%d",&n);
    read(&array,n);
    selectionSort(array,n);
}
