#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* prev;
        node* next;

        node(){
            // DEFAULT CONSTRUCTOR
            this->prev = NULL;
            this->next = NULL;
        }

        node(int data){
            // Constructor
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }

        // DESTRUCTOR
        ~node(){
            cout<< "Destructor is called for: " << this->data << endl;
        }
};

void insertAtHead(node* &head, node* &tail, int data){
    if(head == NULL){
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        node* newNode = new node(data);
        node* temp = head;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(node* &head, node* &tail, int data){
    // node* temp = tail;
    if(head == NULL){
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        node* newNode = new node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void print(node* &head){
    node* temp = head;
    cout<< "DLL is: ";

    while(temp != NULL){
        cout<< temp->data << "->";
        temp = temp->next;
    }
}


int main(){
    node* head = NULL;
    node* tail = NULL;
    
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtTail(head, tail, 5);
    print(head);
    cout<< endl;

    return 0;
}