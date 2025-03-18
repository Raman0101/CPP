#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> song;
    vector<string> singer;

    int size;
    cin>> size;

    string s1 = "";
    string s2 = "";

    getline(cin, s1);

    for(int i=0; i<size; i++){
        getline(cin, s1);
        getline(cin, s2);

        song.push_back(s1);
        singer.push_back(s2);

        s1= "";
        s2 = "";
    }

    cout<< endl<< "Playlist is saved successfullly!"<< endl;
    cout<< endl<< "Playing in forward :"<< endl;

    for(int i=0; i<size; i++){
        cout << "Playing: " << song[i] << " - " << singer[i] << endl;
    }

    cout<< endl<< "Playing in backward :"<< endl;

    for(int i=size-1; i>=0; i--){
        cout << "Playing: " << song[i] << " - " << singer[i] << endl;
    }

    return 0;
    

}