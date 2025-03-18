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

ListNode* detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL){
            fast = fast->next;

            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            if(slow == fast){
                break;
            }
        }
        if(fast == NULL){
            return NULL;
        }

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
}

void removeCycle(ListNode* &head){
    ListNode* cycle = detectCycle(head);
    if(cycle == NULL){
        cout<<"-----Deleting Cycle-----" << endl << " OOPS!!!! No Cycle Present!!!";
    }

    else{
        ListNode* temp = head;

        while(temp->next != cycle){
            temp = temp->next;
        }
        temp->next = NULL;
        cout<< "-----Deleting Cycle-----" << endl << "YEYYYYY!!!!! Cycle Removed Successfully.";
    }
}

int main(){
    ListNode* head = NULL;
    ListNode* tail = NULL;

    insertAtHead(head, tail, -4);
    insertAtHead(head, tail, 0);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 3);
    tail->next = head->next;

    ListNode* ans = detectCycle(head);
    if(ans == NULL){
        cout<< "NO CYCLE PRESENT"<< endl;
    }
    else{
        cout<< "Cycle is Present at: " << ans->data << endl;
    }

    removeCycle(head);

    return 0;
}