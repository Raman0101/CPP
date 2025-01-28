#include<bits/stdc++.h>
using namespace std;

void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans){

    //BASE CASE
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=index; i<nums.size(); i++){
        swap(nums[index], nums[i]);
        recurPermute(index+1, nums, ans);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> Permute(vector<int> &nums){
    vector<vector<int>> ans;
    recurPermute(0, nums, ans);
    return ans;
}

void Display(vector<vector<int>> &ans){
    int m = ans.size();
    int n = ans[0].size();

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<< ans[i][j] << " ";
        }
        cout<< endl;
    }
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = Permute(nums);
    Display(ans);
    return 0;
}