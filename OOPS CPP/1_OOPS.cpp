#include<bits/stdc++.h>
using namespace std;

class Teacher{
public:
    string name;
    string dept;
    string subject;
    double salary;

    void changeDept(string newDept){
        dept = newDept;
    }
};

int main(){
    Teacher t1;
    t1.name = "Raman";
    t1.dept = "IT";
    t1.subject = "oops";
    t1.salary = 20000;
    cout<< t1.name;
    return 0;
}

// long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
//         int n = arr.size();
//         int m = arr.size();
//         sort(arr.begin(), arr.end());
//         sort(brr.begin(), brr.end());

//         long long adjustmentCost = 0;
//         for(int i=0; i<n; i++){
//             adjustmentCost += abs(arr[i] - brr[i]);
//         }
//         if(n > 0){
//             return adjustmentCost ;
//         }
//         else{
//             return adjustmentCost + k;
//         }
        
        
// }
// int main(){
//     vector<int> arr = {-9};
//     vector<int> brr = {9};
//     int k = 29;
//     int ans = minCost(arr, brr, k);

//     cout << ans;
// }