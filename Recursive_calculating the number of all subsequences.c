#include <stdio.h>
#include <string.h>

/* Calculating the number of all subsequences - 14.45 01.07.2022 */


int print_subsequence(int index, char output[25], char input[25]);

int main() {
    char input[25] = "1234";
    char output[25] = "";
    printf("%d",print_subsequence(0,output, input));
    return 0;
}


int print_subsequence(int index, char output[25], char input[25]) {
    int i, sum=0, left=0, right=0;

    if(index >= strlen(input)) {
        for(i=0; output[i] != '\0'; i++){
            sum += output[i] - '0';
        }
        if(sum == 4)return 1;
        else return 0;
        
    }

    output[strlen(output)] = input[index];
    output[strlen(output)+1] = '\0';

    left = print_subsequence(index+1,output,input);
    output[strlen(output)-1] = '\0';
    right = print_subsequence(index+1,output,input);

    return left+right;

}


