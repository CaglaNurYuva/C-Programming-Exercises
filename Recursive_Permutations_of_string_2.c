#include <stdio.h>

void permutations(int array[25], int index);
void swap(int x, int y, int array[25]);

// 16.07.2022 10.06
// https://leetcode.com/problems/permutations/
// https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=13&ab_channel=takeUforward


int main() {
    int array[25] = {1,2,3}; //its length must be known
    permutations(array,0);

    return (0);
}

void permutations(int array[25], int index) {
    int y, i;

    if(index == 3) {
        for(i=0; i<3; i++){
            printf("%d ",array[i]);
        }
        printf("\n");
        return;
    }

    for(y=index; y<3; y++){
        swap(index, y, array);
        permutations(array,index+1);
        swap(index,y,array);
    }
}

void swap(int x, int y, int array[25]) {
    int temp;
    temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}


