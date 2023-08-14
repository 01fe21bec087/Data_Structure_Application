/*
Author: Abhinav Pawar
Date: 11-05-2023
*/
/*Find sum of digits of a number

Constraint: array maximum size 1000
input format: first line is the number
output format: sum of digits
*/
#include<stdio.h>
void main()
{
    int num,sum=0;
    scanf("%d",&num);
    while(num!=0)
    {
        sum=sum+num%10;
        num=num/10;
    }
    printf("%d",sum);
}
/*
sample input: 1357
sample output: 16
*/
