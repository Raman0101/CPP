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
    cout<< "LL is: ";
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(node *head){
    node *temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
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

void insertAtTail(node* &head, node* &tail, int data){
    node* temp = head;
    if(head == NULL){
        node* newNode = new node(data);
        head = newNode;
        tail = newNode;
    }

    else{
        node* newNode = new node(data);
        tail -> next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(node* &head, node* &tail, int data, int position){
    //CASE 1: IF INVALID INDEX
    if(position < 1 || position > getLength(head)+1){
        cout<< "Invalid Insertion!!!!! "<< endl  << "Position " << position <<" Doesn't Exists, Please Enter a Valid Position." <<endl;
        return;
    }
    //CASE 2: Insert at 1ST POSITION
    else if(position == 1){
        insertAtHead(head, tail, data);
    }
    //CASE 3: INSERT AT LAST POSITION
    else if(position == getLength(head)+1){
        insertAtTail(head, tail, data);
    }

    else{
        node* prev = NULL;
        node* curr = head;

        node * newNode = new node(data);

        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }

        prev->next = newNode;
        newNode->next = curr;
    }
}

int main(){
    node * head = NULL;
    node * tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtTail(head, tail, 50);
    Display(head);
    
    insertAtPosition(head, tail, 100, 0);
    Display(head);


    // node a;
    // node* head = new node(2);
    // node* second = new node(4);
    // node* third = new node(5);
    // node* fourth = new node(6);
    // node* fifth = new node(7);
    // node* sixth = new node(8);

    // head -> next = second;
    // second -> next = third;
    // third -> next = fourth;
    // fourth -> next = fifth;
    // fifth -> next = sixth;
    // sixth -> next = NULL;
    // node* tail = sixth;

    // Display(head);
    // getLength(head);
    // insertAtHead(head, tail, 100);
    // cout<< "-----AFTER HEAD INSERTION-----" <<endl;
    // Display(head);
    // getLength(head);
    // insertAtTail(head, tail, 200);
    // cout<< "-----AFTER TAIL INSERTION-----"<<endl;
    // Display(head);
    // getLength(head);
    return 0;
}