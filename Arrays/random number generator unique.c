/*
Author: Abhinav Sushil Pawar
Date: 12/05/2023
*/
/*Unique Random number generator
Constraint: maximum 100000 random numbers can be generated using this program
*/
#include<stdio.h>
#define MAX 10000
void main()
{
    int n,num[MAX];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        num[i]=rand()%200;
        for(int j=0;j<i;j++)
        {
            if(num[i]==num[j]){
                num[i]=rand()%200;
                continue;
            }
        }
        printf("%d\t",num[i]);
    }

    FILE *fptr;
    fptr=fopen("Random_number.txt","w");
    if(fptr==NULL)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("File for random number created successfully\n");
        for(int i=0;i<n;i++)
            fprintf(fptr,"%d\n",num[i]);
    }
}
