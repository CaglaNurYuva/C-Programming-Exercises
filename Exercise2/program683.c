#include <stdio.h>
#include <string.h>

/*
* https://www.scaler.com/topics/data-structures/manachers-algorithm/
* https://hackernoon.com/manachers-algorithm-explained-longest-palindromic-substring-22cb27a5e96f
* 22.49 26.06.2022
*/

/* Longest Palindromic Substring Problem */

void longestPalSubstring(char str[]);
void printSubstring(char str[], int left, int right);


int main() {
    char str[30] = "daabddfddbegtd";
    longestPalSubstring(str);
    return 0;
}

void longestPalSubstring(char str[]) {
    int n = strlen(str);
    int maxlength = 1;
    int start=0, i, j, k, flag;

    for(i=0; i<n; i++){
        for(j=i; j<n; j++){
            flag=1;

            for(k=0; k<(j-i+1)/2; k++){
                if(str[i+k] != str[j-k]) {
                    flag=0;
                    break;
                }
            }

            if(flag && (j-i+1)>maxlength) {
                start = i;
                maxlength = j-i+1;
            }
        }
    }

    printf("The Longest Palindromic Substring: ");
    printSubstring(str,start,start+maxlength-1);

}

void printSubstring(char str[], int left, int right) {
    int i;

    for(i=left; i<=right; i++){
        printf("%c",str[i]);
    }
}
