#include <stdio.h>
#define N 4

// 11.26 24.07.2022 - Rat in a Maze Problem - I
// https://www.geeksforgeeks.org/c-program-for-rat-in-a-maze-backtracking-2/
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// https://www.youtube.com/watch?v=bLGZhJlt4y0&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=18&ab_channel=takeUforward


typedef enum {TRUE, FALSE}bool;
bool isSafe(int maze[N][N], int x, int y);
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);
void printSolution(int sol[N][N]);
bool solveMaze(int maze[N][N]);


int main() {
    int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 1, 1 },
                       { 0, 1, 0, 1 },
                       { 1, 1, 1, 1 } };
 
    solveMaze(maze);
    return 0;
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    if(x == N - 1 && y == N - 1){
        sol[x][y] = 1;
        return TRUE;
    }

    if(isSafe(maze,x,y) == TRUE){
        sol[x][y] = 1;
        if(solveMazeUtil(maze,x+1,y,sol) == TRUE) return TRUE;
        if(solveMazeUtil(maze,x,y+1,sol) == TRUE) return TRUE;
        else {
            sol[x][y] = 0;
            return FALSE;
        }

    }

    return FALSE;

}


bool solveMaze(int maze[N][N]) {
    int sol[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    if(solveMazeUtil(maze,0,0,sol) == FALSE){
        printf("Solution does not exist.");
        return FALSE;
    }

    printSolution(sol);
    return TRUE;

}


bool isSafe(int maze[N][N], int x, int y) {
    if(x >= 0 && x < N && y>=0 && y<N && maze[x][y] == 1) return TRUE;
    return FALSE;
}


void printSolution(int sol[N][N]) {
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}



