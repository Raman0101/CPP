#include<iostream>
using namespace std;

void findSubsequence(string str, string output, int index){

    //base case
    if(index >= str.length()){
        cout << output << endl;
        return;
    }

    // include
    output.push_back(str[index]);
    findSubsequence(str, output, index+1);

    //exclude
    output.pop_back();
    findSubsequence(str, output, index+1);
}

int main(){
    string str = "abc";
    string output = " ";
    int index = 0;
    findSubsequence( str, output, index);

    return 0;
}