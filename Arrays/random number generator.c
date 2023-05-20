/*
Author: Abhinav Sushil Pawar
Date: 24/04/2023
*/
/*Random number generator
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
        num[i]=rand()%200;      //numbers less than 200 will be generated
        printf("%d\n",num[i]);
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
            fprintf(fptr,"%d\n",num[i]);        //store random number array to file
    }
}
