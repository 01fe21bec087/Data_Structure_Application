#include<stdio.h>
#include<stdbool.h>

//Breadth First Search

void bfs(int m[6][6], int v, int source)
{
    int queue[20];
    int front = 0, rear = -1, u, i;
    bool visited[10]={};
    rear++;
    queue[rear] = source;
    visited[source] = true;
    printf("The BFS Traversal is... \n");
    while (front <= rear)
    {
        u = queue[front];
        printf("%d\t", u);
        front = front + 1;
        for(i=0;i<v;i++)
        {
            if(m[u][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                rear = rear + 1;
                queue[rear] = i;
            }
        }
    }
}
int main() {
    int v = 5;
    int m[6][6] = {{0,1,1,0,0}, {1,0,0,1,1},{1,0,0,0,1}, {0,1,0,0,0}, {0,1,1,0,0}};
    int source = 4;
    bfs(m, v, source);
    return 0;
}
