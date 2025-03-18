#include <bits/stdc++.h>
using namespace std;

vector<int> missingRepeatingElement(vector<vector<int>>& grid){

    int n = grid.size();
    int missingElement, repeatingElement;
    int expectedSum = 0;
    int actualSum = 0;

    unordered_set <int> s;
    vector<int> ans;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            actualSum += grid[i][j];

            if(s.find(grid[i][j]) != s.end()){
                repeatingElement = grid[i][j];
                ans.push_back(repeatingElement);
            }
            s.insert(grid[i][j]);
        }
    }

    expectedSum = (n*n * (n*n +1))/2;
    missingElement = expectedSum + repeatingElement - actualSum;
    ans.push_back(missingElement);

    return ans;
}

int main(){
    vector<vector<int>> grid = { {9,1,7}, {8,9,2}, {3,4,6}};

    vector<int> ans = missingRepeatingElement(grid);

    int n = ans.size();
    cout << "Repeating and Missing Elements are: "; 
    for(int i=0; i<n; i++){
        cout<< ans[i] << " ";
    }
    return 0;
}