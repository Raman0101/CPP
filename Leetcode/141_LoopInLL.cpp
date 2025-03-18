#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode *next;

        ListNode(){
            cout<<"Default constructor" << endl;
            this->next == NULL;
        }

        ListNode(int data){
            this->data = data;
            this->next = NULL;
        }
        
        ~ListNode(){
            cout<<"Destructor called for: " << this->data<< endl;
        }
};

void insertAtHead(ListNode* &head, ListNode* &tail, int data){
    ListNode* temp = head;
    if(head == NULL){
        ListNode* newNode = new ListNode(data);
        head = newNode;
        tail = newNode;
    }

    else{
        ListNode* newNode = new ListNode(data);
        newNode -> next = head;
        head = newNode;
    }
}

bool isLoop(ListNode* &head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL){
        fast = fast->next;

        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(slow == fast){
            return true;
        }
    }
    return false;

}

int main(){
    ListNode* head = NULL;
    ListNode* tail = NULL;

    insertAtHead(head, tail, -4);
    insertAtHead(head, tail, 0);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 3);
    tail->next = head->next;

     if(isLoop(head)){
        cout<< "Cycle Present";
     }
     else{
        cout<< "Cycle not Present";
     }
    return 0;
}