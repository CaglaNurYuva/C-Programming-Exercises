#include <stdio.h>

// https://www.youtube.com/watch?v=YK78FU5Ffjw&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=13&ab_channel=takeUforward
// https://leetcode.com/problems/permutations/
// 07.07.2022 12.55 - Permutations of a string/array

typedef enum{FALSE, TRUE}bool;
void permute(bool freq[25], int input[25], int output[25], int index);
int ind=0;

int main() {
    int input[25] = {1,2,3}; //its length must be known
    int output[25], i;
    bool freq[25];
    
    for(i=0; i<3; i++){
        freq[input[i]-1] = FALSE;
    }

    permute(freq,input,output,0);
    return 0;
}

void permute(bool freq[25], int input[25], int output[25], int index){
    int i;

    if(index == 3) {
        printf("[");
        for(i=0; i<3; i++){
            printf("%d ",output[i]);
        }
        printf("]\n");
        return;
    }

    for(i=0; i<3; i++){
        if(freq[i] == FALSE){
            freq[i] = TRUE;
            output[ind] = input[i];
            ind++;
            permute(freq,input,output,ind);
            ind--;
            freq[i] = FALSE;
        }
    }
    
}




