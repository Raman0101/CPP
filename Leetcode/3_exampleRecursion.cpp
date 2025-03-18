// Linear Search using Recursion
#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int k){

    // Base Case
    if(size == 0){
        return false;
    }
    // when i am recursively calling the array it is shifting by 
    // address and new array eill be from the 0 index.
    if(arr[0]==k){
        return true;
    }
    //recursive call
    // Here when in am calling arr+1, it is shifting the array
    // by one index and new array will be from the next index.
    else {
        return linearSearch(arr+1, size-1, k);
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int key = 3;

    bool finalSum = linearSearch(arr, size, key);
    if(finalSum){
        cout<< "Element is Present";
    }

    else{
        cout<< "Element Not Present";
    }
    

    return 0;
}