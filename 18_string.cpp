#include<bits/stdc++.h>
using namespace std;

int main(){
    //Strings 
    // Before we jump into string we should understand 
    // the concept of character arrays
    char str[] = {'a', 'b', 'c', '\0'};
    // here '\0' is a null character used to terminate string
    // NULL Character also takes 1B of memory
    // String is not valid without NULL Character
    
    cout << str << endl; 
    // we can simply take the string as output with the base address

    int length = strlen(str);
    // we can calculate the length of string using the 'strlen()' function
    // the Null character is igmored while calculating the length 
    cout << " The length of " << str << " is " << length <<endl;

    char str2[] = "hello";
    // we can directly assign the string instead of individual character
    // these are string literals

    cout << str[2] << endl;
    // we can access the index just like the integer arrays
    // stored in contiguous memory locations

    // input in strings
    char str3[100];
    cin>> str3;
    // we can take the input like this if it is a word

    
}