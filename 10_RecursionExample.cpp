#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int coinChange(vector<int> coins, int amount){

    // Base Case
    if(amount == 0){
        return 0;
    }
    

    int mini = INT_MAX;
    int ans = INT_MAX;

    for(int i=0; i<coins.size(); i++){
        int currCoin = coins[i];

        if(currCoin <= amount){
            int recAns = coinChange(coins, amount-currCoin);
            if(recAns != INT_MAX){
                ans = 1 + recAns;
            }
        }

        mini = min(ans, mini);

    }

    return mini;
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;

    int FinalAns = coinChange(coins, amount);

    if(FinalAns == INT_MAX){
        cout << "Invalid Answer!!!!!!!" << endl;
    }
    else{
        cout << "Minimum Coins: " <<  FinalAns << endl;
    }
    
    return 0;
    
}