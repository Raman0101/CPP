#include<iostream>
#include<vector>
using namespace std;

int houseRobber(int amount[], int size, int index){
    //base case 
    if(index >= size){
        return 0;
    }

    //case 1
    int option1 = amount[index] + houseRobber(amount, size, index+2);

    //case 2
    int option2 = 0 + houseRobber(amount, size, index+1);

    int finalAns = max(option1, option2);
    return finalAns;
}

int main(){
    int amount[] = {1,2,3,1};
    int index = 0;
    int size = 4;

    int ans = houseRobber(amount, size, index);

    cout << "Maximum Profit : " << ans;

    return 0;
}