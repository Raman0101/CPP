#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector <vector<int>> ans;

        for(int i=0; i<n; i++){ // PEHLA Element yahan se le raha hu
            if(i > 0 && nums[i] == nums[i-1]) continue; // agr lagatar do bar same he element aa raha hai toh skip kar raha hu

            for(int j=i+1; j<n; ){ //Dusra element yahan se le raha hu
                
                int p = j+1; //TEESRA Element 
                int q = n-1; // CHOTHA Element 

                while(p < q){ // Two pointer approach se last k 2 elements k alag alag combinations check kr raha hu
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];
                    // lon long isliye use kiya kyunki sum ki value badi bhi ho skti hai
                    if(sum < target){
                        p++;
                    }
                    else if(sum > target){
                        q--;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]}); // ANSWER Store krwa raha hu
                        p++;
                        q--;
                        while (p < q && nums[p] == nums[p-1]) p++; // P ki value alag lagatar same ghhai toh skip kar raha hu
                        while (p < q && nums[q] == nums[q + 1]) q--; // q ki value alag lagatar same ghhai toh skip kar raha hu
                    }
                }
                j++;
                while(j < n && nums[j] == nums[j-1]) j++; // // j ki value alag lagatar same ghhai toh skip kar raha hu
            }
        }
        return ans;
    }

// FOR EACH LOOP
void display2(vector<vector<int>> &nums){
    for(vector<int> row : nums){
        for(int element : row){
            cout << element << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector <int>> ans = fourSum(nums, target);
    display2(ans);
    return 0;
}
