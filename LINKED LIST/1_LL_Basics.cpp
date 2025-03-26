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
        
        ~node(){
            cout<<"Destructor called for: " << this->data<< endl;
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

int getPosition(node* &head, int value){
    int position = 1;
    node* temp = head;
    while(temp != NULL){
        if(temp->data == value){
        return position;
    }
        position++;
        temp = temp->next;
    }

    return -1;
}

void deleteFromHead(node* &head){
    node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deleteFromTail(node* &head, node* &tail){
    node* prev = head;
        while(prev->next != tail){
            prev = prev->next;
        }
        prev-> next = NULL;
        delete tail;
        tail = prev;
}

void deleteFromPosition(node* head, int position){
    node* prev = NULL;
        node* curr = head;
        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
}

void deleteNodeByPosition(node* &head, node* &tail, int position){

    // CASE: LL IS EMPTY
    if(head == NULL){
        cout<< "LL IS EMPTY, NOTHING TO DELETE."<< endl;
    }

    // CASE: IF HEAD == TAIL i.e ONLY ONE ELEMENT IN LL
    else if(head == tail && position == 1){
        node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }

    // CASE 1: DELETE FROM HEAD
    else if(position == 1){
        deleteFromHead(head);
    }
    
    // CASE 2: DELETE FROM TAIL
    else if(position == getLength(head)){
        deleteFromTail(head, tail);
    }
    
    // CASE 3: DELETE FROM OTHER POSITION
    else{
        deleteFromPosition(head, position);
    }
}

void deleteNodeByValue(node* head, node*tail, int value){

    if(head == NULL){
        cout<< "Linked List is EMPTY!!!!!"<<endl;
    }

    else if( getPosition(head, value) == -1){

        cout<<"THIS VALUE DOESN'T EXIST"<< endl;
    }
    else{
        deleteNodeByPosition(head, tail, getPosition(head, value));
    }
}

node* reverseList(node* head){
    node* temp = head;
    node* prev = NULL;

    while(temp != NULL){
        node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

node* middleNode(node* head){
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL){

        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* mergeTwoLists(node* list1, node* list2) {
    node* dummyNode = new node(-1);
    node* temp = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->data <= list2->data){
            temp->next = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    if(list1 == NULL){
        temp->next = list2;
    }
    else{
        temp->next = list1;
    }

    return dummyNode->next;
}

node* removeNthFromEnd(node* head, int n){
    node* slow = head;
    node* fast = head;

    for(int i=0; i<n; i++){
        fast = fast->next;
    }

    if(fast == NULL){
        return head->next;
    }

    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

    return head;
}

void deleteNode(node* Node){
    // Node mein nextNode ki value store krwa dunga 
    // Node ke next mein nextNode ka next kr dunga
    // nextNode ko delete kr dunga
    Node->data = Node->next->data;
    node* temp = Node->next;
    Node->next = temp->next;
    temp->next = NULL;

    delete temp;
}

node* sort012(node* head) {
        
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    node* dummyZero = new node(-1);
    node* zero = dummyZero;
    node* dummyOne = new node(-1);
    node* one = dummyOne;
    node* dummyTwo = new node(-1);
    node* two = dummyTwo;
    
    node* temp = head;
    
    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        
        temp = temp->next;
    }
    
    zero->next = dummyOne->next;
    one->next = dummyTwo->next;
    
    node* newHead = dummyZero->next;
    
    delete dummyZero;
    delete dummyOne;
    delete dummyTwo;
    
    return newHead;
    
}

bool hasCycle(node *head) {
    // map<node*, bool> table;

    // node* temp = head;

    // while(temp != NULL){
    //     if(table[temp] == false){
    //         table[temp] = true;
    //     }
    //     else{
    //         return true;
    //     }
    //     temp = temp->next;
    // }
    // return false;
    

    //------------approach-2 --------
    node *slow = head;
    node *fast = head;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

node *detectCycle(node *head) {
    node* slow = head;
    node* fast = head;
    
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

bool isPalindrome(node* head) {
    //Midlle Nikalo
    //Reverse 2nd Half
    //compare both halves
    node* middle = middleNode(head);
    node* head2 = middle->next;
    middle->next = NULL;

    head2 = reverseList(head2);

    node* temp1 = head;
    node* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;

}

node *getIntersectionNode(node *headA, node *headB) {
    node *d1 = headA;
    node *d2 = headB;

    while(d1 != d2){
        d1 = d1 == NULL? headB : d1->next;
        d2 = d2 == NULL? headA : d2->next;
    }

    return d1;
}

node *flattenLL(node *root) {
    if(root == NULL || root->next == NULL){
        return root;
    }
    
    node* mergedHead = flattenLL(root->next);
    
    return mergeTwoLists(root, mergedHead);
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
    
    // insertAtPosition(head, tail, 100, 0);
    // Display(head);

    // deleteNodeByValue(head, tail, 10);
    // Display(head);

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