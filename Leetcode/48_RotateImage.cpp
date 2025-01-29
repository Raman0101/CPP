#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int> &row){
    int n = row.size();

    int start = 0;
    int end = n-1;

    while(start < end){
        swap(row[start], row[end]);
        start++;
        end--;
    }
}

void RotateMatrix(vector<vector<int>> &matrix){
    int n = matrix.size();

    //finding the TRANSPOSE of the matrix
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // ROTATING EACH ROW TO GET THE 90 DEGREE ROTATION
    for(int i=0; i<n; i++){
        rotate(matrix[i]);
    }
}

int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    RotateMatrix(matrix);
    
    return 0;
}