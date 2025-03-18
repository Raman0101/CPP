#include<iostream>
#include<limits.h>
using namespace std;

int maximizeTheCuts(int N, int x, int y, int z){

    //Base Case
    if(N == 0){
        return 0;
    }
    if(N < 0){
        return INT_MIN;
    }

    // Consider x as 1st cut
    int option1 = 1 + maximizeTheCuts(N-x, x, y, z);

    // consider y 1st cut
    int option2 = 1 + maximizeTheCuts(N-y, x, y, z);

    // consider z as 1st option
    int option3 = 1 + maximizeTheCuts(N-z, x, y, z);

    int finalAns = max(option1, max(option2, option3));

    return finalAns;
}

int main(){
    int N = 5;
    int x = 2;
    int y = 1;
    int z = 1;
    int ans = maximizeTheCuts(N, x, y, z);
    cout << "Maximum Cuts are: " << ans;

    return 0;
}