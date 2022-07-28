#include <stdio.h>
// Two Sum - 10.26 28.07.2022
// https://leetcode.com/problems/two-sum/
// https://www.youtube.com/watch?v=VbVQJRKXxBA&list=PL1w8k37X_6L86f3PUUVFoGYXvZiZHde1S&ab_channel=KnowledgeCenter


int main() {
    int array[25] = {2,7,11,15}; 
    int target, i, j;

    printf("Enter target: ");
    scanf("%d",&target);

    for(i=0; i<4; i++){
        for(j=i+1; j<4; j++){
            if(array[i] + array[j] == target){
                printf("[%d, %d]",i,j);
                return 0;
            }
        }
    }

    printf("No solution");
    return 0;
}
