#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertInBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertInBST(root->right, data);
    }
    else{
        root->left = insertInBST(root->left, data);
    }

    return root;
}

void createBST(Node* &root){
    cout << "enter the data: ";
    int data;
    cin >> data;

    while(data != -1){
        root = insertInBST(root, data);
        cout<<"enter the data: " << endl;
        cin >> data;
    }
}

void levelOrderTraversal(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i=0; i<size; i++){
            Node* front = q.front();
            q.pop();

            cout<< front->data << " ";

            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }
        cout << endl;
    }

}

bool isElementPresent(Node* root, int target){
    if(root == NULL){
        return false;
    }

    if(root->data == target){
        return true;
    }

    bool rightAns = false;
    bool leftAns = false;

    if(target > root->data){
        rightAns = isElementPresent(root->right, target);
    }
    else{
        leftAns = isElementPresent(root->left, target);
    }

    return leftAns || rightAns;
}

Node* maxInBST(Node* root){
    if(root == NULL){
        return NULL;
    }

    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* minInBST(Node* root){
    if(root == NULL){
        return NULL;
    }

    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* deleteNodeFromBST(Node* root, int target){
    if(root == NULL){
        cout << "element doesn't exists!!!" << endl;
        return NULL;
    }

    if(root->data == target){
        //Case 1: Leaf Node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // Case 2: ONLY Left subtree exist 
        else if(root->left != NULL && root->right == NULL){
            Node* childSubTree = root->left;
            delete root;
            return childSubTree;
        }
        //Case 3: ONLY Right subtree exists
        else if(root->left == NULL && root->right != NULL){
            Node* childSubTree = root->right;
            delete root;
            return childSubTree;
        }
        //Case 4: Both Child EXISTS
        else{
            // Step 1: find max in left sub tree
            Node* maxi = maxInBST(root->left);

            // Step 2: replace with root(target)
            root->data = maxi->data;

            // Step 3: delete maxi from its pos
            root->left = deleteNodeFromBST(root->left, maxi->data);
            return root;
        }
    }

    if(target < root->data){
        root->left = deleteNodeFromBST(root->left, target);
    }
    else{
        root->right = deleteNodeFromBST(root->right, target);
    }

    return root;
}

void convertBSTtoDLL(Node* root, Node* &head){

    if(root == NULL){
        return;
    }

    convertBSTtoDLL(root->right, head);

    root->right = head;
    if(head != NULL)
        head->left = root;
    head = root;

    convertBSTtoDLL(root->left, head);
}

int main(){
    Node* root = NULL;
    createBST(root);

    cout <<endl << "level order traversal: "<<endl;
    levelOrderTraversal(root);


    return 0;
}