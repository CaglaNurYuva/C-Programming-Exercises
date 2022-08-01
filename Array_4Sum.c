#include <stdio.h>
#include <stdlib.h>

// https://programs.programmingoneonone.com/2021/08/leetcode-4sum-problem-solution.html#:~:text=In%20this%20Leetcode%204Sum%20problem,%2B%20nums%5Bd%5D%20%3D%3D%20target
// https://leetcode.com/problems/4sum/
// 4Sum - 14.03 01.08.2022

void Four_Sum(int *nums, int size, int target);
void bubble_sort(int *nums, int size);

int main() {
    int *nums, size,i,target;

    printf("Enter size of nums: ");
    scanf("%d",&size);
    nums = (int*)malloc(sizeof(int)*4);

   
    printf("Enter elements of nums array: ");
    for(i=0; i<size; i++){
        scanf("%d",&nums[i]);
    }

    printf("Enter target: ");
    scanf("%d",&target);


    Four_Sum(nums,size,target);
    free(nums);
    return (0);
}

void bubble_sort(int *nums, int size) {
    int i,j,temp;
    for(i=0; i<size; i++){
        for(j=i+1; j<size; j++){
            if(nums[i] > nums[j]){
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
           
        }
    }
}

void Four_Sum(int *nums, int size, int target){
    int i,j,k,m;

    bubble_sort(nums,size);
    for(i=0; i<size-3; i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }

        if(nums[i]*4 > target){
            break;
        }

        for(j=i+1; j<size-2; j++){

            if(j > i+1 && nums[j] == nums[j-1]){
                continue;
            }

            if(nums[j]*3+nums[i]> target) break;
            if(nums[size-1]*3+nums[i] < target) break;

            k = j+1;
            m = size - 1;

            while(k < m){
                if(nums[i] + nums[j] + nums[k] + nums[m] == target){
                    printf("[%d %d %d %d]\n",nums[i],nums[j],nums[k],nums[m]);
                    k++;
                    m--;
                }

                else if(nums[i] + nums[j] + nums[k] + nums[m] < target) {
                    k++;
                }

                else if(nums[i] + nums[j] + nums[k] + nums[m] > target) {
                    m--;
                }

            }
        }
    }
}



