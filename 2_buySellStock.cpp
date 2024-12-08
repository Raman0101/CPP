// Leetcode Problem 121

#include<iostream>
using namespace std;

int maxProfit(int prices[], int size){
    int maxProfit = 0;
    int bestBuy = prices[0]; //assuming that day 1 is the lowest price

    for(int i=0; i<size; i++){
        
        //if the current price is greater then the best buy price
        if(prices[i] > bestBuy){ 
            // calculating the max profit by comparing the maxprofit and the new profit that we can get
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }

        // checking the price of current day is lesser than the previous low or not
        bestBuy = min(bestBuy, prices[i]);
    }
    
    return maxProfit;
}

int main(){
    int prices[6] = {7,1,5,3,6,4};
    int size = 6;

     int profit = maxProfit(prices, size);

     cout<< profit;

     return 0;
}