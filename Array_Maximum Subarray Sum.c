#include <stdio.h>

// Maximum Subarray Sum - 12.48  28.07.2022
// https://leetcode.com/problems/maximum-subarray/
// https://www.youtube.com/watch?v=u202zgM7Fqk&list=PL1w8k37X_6L86f3PUUVFoGYXvZiZHde1S&index=3&ab_channel=KnowledgeCenter

int maximum_sub_array(int nums[25]);
int find_sum(int nums[25], int i, int j);

int main() {
    int nums[25] = {5,4,-1,7,8};
    
    printf("Largest sum = %d",maximum_sub_array(nums));
    return (0);
}


int maximum_sub_array(int nums[25]) {
    int i=0, j=4, sum, biggest_sum=0;

    while(i<j){
        sum = find_sum(nums,i,j);
        if(nums[i] < nums[j]){
            i++;
        }
        else {
            j--;
        }

        if(sum > biggest_sum){
            biggest_sum = sum;
        }

    }

    return biggest_sum;
}

int find_sum(int nums[25], int i, int j) {
    int sum=0;

    while(i<=j){
        sum += nums[i];
        i++;
    }

    return sum;
}



