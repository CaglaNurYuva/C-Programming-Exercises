#include <stdio.h>
#include <limits.h>

// https://leetcode.com/problems/next-permutation/
// Next Permutation - 00.13 02.08.2022

void next_permutation(int arr[], int size);
void swapping(int arr[], int indx, int indy);
int find_biggest_index(int arr[], int size);

int main() {
    int arr[] = {1,1,5};
    next_permutation(arr,3);
    return (0);
}

int find_biggest_index(int arr[], int size){
    int biggest = INT_MIN, i,index;
    for(i=0; i<size; i++){
        if(arr[i] > biggest){
            biggest = arr[i];
            index = i;
        }
    }

    return index;
}

void swapping(int arr[], int indx, int indy) {
   int temp;
   temp = arr[indx];
   arr[indx] = arr[indy];
   arr[indy] = temp;
}

void next_permutation(int arr[], int size) {
    int i,biggest_index;

    if(size == 1) {
        printf("%d",arr[0]);
        return;
    }

    else if(size == 2){
        swapping(arr,0,1);
        printf("%d %d",arr[0], arr[1]);
        return;
    }

    biggest_index = find_biggest_index(arr,size);

   
    if(biggest_index == 0){
        swapping(arr,0,size-1);

        printf("[");
        for(i=0; i<size; i++){
            printf("%d ",arr[i]);
        }
        printf("\b]\n");

        return;
    }

    
    swapping(arr,biggest_index-1,biggest_index);
    printf("[");
    for(i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\b]\n");




}


