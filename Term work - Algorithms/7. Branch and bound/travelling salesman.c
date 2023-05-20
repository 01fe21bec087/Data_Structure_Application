// traveling salesman problem

#include <limits.h>
#define MAX_CITIES 10
int graph[MAX_CITIES][MAX_CITIES];int numCities;
int min(int a, int b) {   
    return (a < b) ? a : b;
}
int tsp(int mask, int currentCity)
{   
    if (mask == (1 << numCities) - 1)
    {        // All cities visited, return to starting city       
        return graph[currentCity][0];   
    }
    int minDistance = INT_MAX;
    for (int nextCity = 0; nextCity < numCities; nextCity++)
    {       
        if ((mask & (1 << nextCity)) == 0)
        {           
            int distance = graph[currentCity][nextCity] + tsp(mask | (1 << nextCity), nextCity); 
            minDistance = min(minDistance, distance);       
        }
    }
    return minDistance;
}
void main()
{   
    printf("Enter the number of cities: ");   
    scanf("%d", &numCities);
    printf("Enter the adjacency matrix:\n");   
    for (int i = 0; i < numCities; i++)
    {       
        for (int j = 0; j < numCities; j++)
        {           
            scanf("%d", &graph[i][j]);       
        }   
    }
    int startingCity = 0; 
    int initialMask = 1 << startingCity;   
    int shortestDistance = tsp(initialMask, startingCity);
    printf("Shortest distance: %d\n", shortestDistance);
}
