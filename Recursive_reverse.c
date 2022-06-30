#include <stdio.h>

//reversing using recursion 12.37 30.06.2022

void swap(int *a, int *b);
void printing(int array[5]);
void reversing(int *f, int *g);

int main() {
    int array[5] = {1,2,3,4,5};
    printing(array);
    reversing(&array[0],&array[4]);
    printing(array);
    return 0;
}

void reversing(int *f, int *g) {
    if(f >= g) return;
    else {
        swap(f,g);
        reversing(f+1,g-1);
    }
}

void swap(int *a, int *b) {
    int x;

    x = *a;
    *a = *b;
    *b = x;
}

void printing(int array[5]) {
    int i=0;
    while(i<5){
        printf("%d ",array[i++]);
    }
    printf("\n");
}


