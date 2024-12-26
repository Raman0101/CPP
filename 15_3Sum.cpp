#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE SOLUTION 
vector<vector <int>> triplets(vector<int> &nums){
    int size = nums.size();
    vector<vector <int>> ans;
    //using set instead of unordered set
    // set takes O(logn) but unorederd set takes only O(1)
    // but in undered set we have to write the custom hash
    // for simplicity we are using the set 
    set <vector <int>> s;

    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            for(int k=j+1; k<size; k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    sort (trip.begin(), trip.end());
                    
                    if(s.find(trip) == s.end()){
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    return ans;
} 

// BETTER SOLUTION
vector <vector<int>> triplet2(vector<int> &nums){
    int size = nums.size();
    set <vector <int>> unique_triplets;

    for(int i=0; i<size; i++){
        int tar = -(nums[i]);
        set<int> s;

        for(int j=i+1; j<size; j++){
            int third = tar - nums[j];

            if(s.find(third) != s.end()){
                vector<int> trip = {nums[i], nums[j], third};
                sort(trip.begin(), trip.end());
                unique_triplets.insert(trip);
            }
            s.insert(third);
        }
    }
    vector <vector<int>> ans(unique_triplets.begin(), unique_triplets.end());
    return ans;
}

// OPTIMIZED APPROACH (TWO POINTER APPROACH)
vector <vector<int>> triplets4(vector<int> &nums){
    int n = nums.size();
    vector <vector<int>> ans;

    sort(nums.begin(), nums.end()); // Sorting given array
    
    for(int i=0; i<n; i++){ // tracking first number with this loop
        if(i > 0 && nums[i] == nums[i-1]) continue; // agar ith aur i+1 wala element same hai toh skip kar raha hu

        int j = i+1; // we cant take same element twice so 2nd element will be one next from first
        int k = n-1; // tracking 3rd element from end
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k]; // taking sum of all three elements

            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{ // mtlb sum zero mil gaya
                ans.push_back({nums[i], nums[j], nums[k]}); // store kr liya elements
                j++;
                k--;
                while(j < k && nums[j] == nums[j-1]) j++; // agar j ko increase krke bhi same value hai next element ki toh skip kar raha hu
            }
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

// FOR LOOP
void display1(vector<vector <int>> &nums){

    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums[i].size(); j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector <int>> ans = triplets(nums);
    // display1(ans);
    display2(ans);
    return 0;
}