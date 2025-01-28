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
    cout<< "LL is: " << endl;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
}

void getLength(node *head){
    node *temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    cout<< endl << "Length of LL is: " << length<< endl;
}

void insertAtHead(node* &head, node* &tail, int data){
    node* temp = head;
    if(head == NULL){
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
    }

    else{
        node* newNode = new node(data);
        newNode -> next = head;
        head = newNode;
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
    node* tail = sixth;

    Display(head);
    getLength(head);
    insertAtHead(head, tail, 100);
    Display(head);
    getLength(head);
    return 0;
}