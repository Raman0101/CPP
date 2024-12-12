#include<iostream>
using namespace std;

bool isSorted(int arr[], int size, int index){
    // Base Case, index array ke bahar chala gaya
    if(index >= size){
        return true;
    }

    // processing
    if(arr[index] > arr[index]-1){
        //true hai mtlb sorted hai bhai
        return isSorted(arr, size, index + 1);
    }
    else{
        // mtlb sorted nahi hai
        return false;
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
    int size = 5;

    int index = 1;

    bool checkSorted = isSorted(arr, size, index);

    if(checkSorted){
        cout << "Array is Sorted" << endl;
    }
    else{
        cout << "Array is not Sorted" << endl;
    }

    return 0;
}