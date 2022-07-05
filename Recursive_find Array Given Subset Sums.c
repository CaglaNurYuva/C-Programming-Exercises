#include <stdio.h>

void subset_sum(int output[25], int input[25], int sum, int length, int index);
void sorting(int array[25], int length);
int ind=0;

// 13.53 05.07.2022 - Find Array Given Subset Sums
// https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=13&ab_channel=takeUforward
// https://leetcode.com/problems/find-array-given-subset-sums/

int main() {
    int input[25] = {3,1,2};
    int output[25],i;
    subset_sum(output,input,0,3,0);
    sorting(output,ind);

    for(i=0; i<ind; i++){
        printf("%d ",output[i]);
    }
    return 0;
}


void subset_sum(int output[25], int input[25], int sum, int length, int index){
    int i;

    if(index == length) {
        output[ind] = sum;
        ind++;
        return;
    }


    subset_sum(output,input,sum+input[index],length,index+1);
    subset_sum(output,input,sum,length,index+1);
  
}


void sorting(int array[25], int length) {
    int temp, i, j;
  

    for(i=0; i<length; i++){
        for(j=i+1; j<length; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

}


