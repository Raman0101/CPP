#include<iostream>
using namespace std;

int ContainerWithMostWater(int heights[], int size){
    int ans = 0;
    int currArea = 0;
    int start = 0;
    int end = size-1;
    int width = size-1;

    while(start<end){
        if(heights[start] < heights[end]){
            currArea = heights[start] * width;
            start++;
        }
        else{
            currArea = heights[end] * width;
            end--;
        }

        ans = max(ans, currArea);
        width--;
    }
    return ans;
}

int main(){
    int arr[9] = {1,8,6,2,5,4,8,3,7};
    int size = 9;

    int finalAns = ContainerWithMostWater(arr, size);
    cout<< "The max area of water the container can contain is " << finalAns;

    return 0;
}