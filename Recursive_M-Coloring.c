#include <stdio.h>
#define V 4
typedef enum {FALSE,TRUE}bool;
bool graphColoring(bool graph[V][V], int m, int i, int color[V]);
//m number of asked colors 

// 11.51 19.07.2022 - M-Coloring
// https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/
// https://www.youtube.com/watch?v=wuVwUK25Rfc&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&ab_channel=takeUforward
// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1


void printSolution(int color[])
{
    printf("Solution Exists:"
           " Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

bool isSafe(bool graph[V][V], int color[])
{
    // check for every edge
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (graph[i][j] && color[j] == color[i])
                return FALSE;
    return TRUE;
}

int main() {
    bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m=3, i;
    int color[V];

    for(i=0; i<V; i++){
        color[i] = 0;
    }

    if (!graphColoring(graph, m, 0, color))
        printf("Solution does not exist");
 
    return 0;

}

bool graphColoring(bool graph[V][V], int m, int i, int color[V]){
    int j;

    if(i == V){
        if(isSafe(graph,color)){
            printSolution(color);
            return TRUE;
        }

        return FALSE;
    }

    for(j=1; j<=m; j++){
        color[i] = j;
        if(graphColoring(graph,m,i+1,color) == TRUE){
            return TRUE;
        }
        color[i] = 0;
    }

    return FALSE;
}


