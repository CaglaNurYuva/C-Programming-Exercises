#include <stdio.h>
#include <string.h>

//checking palindrome using recursive 13.14 30.06.2022

int checking(int i, char array[25]);

int main() {
    char array[25] = "billib";
    int i=0;
    int r = checking(i, array);
    if(r == 1) printf("true");
    else printf("false");
    return 0;
}

int checking(int i, char array[25]) {
   if(i >= strlen(array)/2) return 1;
   else {
    if(array[i] == array[strlen(array)-i-1]) return checking(i+1,array);
    else return 0;
   }

}



