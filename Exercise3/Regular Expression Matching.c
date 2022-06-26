#include <stdio.h>

//23.42 26.06.2022
// Regular Expression Matching - Leetcode

int main() {
    char first[25];
    char second[25];
    char encrypted[25];
    int i;

    printf("Enter first: ");
    scanf("%s",first);

    printf("Enter second: ");
    scanf("%s",second);

    printf("first: %s\n",first);
    printf("second: %s\n",second);

    for(i=0; first[i] != '\0'; i++){

        if(second[i] == '\0') {
            printf("false");
                return 0;
        }


        if(first[i] == second[i]){
            continue;
        }

        else if(second[i] == '.'){
            continue;
        }

        else if(second[i] == '*'){
           if(i != 0) second[i] = second[i-1];
           else second[i] = '0';

           if(first[i] == second[i] || second[i] == '.'){
                continue;
            } 

            else {
                printf("false");
                return 0;
            }

        }

        else if(first[i] != second[i]) {
            printf("false");
                return 0;
        }
    }

    printf("true");
    return 0;

}
