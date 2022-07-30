#include <stdio.h>
#include <stdlib.h>

// Median of Two Sorted Arrays - 17.52 30.07.2022
// https://leetcode.com/problems/median-of-two-sorted-arrays/

void bubble_sorting(int *merged_array, int size);

int main() {
    int *nums1, *nums2, *merged_array;
    int size1, size2, i, j=0;
    float result;

    printf("Enter size1 = ");
    scanf("%d",&size1);
    printf("Enter size2 = ");
    scanf("%d",&size2);

    nums1 = (int*)malloc(sizeof(int)*size1);
    nums2 = (int*)malloc(sizeof(int)*size2);
    merged_array = (int*)malloc(sizeof(int)*(size1+size2));

    printf("Enter first array's elements: ");
    for(i=0; i<size1; i++, j++){
        scanf("%d",&nums1[i]);
        merged_array[j] = nums1[i];
    }

    printf("Enter second array's elements: ");
    for(i=0; i<size2; i++,j++){
        scanf("%d",&nums2[i]);
        merged_array[j] = nums2[i];
    }

    bubble_sorting(merged_array,size1+size2);

    printf("Merged array = [");
    for(i=0; i<(size2+size1); i++,j++){
        printf("%d,",merged_array[i]);
    }
    printf("\b]");
    if((size1+size2)%2 == 0){
        result = (merged_array[(size1+size2)/2 - 1] + merged_array[(size1+size2)/2])/(float)2;
        printf(" and median is (%d + %d) / %d = %.2f.\n",merged_array[(size1+size2)/2 - 1], merged_array[(size1+size2)/2], 2,result);
    }

    else {
        result = merged_array[(size1+size2)/2];
        printf(" and median is %.2f.\n",result);
    }

    return (0);
}

void bubble_sorting(int *merged_array, int size) {
    int i,j, temp;

    for(i=0; i<size; i++){
        for(j=i; j<size; j++){
            if(merged_array[i] > merged_array[j]){
                temp = merged_array[i];
                merged_array[i] = merged_array[j];
                merged_array[j] = temp;
            }
        }
    }

    
}



