// Adjacency Matrix representation
#include <stdio.h>
#define V 4
// Initialize the matrix to zero
void init(int arr[][V]) {
  int i, j;
  for(i=0;i<V;i++)
    for(j=0;j<V;j++)
        arr[i][j]=0;
}
// Add edges
void addEdge(int arr[][V], int row, int col) {
    arr[row][col]=1;
    arr[row][col]=1;
}
// Print the matrix
void printAdjMatrix(int arr[][V]) {
    int i,j;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
}
void main() {
    int adjMatrix[V][V];
    init(adjMatrix);
    addEdge(adjMatrix,0,1);
    addEdge(adjMatrix,0,2);
    addEdge(adjMatrix,1,2);
    addEdge(adjMatrix,2,0);
    addEdge(adjMatrix,2,3);
    printAdjMatrix(adjMatrix);
}
