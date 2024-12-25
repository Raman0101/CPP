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