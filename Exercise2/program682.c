#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestPalindrom(char *str);
void printing(char *str, int low, int high);

int main() {
    char *string = (char*)calloc(30,sizeof(char));
  
    printf("Enter string: ");
    scanf("%s",string);

    printf("\nLongest palindrom's length = %d\n",longestPalindrom(string));
    free(string);
 
    return 0;
}

int longestPalindrom(char *str) {
    int length = strlen(str);
    int maxLength = 1, start=0, low, high, i, sub_palindrom_length;

    if(length < 2) return length;
    for(i=0; i<length; i++){
        low = i-1;
        high = i+1;

        while(high<length && str[high] == str[i]) high++;
        while(low>=0 && str[low] == str[i]) low--;
        while(low >= 0 && high<length && str[low] == str[high]) {
            low--;
            high++;
        }

        sub_palindrom_length = high-low-1; 
        if(maxLength < sub_palindrom_length){
            maxLength = sub_palindrom_length;
            start = low+1;
        }

    }

    printf("Longest subpalindrome = ");
    printing(str,start,start+maxLength-1);
    return maxLength;

}


void printing(char *str, int low, int high) {
    int i;
    for(i=low; i<=high; ++i){
        printf("%c",str[i]);
    }
}



