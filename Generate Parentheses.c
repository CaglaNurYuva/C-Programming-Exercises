#include <stdio.h>
#define MAX 100

void printing(int position, int n, int open, int close);
void print_parenthesis(int n);

// 16.47 27.06.2022 - Generate Parentheses

int main() {
    int n = 3;
    print_parenthesis(n);
    return 0;
}

void print_parenthesis(int n) {
    if(n > 0) printing(0,n,0,0);
    return;
}


void printing(int position, int n, int open, int close){
    static char str[MAX];

    if(close == n) {
        printf("'%s', ",str);
        return;
    }

    else {
        if(open > close) {
            str[position] = '}';
            printing(position+1,n,open,close+1);
        }

        if(open < n) {
            str[position] = '{';
            printing(position+1,n,open+1,close);
        }

    }

} 







