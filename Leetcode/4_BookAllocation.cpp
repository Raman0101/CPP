#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllocation){
    int student = 1;
    int page = 0;

    for(int i=0; i<n; i++){
        if(arr[i] > maxAllocation){
            return false;
        }
        if(page + arr[i] <= maxAllocation){
            page += arr[i];
        }
        else{
            student++;
            page = arr[i];
        }
    }
   
    return student > m ? false : true;
}

int allocateBooks(vector<int> &arr, int n, int m){ //O(nlogN)
    if(m > n){
        return -1;
    }

    int sum = 0;
    for(int i=0; i<n; i++){  // O(n)
        sum += arr[i];
    }

    //Range of possible answers
    int start = 0;
    int end = sum; // Maximum Pages i.e sum of all pages
    int ans = -1;

    while(start <= end){ // O(logN)
        int mid = start + (end - start)/2;

        if(isValid(arr, n, m, mid)){ // O(n)
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {2,1,3,4};
    int n=4;
    int m=2;

    int ans = allocateBooks(arr, n, m);

    cout << "Minimun Maximum Books that can be allocated to a student is " << ans << endl;

    return 0;
}
