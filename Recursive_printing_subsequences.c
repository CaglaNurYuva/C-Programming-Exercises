#include <stdio.h>
#include <string.h>

/* Printing Subsequences - 11.49 01.07.2022 */

void print_subsequence(int index, char output[25], char input[25]);

int main() {
    char input[25] = "abc";
    char output[25] = "";
    print_subsequence(0,output, input);
    return 0;
}


void print_subsequence(int index, char output[25], char input[25]) {
    int i;

    if(index >= (strlen(input))) {
        printf("[");
        for(i=0; output[i] != '\0'; i++){
            printf("%c",output[i]);
        }
        printf("]");
        printf("\n");
        return;
    }

    output[strlen(output)] = input[index];
    output[strlen(output)+1] = '\0';
    print_subsequence(index+1,output,input);
    output[strlen(output)-1] = '\0';
    print_subsequence(index+1,output,input);


}


