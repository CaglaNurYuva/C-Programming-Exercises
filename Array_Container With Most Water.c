#include <stdio.h>

// Container With Most Water - 12.12 28.07.2022
// https://leetcode.com/problems/container-with-most-water/
// https://www.youtube.com/watch?v=2DjZ8AHcofE&list=PL1w8k37X_6L86f3PUUVFoGYXvZiZHde1S&index=2&ab_channel=KnowledgeCenter

int max_Area(int height[25]);

int main() {
    int height[25] = {1,8,6,2,5,4,8,3,7};

    printf("Max containing limit: %d",max_Area(height));
    return (0);
}

int max_Area(int height[25]) {
    int i=0, j=8, width;
    int hmin=0, area, biggest_area=0;

    while(i<j){
        width = j-i;
        
        if(height[i] < height[j]){
            hmin = height[i];
            i++;
        }

        else {
            hmin = height[j];
            j--;
        }
        area = width*hmin;
        if(biggest_area<area){
            biggest_area = area;
        }
    }

    return biggest_area;
}

