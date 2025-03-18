#include<bits/stdc++.h>
using namespace std;

int duplicate(vector<int> &nums){
    int slow = nums[0];
    int fast = nums[0];

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    while(slow != fast);

    slow = nums[0];

    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main(){
    vector<int> nums = {1,3,4,2,2};

    int ans = duplicate(nums);

    cout << "The repeating element is: " << ans;

    return 0;
}