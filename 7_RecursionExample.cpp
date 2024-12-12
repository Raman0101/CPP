#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int target){
    // base case
    if(start > end){
        return -1;
    }
    // Processing
    int mid = start + (end - start)/2;
    if(arr[mid] == target){
        return mid;
    }

    //Left Search
    if(target < arr[mid]){
        return binarySearch(arr, start, mid-1, target);
    }

    //Right Search
    else{
        return binarySearch(arr, mid + 1, end, target);
    }
}

int main(){
    int arr[7] = {1,2,3,4,5,6,7};
    int size = 7;
    int start = 0;
    int end = size-1;
    int target = 5;

    int ans = binarySearch(arr, start, end, target);

    if(ans >= 0){
        cout << "Element is found at index: " << ans << endl;
    }
    else{
        cout << "Element not found!!!!!!!" << endl;
    }

    return 0;
}