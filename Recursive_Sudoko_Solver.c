#include <stdio.h>

typedef enum{FALSE,TRUE}bool;
bool sudoku_solver(char board[9][9]);
bool isValid(int row, int col, char num, char board[9][9]);

// 12.25 18.07.2022 - Sudoko Solver
// https://leetcode.com/problems/sudoku-solver/
// https://www.youtube.com/watch?v=FWAIf_EVUKE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=19&ab_channel=takeUforward

int main() {
    int i,j;
    char board[9][9] = {"53..7....",
                        "6..195...",
                        ".98....6.",
                        "8...6...3",
                        "4..8.3..1",
                        "7...2...6",
                        ".6....28.",
                        "...419..5",
                        "....8..79"};
    sudoku_solver(board);
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    return (0);                    
}

bool sudoku_solver(char board[9][9]) {
    int i,j;
    char c;

    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            if(board[i][j] == '.') {
                for(c = '1'; c<= '9'; c++){
                    
                    if(isValid(i,j,c,board) == TRUE){
                        board[i][j] = c;
                        
                        if(sudoku_solver(board) == TRUE){
                            return TRUE;
                        }

                        else {
                            board[i][j] = '.';
                        }
                    }

                    
                }

                return FALSE;
            }

        }
    }

    return TRUE;
}

bool isValid(int row, int col, char num, char board[9][9]) {
    int i;
    for(i=0; i<9; i++){
        if(board[row][i] == num) return FALSE;
        if(board[i][col] == num) return FALSE;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == num) return FALSE;
    }
    return TRUE;
}


