//leetcode problem: 50

#include<iostream>
using namespace std;

double myPow(double x, int n){

    //corner cases
    if(n==0) return 1.0;
    if(x==0) return 0.0;
    if(x==1) return 1.0;
    if(x==1 && n%2==0) return 1.0;
    if(x==1 && n%2!=0) return -1.0;
    

    long binForm = n;            // storing n in binForm for better understamgong and visualization

    // if power is negative
    if(binForm < 0){
        x = 1/x;
        binForm = -binForm;
    }
    
    double ans = 1;   // declaring answer

    // Binary Exponentiation
    while(binForm > 0){
        if(binForm % 2 == 1){    // to check the bit is 0 or 1
            ans *= x;           // calculating answer when bit is 1
        }
        x *= x;                // to calcutale the square in each step
        binForm /= 2;         // shifting to next bit
    }

    return ans;
}

int main(){
    double x;
    int n;

    // Taking input from the user
    cin >> x;
    cin >> n;

    //passing parameters in the function
    double finalAns = myPow(x, n);
    
    //printing the final answer
    cout<< finalAns;

    return 0;
}