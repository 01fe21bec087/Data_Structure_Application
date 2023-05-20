//the requirements for Sudoku solution: (non-duplication across rows,columns, and boxes)
#include <stdio.h>
#include <stdlib.h>
#define N 9

int checkelement(int partsudoku[N][N], int row,int col, int num)
{
    for (int x = 0; x <= N-1; x++)        //Check for identical numbers in row
    {
         if (partsudoku[row][x] == num)
            return 0;
    }

    for (int x = 0; x <= N-1; x++)         //Check for identical numbers in column
    {
        if (partsudoku[x][col] == num)
            return 0;
    }

    int rowBeg,colBeg;
    rowBeg = row - row%3;
    colBeg = col - col%3;
    for (int i = 0; i < 3; i++)             //Check for identical number in 3x3 box
    {
        for (int j = 0; j < 3; j++)
        {
            if (partsudoku[i+rowBeg][j+colBeg] == num)
                return 0;
        }
    }
    return 1;       //No identical elements
}

int solveSudoku(int partSudoku[N][N], int row, int col)
{
    if (row == N - 1 && col == N)       //check if reached the end of sudoku (last row (index=8), and last+1 column (index=9))
        return 1;                       //solved

    if (col == N)                     //check if we reached the end of particular row (last+1 column (index=9))
    {
        row++;                          //reinitialise indices for next row
        col = 0;
    }
    if (partSudoku[row][col] > 0)                       //checks if element at this position is >0
        return solveSudoku(partSudoku, row, col + 1);   //if true,check for next col

    for (int num = 1; num <= N; num++)                  //check for all 9 numbers, one by one, to enter in grid
    {
        if (checkelement(partSudoku, row, col, num)==1)
        {
            partSudoku[row][col] = num;                  //assuming entered element is correct
            if (solveSudoku(partSudoku, row, col + 1)==1) //Check for next column
                return 1;
        }
        //Assumption is wrong -------. Backtrack
        partSudoku[row][col] = 0;       //Hence remove the incorrect assumption
    }
    return 0;
}
void display(int array[N][N])
{
     for (int i=0;i<N;i++)
      {
         for (int j=0;j<N;j++)
         {
            printf("%d ",array[i][j]);
         }
         printf("\n");
       }
}
void main()
{
    int partSudoku[N][N] = {
                       { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
                       };
    int status = solveSudoku(partSudoku, 0, 0);     //start by checking 1st element
    if (status==1)
        display(partSudoku);
    else
        printf("No solution found!");
}
