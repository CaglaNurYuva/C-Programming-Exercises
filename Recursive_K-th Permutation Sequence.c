#include <stdio.h>

void swapping(int index1, int index2, int array[25]);
void permutations(int index1, int array[25], int n);
int k;

// 10.41 24.07.2022 - K-th Permutation Sequence
// https://www.youtube.com/watch?v=wT7gcXLYoao&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=30&ab_channel=takeUforward
// https://leetcode.com/problems/permutation-sequence/

int main() {
    int array[25], n, i;

    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter k: ");
    scanf("%d",&k);

    for(i=0; i<n; i++){
        array[i] = i+1;
    }

    permutations(0,array,n);
    return (0);
}

void permutations(int index1, int array[25], int n) {
    int i, j;

    if(index1 == n){
        k--;
        if(k == 0){
            for(i=0; i<n; i++){
                printf("%d",array[i]);
            }

            printf("\n");
        }
        
        return;
    }

    for(j=index1; j<n; j++){
        swapping(index1,j,array);
        permutations(index1+1,array,n);
        swapping(index1,j,array);
    }
    
}

void swapping(int index1, int index2, int array[25]){
    int temp;
    temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}


