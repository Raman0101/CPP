#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    int size = nums.size();
    vector<int> ans;
    unordered_map<int, int> m;

    for(int i=0; i<size; i++){
        int first = nums[i];
        int sec = target - first;

        if(m.find(sec) != m.end()){
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;
        }
        m[first] = i;
    }

    return ans;

}

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);
    int n = ans.size();

    cout << "Indices at which the elements are found are: ";
    for(int i=0; i<n; i++){
        cout<< ans[i] << " ";
    }

    return 0;
}