#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e){

    int mid = (s + e)/2;
    //calculating the lengths of two arrays that has to be merge
    int lenLeft = mid - s + 1;
    int lenRight = e - mid;

    //creating two dynamic arrays
    int *leftArr = new int[lenLeft];
    int *rightArr = new int[lenRight];

    //copying values of left and right arrays in dynamic arrays
    int k = s;
    
    for(int i=0; i< lenLeft; i++){
        leftArr[i] = arr[k];
        k++;
    }

    k = mid + 1;

    for(int i=0; i<lenRight; i++){
        rightArr[i] = arr[k];
        k++;
    }

    //sorting and merging both array in original array

    int leftIndex = 0;
    int rightIndex = 0;
    int arrIndex = s;

    while(leftIndex < lenLeft && rightIndex < lenRight){
        
        if(leftArr[leftIndex] < rightArr[rightIndex]){
            arr[arrIndex] = leftArr[leftIndex];
            arrIndex++;
            leftIndex++;
        }
        else{
            arr[arrIndex] = rightArr[rightIndex];
            arrIndex++;
            rightIndex++;
        }
    }

    while(leftIndex < lenLeft){
        arr[arrIndex] = leftArr[leftIndex];
        leftIndex++;
        arrIndex++;
    }

    while(rightIndex < lenRight){
        arr[arrIndex] = rightArr[rightIndex];
        rightIndex++;
        arrIndex++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort( int arr[], int s, int e){
    
    //Base Case
    if(s > e){
        return;
    }
    if(s == e){
        return;
    }

    //divide
    int mid = (s + e)/2;

    //left call
    mergeSort(arr, s, mid);

    // right call
    mergeSort(arr, mid+1, e);

    //Conquer
    merge(arr, s, e);
}

int main(){
    int arr[] = {15, 70, 3, 76, 55, 8};
    int size = 6;
    int start = 0;
    int end = size - 1;

    cout<< " Before Merge Sort:"<< endl;
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }

    mergeSort(arr, start, end);

    cout<<endl << "After Merge Sort: "<< endl;

    for(int i=0; i<size; i++){
        cout<< arr[i] << " " ;
    }

    return 0;
}