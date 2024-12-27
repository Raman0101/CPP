#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH
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


// Optimal Solution, PrefixSum Approach
int prefixSum(vector<int> &nums, int k){
    int n = nums.size();
    int ans = 0;

    vector<int> prefixsum(n, 0);
    prefixsum[0] = nums[0];
    for(int i=1; i<n; i++){
        prefixsum[i] = prefixsum[i-1] + nums[i];
        
    }

    unordered_map <int, int> m;
    for(int j=0; j<n; j++){
        if(prefixsum[j] == k){
            ans++;
        }

        int val = prefixsum[j] - k;
        if(m.find(val) != m.end()){
            ans += m[val];
        }

        if(m.find(prefixsum[j]) == m.end()){
            m[prefixsum[j]] = 0;
        }
        m[prefixsum[j]]++;

    }
    return ans;
}

int main(){
    vector <int> nums = {9, 4, 20, 3, 10, 5};
    int target = 33;
    int ans = prefixSum(nums, target);

    cout <<"Number of subarrays having sum " << target << " are: " << ans;

    return 0;
}