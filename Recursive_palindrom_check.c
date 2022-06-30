#include <stdio.h>
#include <string.h>

//checking palindrome using recursive 13.01 30.06.2022

int checking(char *a, char *b);

int main() {
    char array[25] = "madam";
    printf("%s",((checking(&array[0],&array[strlen(array)-1])) == 1) ? "true" : "false");
    return 0;
}

int checking(char *a, char *b) {
    if(a >= b) {
        return 1;
    }

    else if(*a == *b){
        checking(a+1, b-1);
    }

    else if(*a != *b) return 0;
}



