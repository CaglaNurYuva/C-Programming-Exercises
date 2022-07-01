#include <stdio.h>
#include <string.h>

/* Printing just one subsequence fulfilling a specific condition (sum condition) - 14.17 01.07.2022 */

typedef enum {FALSE, TRUE}bool;

bool print_subsequence(int index, char output[25], char input[25]);

int main() {
    char input[25] = "1234";
    char output[25] = "";
    print_subsequence(0,output, input);
    return 0;
}


bool print_subsequence(int index, char output[25], char input[25]) {
    int i, sum=0;

    if(index >= strlen(input)) {
        for(i=0; output[i] != 0; i++){
            sum += output[i] - '0';
        }

        if(sum == 4) {
            printf("[");
            for(i=0; output[i] != '\0'; i++){
                printf("%c",output[i]);
            }
            printf("]");
            printf("\n");
            return TRUE;
        }
       
        else return FALSE;
    }

    output[strlen(output)] = input[index];
    output[strlen(output)+1] = '\0';

    //avoiding future recursive calls
    if(print_subsequence(index+1,output,input) == TRUE) {
        return TRUE;
    }

    output[strlen(output)-1] = '\0';

    //avoiding future recursive calls
    if(print_subsequence(index+1,output,input) == TRUE) {
        return TRUE;
    }

    return FALSE;

}


