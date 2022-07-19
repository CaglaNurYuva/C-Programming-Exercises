#include <stdio.h>

// 19.50 19.07.2022 - Palindrome Partitioning
// https://www.youtube.com/watch?v=WBgsABoClE0&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&ab_channel=takeUforward
// https://leetcode.com/problems/palindrome-partitioning/

typedef enum{FALSE,TRUE}bool;
void palindrome_partitioning(char array[25],char output[25], int index);
bool isPalindrome(char array[25], int start, int end);
int ind=0;


int main() {
    char array[25] = "aabb";
    char output[25] = "";
    palindrome_partitioning(array,output,0);
    return (0);
}

void palindrome_partitioning(char array[25],char output[25], int index) {
    int j, k;


    for(j=index; j<4; j++){
        
        if(isPalindrome(array,index,j) == TRUE){
            ind=0;
            for(k=index; k<=j; k++){
                output[ind] = array[k];
                printf("%c",output[ind]);
                ind++;
            }

            printf("\n");
            palindrome_partitioning(array,output,j+1);
            output[ind-1] = '\0';
            // I need to remove the last answer from all the
            // answers therefore output has some replications
            // besides all correct results
            
        }
    }


}

bool isPalindrome(char array[25], int start, int end){
    while(start <= end){
        if(array[start] != array[end]) {
            return FALSE;
        }
        start++;
        end--;
    }
    return TRUE;
}



