# include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(int nums[], int size){
    vector<int> ans(size, 1);

    // prefix
    for(int i=1; i<size; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }

    //Suffix
    int suffix = 1;
    for(int i=size-2; i>=0; i--){
        suffix *= nums[i+1];
        ans[i] *= suffix;
    }
    return ans;
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;

    vector<int> finalAns = productExceptSelf(arr, size);
    int n = finalAns.size();
    for(int i=0; i<n; i++){
        cout<< finalAns[i] <<" ";
    }
    return 0;
}