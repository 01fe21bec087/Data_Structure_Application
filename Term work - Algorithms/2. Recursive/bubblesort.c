#include <stdio.h>
#define MAX 1000
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int arr[], int n)
{
    if (n == 1)         // Base case
        return;

    int count = 0;
    for (int i=0; i<n-1; i++)
    {
        if (arr[i] > arr[i+1])      //ascending order
        {
            swap(&arr[i], &arr[i+1]);
            count++;
        }
    }
      if (count==0)
           return;

    bubblesort(arr, n-1);       //upto nth element is sorted, sort remaining
}
void read(int array[],int n)
{
    for(int i=0;i<n;i++){           //f(n)=n+1
        scanf("%d",&array[i]);
    }
}
void display(int array[], int n)
{
    for (int i=0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}
void main()
{
    int array[MAX];
    int n;
    scanf("%d",&n);
    read(array,n);
    bubblesort(array, n);
    printf("Sorted array : \n");
    display(array, n);
}
