#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *next;

        node(){
            cout<<"Default constructor" << endl;
            this->next == NULL;
        }

        node(int data){
            this->data = data;
            this->next = NULL;
        }
};

int Display(node *head){
    node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    // node a;
    node* head = new node(2);
    node* second = new node(4);
    node* third = new node(5);
    node* fourth = new node(6);
    node* fifth = new node(7);
    node* sixth = new node(8);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;
    sixth -> next = NULL;

    Display(head);
    return 0;
}