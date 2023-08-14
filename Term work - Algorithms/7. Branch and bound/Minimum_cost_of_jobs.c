#include<stdio.h>
#include<limits.h>
void main()
{
    int workers,jobs,min_cost;
    scanf("%d",&workers);
    scanf("%d",&jobs);
    int cost[workers][jobs];
    for(int i=0;i<workers;i++)
    {
        for(int j=0;j<jobs;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }

    for(int i=0;i<workers;i++)
    {
        printf("\n");
        for(int j=0;j<jobs;j++)
        {
            printf("%d\t",cost[i][j]);
        }
        printf("\n");
    }


    int fix_index[jobs];
    for(int m=0;m<jobs;m++)
        fix_index[m]=-1;

    for(int i=0;i<workers;i++)
    {
        printf("\n Worker %d: ",i);
        min_cost=INT_MAX;//cost[0][0];
        for(int j=0;j<jobs;j++)
        {
            int k=0;
            do
            //for(int k=0;k<=fix_index[i-1];k++)
            {
                if(j!=fix_index[k])
                {
                    if(cost[i][j]<min_cost)
                    {
                        min_cost=cost[i][j];
                        printf("Min cost = %d, at index i,j = %d,%d\n",min_cost,i,j);
                        fix_index[i]=j;
                    }
                }
                k++;
            }while(k<=fix_index[i-1]);
        }
    }
    int total_cost=0;
    for(int i=0;i<workers;i++)
    {
        for(int j=0;j<jobs;j++)
        {
            if(fix_index[j]==i)
            {
                printf("Min cost = %d, at index i,j = %d,%d\n",cost[i][j],i,j);
                total_cost+=cost[i][j];
            }
        }
    }
    printf("Total cost = %d\n",total_cost);
/*
    min_cost=INT_MAX;//cost[0][0];
    for(int i=0;i<workers;i++)
    {
        if(cost[i][0]<min_cost)
        {
            min_cost=cost[i][0];
            fix_index[0]=i;
        }
    }
    min_cost=INT_MAX;//cost[0][1];
    for(int i=0;i<workers;i++)
    {
        if(fix_index[0]!=i)
        {
            if(cost[i][1]<min_cost)
            {
                min_cost=cost[i][1];
            }
        }
    }*/
}
