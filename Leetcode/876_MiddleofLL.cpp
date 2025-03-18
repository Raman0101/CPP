#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

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

int Display(node *head){
    node * temp = head;
    cout<< "LL is: ";
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<<endl;
}

 void middleNode(node* head) {
        node* slow = head;
        node* fast = head;

        while(fast != NULL && fast->next != NULL){

            fast = fast->next->next;
            slow = slow->next;
        }
        
        cout<< endl << "Middle of LL is: "<< slow->data;
    }

int main(){
    node* head = NULL;
    node* tail = NULL;

    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    Display(head);
    middleNode(head);
    return 0;
}