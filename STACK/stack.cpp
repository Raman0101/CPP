#include<bits/stdc++.h>
using namespace std;


//Stack using array
class Stack{
  
    public:
        int *arr;
        int size;
        int top;

        Stack(int size){
            arr = new int[size];
            this->size = size;
            this->top = -1;
        }

        void push(int data){
            if(top == size - 1){
                cout<< "OverFlow condition" << endl;
            }
            else{
                top++;
                arr[top] = data;
            }
        }

        int getsize(){
            return top + 1;
        }

        void pop(){
            if(top == -1){
                cout<< "Stack is empty" << endl;
            }
            else{
                top--;
            }
        }

        bool empty(){
            if(top == -1) return true;

            else return false;
        }

        int gettop(){
            if(top == -1){
                cout<< "Stack is Empty." << endl;
            }
            else{
               return arr[top];
            }
        }

        void print(){
            if(top == -1){
                cout<< "Stack is empty." << endl;
            }
            else{
                for(int i=0; i<getsize(); i++){
                    cout<< arr[i] <<"->";
                }
                cout<<endl;
            }
        }

};

int middle(Stack &st, int pos){
    if(pos == 1){
        return st.gettop();
    }
    
    pos--;
    int temp = st.gettop();
    st.pop();

    //recursive call
     int ans = middle(st, pos);

    //backtrack
    st.push(temp);

    return ans;
}

int getPosition(int size){
    int pos = -1;
    if(size & 1 ){ // check odd
        pos = size/2 + 1;
    }
    else{
        //even
        pos = size/2;
    }
    return pos;
}

int getMiddleElement(Stack &st, int size){
    if(st.empty()){
        return -1;
    }

    else{
        //Stack not empty.
        int ans = middle(st, getPosition(size));
        return ans;
    }
}

int main(){
    Stack st(5);

    st.push(20);
    st.push(30);
    st.push(80);
    st.push(70);
    st.push(60);
    st.print();

    int size = st.getsize();

    int ans = getMiddleElement(st, size);
    if(ans == -1){
        cout<< "Stack is empty"<<endl;
    }
    else{
        cout<< "Middle Element is: " << ans << endl;
    }
    return 0;
}




bool hasSpecialSubstring(string s, int k) {
    char ch = s[0];
    int count = 1;
    if((s.length() == 1 && k == 1) || (k == 1 && s.length()>0)){
        return true;
    }
    for(int i=1; i<s.length(); i++){
        if(s[i] == ch){
            count ++;
            
            if(count == k  ){
               
                    return true;
            }
            if(count > k){
                return false;
            }
        }
        else{
            ch = s[i];
            count = 1;
        }
        
    }
    return false;
}
}