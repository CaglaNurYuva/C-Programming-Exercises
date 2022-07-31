#include <stdio.h>
// https://www.programcreek.com/2012/12/leetcode-3sum/
// https://leetcode.com/problems/3sum/
// 3Sum 11.40 31.07.2022

void bubble_sort(int nums[6], int size);

int main() {
    int i,j,k;
    int nums[6] = {-1,0,1,2,-1,-4};

    bubble_sort(nums,6);

    for(i=0; i<6; i++){
        j = i+1;
        k = 6-1;

        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }

        while(j<k){
            if(k<5 && nums[k]==nums[k+1]){
                k--;
                continue;
            }

            if(nums[i]+nums[j]+nums[k]>0){
                k--;
            }

            else if(nums[i] + nums[j] + nums[k] < 0){
                j++;
            }

            else {
                printf("[%d %d %d]\n",nums[i],nums[j],nums[k]);
                j++;
                k--;
            }


        }


    }

    return (0);
}

void bubble_sort(int nums[6], int size) {
    int i,j,temp;

    for(i=0; i<size; i++){
        for(j=i;j<size;j++){
            if(nums[i]>nums[j]){
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}





