#include <stdio.h>
#include <limits.h>

// https://leetcode.com/problems/3sum-closest/
// https://leetcode.com/problems/3sum-closest/discuss/2354158/3Sum-Fast-Solution-with-Sorting
// 3Sum Closest 12.48 31.07.2022

void bubble_sort(int nums[4], int size) {
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


int main() {
    int nums[4] = {-1,2,1,-4};
    int i,j,k, target,absolute_value,min=INT_MAX,closet_sum;

    printf("Enter target = ");
    scanf("%d",&target);

    bubble_sort(nums,4);

    for(i=0; i<4; i++){
        j = i+1;
        k = 4-1;

        if(nums[i]+nums[j]+nums[k] == target){
            printf("Target = [%d %d %d]\n",nums[i],nums[j],nums[k]);
            return (0);
        }

        absolute_value = (nums[i]+nums[j]+nums[k])-target;
        if(absolute_value < 0){
            absolute_value *= -1;
        }

        if(absolute_value<min){
            min = absolute_value;
            closet_sum = nums[i]+nums[j]+nums[k];
        }

        if(nums[i]+nums[j]+nums[k]<target){
            j++;
        }

        else k--;

    }

    printf("Closest sum = %d\n",closet_sum);

}
