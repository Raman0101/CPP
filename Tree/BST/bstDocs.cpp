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

int main(){
    Node* root = NULL;
    createBST(root);

    cout <<endl << "level order traversal: "<<endl;
    levelOrderTraversal(root);


    return 0;
}