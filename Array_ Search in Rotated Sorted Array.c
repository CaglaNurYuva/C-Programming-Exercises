#include <stdio.h>

// https://leetcode.com/problems/search-in-rotated-sorted-array/
// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/2366254/Easiest-soltuion-logN
// Search in Rotated Sorted Array 00.35 02.08.2022

int rotated_sorted_array(int nums[], int size, int target);

int main() {
    int nums[] = {4,5,6,7,0,1,2};
    int target;

    printf("Enter target = ");
    scanf("%d",&target);

    printf("Output = %d",rotated_sorted_array(nums,7,target));
    return (0);
}

int rotated_sorted_array(int nums[], int size, int target){
    int start=0, end=size-1, i;
    
    if(target == nums[start]) return start;
    if(target == nums[end]) return end;

    if(target > nums[start]) {
        for(i=start; i<=end; i++){
            if(nums[i] == target) return i;
        }
    }

    if(target < nums[end]){
        for(i=end; i>=0; i--){
            if(nums[i] == target) return i;
        }
    }

    return -1;

}


