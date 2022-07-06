#include <stdio.h>

// https://leetcode.com/problems/subsets-ii/
// https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=13&ab_channel=takeUforward
// 11.37 06.07.2022 - Subset Sum II


void subset_sum_II(int input[25], int output[25], int index);
void sorting(int array[25], int length);
int ind=0;

int main() {
    int input[25] = {1,2,2,2,3,3}; //its length must be asked to user
    int output[25];
    sorting(input,6);
    subset_sum_II(input,output,0);
    return (0);
}


void subset_sum_II(int input[25], int output[25], int index){
    int j,i;

    printf("[");
    for(i=0; i<ind && output[i] != -9999; i++){
        printf("%d ",output[i]);
    }
    printf("]\n");
        
 
    for(j=index; j<6; j++){
        if(j != index && input[j] == input[j-1])continue;
      
     
        output[ind] = input[j];
        ind++;
        subset_sum_II(input,output,j+1);
        
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







