#include <stdio.h>

typedef enum {FALSE,TRUE}bool;
bool is_safe(char array[4][4], int row, int col, int n);
void n_queens(char array[4][4],int col, int n); // n equals one side of square

// https://leetcode.com/problems/n-queens/
// 22.21 16.07.2022
// https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=15&ab_channel=takeUforward
// N-Queens 

int main() {
    char array[4][4] = {"....","....","....","...."};
    n_queens(array,0,4);
    return (0);
}

bool is_safe(char array[4][4], int row, int col, int n) {
    int row_backup, col_backup;
    row_backup = row;
    col_backup = col;

    while(row >= 0 && col >= 0) {
        if(array[row][col] == 'Q') return FALSE;
        row--;
        col--;
    }

    row = row_backup;
    col = col_backup;

    while(col >= 0) {
        if(array[row][col] == 'Q') return FALSE;
        col--;
    }

    row = row_backup;
    col = col_backup;

    while(row<n && col >= 0) {
        if(array[row][col] == 'Q') return FALSE;
        col--;
        row++;
    }

    return TRUE;

}

void n_queens(char array[4][4],int col, int n){
    int row;

    if(col == n) {
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                printf("%c ",array[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for(row=0; row<n; row++){
        if((is_safe(array,row,col,n)) == TRUE){
            array[row][col] = 'Q';
            n_queens(array,col+1,n);
            array[row][col] = '.';
        }
    }


}


