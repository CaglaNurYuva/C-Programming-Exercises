#include <stdio.h>

// Remove Element 17.21 01.08.2022
// https://leetcode.com/problems/remove-element/

int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int i,size=10,j,k=0, val;

    printf("Enter val: ");
    scanf("%d",&val);

    for(i=0; i<size; i++){
        if(nums[i] == val){
            for(j=i+1; j<size; j++){
                nums[j-1] = nums[j];
            }
            size--;
            i--;
        }

        else k++;
    }

    for(i=0; i<size; i++){
        printf("%d ",nums[i]);
    }

    printf("\nk=%d\n",k);
}


