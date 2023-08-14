#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10
// Structure to represent a cell in the maze
typedef struct {
    int row;
    int col;
} Cell;
// Structure to store the cells in the BFS queue
typedef struct {
    Cell items[MAX_SIZE * MAX_SIZE];
    int front;
    int rear;
} Queue;
// Function to perform BFS and solve the maze
bool bfsMazeSolver(int maze[MAX_SIZE][MAX_SIZE], int startRow, int startCol, int endRow, int endCol, int numRows, int numCols) {
    Queue queue;
    queue.front = -1;
    queue.rear = -1;
    bool visited[MAX_SIZE][MAX_SIZE] = {false};
    Cell parent[MAX_SIZE][MAX_SIZE];

    Cell startCell = {.row = startRow, .col = startCol};
    enqueue(&queue, startCell);
    visited[startRow][startCol] = true;
    parent[startRow][startCol] = startCell;

    while (!isEmpty(&queue)) {
        Cell currentCell = dequeue(&queue);
        if (currentCell.row == endRow && currentCell.col == endCol) {
            printf("Path found!\n");
            printPath(parent, currentCell);
            return true;
        }
        // Generate all possible moves
        int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int newRow = currentCell.row + moves[i][0];
            int newCol = currentCell.col + moves[i][1];
            if (isValidMove(maze, newRow, newCol, numRows, numCols) && !visited[newRow][newCol]) {
                Cell newCell = {.row = newRow, .col = newCol};
                enqueue(&queue, newCell);
                visited[newRow][newCol] = true;
                parent[newRow][newCol] = currentCell;
            }
        }
    }
    printf("No path found!\n");
    return false;
}

// Function to check if a move is valid within the maze boundaries
bool isValidMove(int maze[MAX_SIZE][MAX_SIZE], int row, int col, int numRows, int numCols) {
    return (row >= 0 && row < numRows && col >= 0 && col < numCols && maze[row][col] == 0);
}

// Function to print the path from start to end cell
void printPath(Cell parent[MAX_SIZE][MAX_SIZE], Cell currentCell) {
    if (parent[currentCell.row][currentCell.col].row == currentCell.row && parent[currentCell.row][currentCell.col].col == currentCell.col) {
        printf("(%d, %d) ", currentCell.row, currentCell.col);
        return;
    }
    printPath(parent, parent[currentCell.row][currentCell.col]);
    printf("(%d, %d) ", currentCell.row, currentCell.col);
}
// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == -1;
}
// Function to add an element to the queue
void enqueue(Queue* queue, Cell cell) {
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear++;
    queue->items[queue->rear] = cell;
}
// Function to remove an element from the queue
Cell dequeue(Queue* queue) {
    Cell item = queue->items[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;
    return item;
}
void main() {
    int maze[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0}
    };
    int numRows = 5;
    int numCols = 5;
    int startRow = 0;
    int startCol = 0;
    int endRow = 4;
    int endCol = 4;
    printf("Solving the maze...\n");
    bfsMazeSolver(maze, startRow, startCol, endRow, endCol, numRows, numCols);
}
