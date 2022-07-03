#include <stdio.h>
#include <string.h>

// 03.07.2022 11.17 Leetcode - Combination Sum 
// https://leetcode.com/problems/combination-sum/
// https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10&ab_channel=takeUforward

void combination_sum(char input[25], char output[25], int index, int expected_sum);

int main() {
    char input[25] = "2167";
    char output[25] = "";
    combination_sum(input,output,0,7);
    return 0;
}


void combination_sum(char input[25], char output[25], int index, int expected_sum) {
    int i;

    if(index == strlen(input)){
        if(expected_sum == 0) {
            printf("[");
            for(i=0; output[i] != '\0'; i++){
                printf("%c",output[i]);
            }
            printf("]\n");
        }
        
        return;
    }


    else if((input[index]-'0') <= expected_sum){
        output[strlen(output)] = input[index]; 
        output[strlen(output)+1] = '\0';
        combination_sum(input,output,index,expected_sum-(input[index]-'0'));
        output[strlen(output)-1] = '\0'; 
    }

    combination_sum(input,output,index+1,expected_sum);


}



