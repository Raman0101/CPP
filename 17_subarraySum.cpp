#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k){
    int size = nums.size();
    int ans = 0;
    int currSum = 0;

    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            currSum = currSum + nums[j];
            if(currSum == k){
                ans++;
            }
        }
        currSum = 0;
    }
    return ans;

}

int main(){
    vector <int> nums = {9, 4, 20, 3, 10, 5};
    int target = 33;
    int ans = subarraySum(nums, target);

    cout <<"Number of subarrays having sum " << target << " are: " << ans;

    return 0;
}