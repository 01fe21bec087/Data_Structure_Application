//Golomb sequence using dynamic programming
/*Golomb sequence is a sequence where n-th term is equal to number of times n appears in the sequence.
*/
#include<stdio.h>
void Generate_Golomb(int n)
{
    int G[n+1];
    G[1]=1;     //base case
    for(int i=1;i<n;i++)
    {
        G[i+1]=1+G[(i+1)-G[G[i]]];
    }
    printf("Golomb sequence with position of each element:\n");
    display(G,n);
}
void display(int array[],int n)
{
    printf("Sequence: ");
    for(int i=1;i<n;i++){
        printf(" %d ",array[i]);
        if(i>9) printf(" ");
    }
    printf("\nPosition: ");
    for(int i=1;i<n;i++)
        printf(" %d ",i);
}
void main()
{
    int n;
    scanf("%d",&n);
    Generate_Golomb(n);
}
