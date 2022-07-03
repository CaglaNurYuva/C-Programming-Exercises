#include <stdio.h>

void sorting(int array[25], int length);
void combination_sum_II(int input[25], int output[25], int index, int expected_sum, int length);
int ind=0;

// 18.31 03.07.2022 - Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/
// https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=11&ab_channel=takeUforward

int main() {
    int array[25] = {1,1,1,2,2};
    int output[25] = {-9999,-9999,-9999,-9999,-9999};
    sorting(array,5);
    combination_sum_II(array,output,0,4,5);
    return (0);
}


void combination_sum_II(int input[25], int output[25], int index, int expected_sum, int length){
    int i;
   
    if(expected_sum == 0){
        
        for(i=0; i<length && output[i] != -9999; i++){
            printf("%d ",output[i]);
        }
        printf("\n");
        return;
    }

    for(i=index; i<length; i++){
        if(i>index && input[i] == input[i-1]) continue;
        if(input[i] > expected_sum) break;
        

        output[ind] = input[i];
        ind++;
        combination_sum_II(input,output,i+1,expected_sum-output[ind-1],5);
        output[ind-1] = -9999;
        ind--;
    }



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




