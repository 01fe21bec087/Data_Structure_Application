//Matrix multiplication using Strassens Algorithm
#include<stdio.h>
#define MAX 100
int resMatrix[MAX][MAX];
int resMatrix2[MAX][MAX],resMatrix3[MAX][MAX],resMatrix4[MAX][MAX];
void addmatrix(int matrixA[MAX][MAX],int matrixB[MAX][MAX],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            resMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}
void mulmatrix(int matrixA[MAX][MAX],int row1,int col1,int matrixB[MAX][MAX],int row2,int col2)
{
    if(row2==col1)
    {
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<col2;j++)
            {
                resMatrix[i][j]=matrixA[i][0]*matrixB[0][j];
                if (col1>1){
                    resMatrix2[i][j]=matrixA[i][1]*matrixB[1][j];
                    if(col1>2){
                        resMatrix3[i][j]=matrixA[i][2]*matrixB[2][j];
                        if(col1>3)
                            resMatrix4[i][j]=matrixA[i][3]*matrixB[3][j];
                    }
                }
            }
        }
        if(col1>1){
            addmatrix(resMatrix,resMatrix2,row1,col2);
            if(col1>2){
                addmatrix(resMatrix,resMatrix3,row1,col2);
                if(col1>3)
                    addmatrix(resMatrix,resMatrix4,row1,col2);
            }
        }
    }
    else
    {
        printf("Matrix multiplication not possible!\n");
        exit(0);
    }
}
void readmatrix(int matrix[MAX][MAX], int row, int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
}
void displaymatrix(int matrix[MAX][MAX],int row, int col)
{
    for(int i=0;i<row;i++)
    {
        printf("\t\t");
        for(int j=0;j<col;j++)
        {
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
}
void main()
{
    int matrixA[MAX][MAX],matrixB[MAX][MAX];
    int row1,col1,row2,col2;
    scanf("%d%d",&row1,&col1);
    readmatrix(matrixA,row1,col1);
    printf("\nMatrix A: \n");
    displaymatrix(matrixA,row1,col1);
    scanf("%d%d",&row2,&col2);
    readmatrix(matrixB,row2,col2);
    printf("\nMatrix B: \n");
    displaymatrix(matrixB,row2,col2);
    mulmatrix(matrixA,row1,col1,matrixB,row2,col2);
    printf("\n\nResultant multiplied matrix: \n");
    displaymatrix(resMatrix,row1,col2);
}
