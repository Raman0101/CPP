#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;

    node (int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int searchInOrder(int inOrder[], int element, int size){
    for(int i=0; i<size; i++){
        if(inOrder[i] == element){
            return i;
        }
    }
    return -1;
}

node* createTreebyPOIO(int preOrder[], int inOrder[], int size, int inStart, int inEnd, int &preIndex){
    //Base Case
    if(preIndex >= size || inStart > inEnd){
        return NULL;
    }
    
    //create root
    int element = preOrder[preIndex];
    preIndex++;
    node* root = new node(element);

    //search position of element in inOrder
    int position = searchInOrder(inOrder, element, size);

    //left SubTree ki call
    root->left = createTreebyPOIO(preOrder, inOrder,size, inStart, position-1, preIndex);

    //right SubTree ki Call
    root->right = createTreebyPOIO(preOrder, inOrder,size, position+1, inEnd, preIndex);

    return root;
}

node* createTree(){
    cout<< "Enter the value for Node: "<< endl;
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    node* root = new node(data);

    cout<< " left of Node: " << root->data <<endl;
    root->left = createTree();

    cout << "right of node: " << root->data << endl;
    root->right = createTree();

    return root;
}

void levelOrderTraversal(node* root) {
    if (root == NULL) return;
    
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size(); // Number of nodes in the current level

        // Print all nodes of the current level
        for (int i = 0; i < size; i++) {
            node* front = q.front();
            q.pop();
            cout << front->data << " ";

            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
        cout << endl; // Move to the next line after printing a level
    }
}

void leftView(node* root, vector<int> &leftv, int level){

    if(root == NULL) return;

    if(level == leftv.size()){
        leftv.push_back(root->data);
    }

    leftView(root->left, leftv, level+1);
    leftView(root->right, leftv, level+1);
}

void rightView(node* root, vector<int> &rightv, int level){

    if(root == NULL) return;

    if(level == rightv.size()){
        rightv.push_back(root->data);
    }

    rightView(root->right,rightv, level+1);
    rightView(root->left, rightv, level+1);
}

void topView(node* root){
    map<int, int> hdToNodeMap;
    queue<pair<node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        node* front = temp.first;
        int hd = temp.second;

        if(hdToNodeMap.find(hd) == hdToNodeMap.end()){
            hdToNodeMap[hd] = front->data;
        }

        //child call
        if(front->left != NULL){
            q.push(make_pair(front->left, hd-1));
        }
        if(front->right != NULL){
            q.push(make_pair(front->right, hd-1));
        }
    }

    cout<< "printing Top View: "<< endl;

    for(auto i : hdToNodeMap){
        cout << i.second << " ";
    }
}

void bottomView(node* root){
    map<int, int> hdToNodeMap;
    queue<pair<node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        node* front = temp.first;
        int hd = temp.second;

        hdToNodeMap[hd] = front->data;

        //child call
        if(front->left != NULL){
            q.push(make_pair(front->left, hd-1));
        }
        if(front->right != NULL){
            q.push(make_pair(front->right, hd-1));
        }
    }

    cout<< "printing Bottom View: "<< endl;

    for(auto i : hdToNodeMap){
        cout << i.second << " ";
    }
}

void leftBoundary(node* root){
    if(root == NULL){
        return;
    }

    //leaf node
    if(root->left == NULL && root->right == NULL){
        return;
    }
    
    // printing data
    cout << root->data << " ";

    //only one call, either left or right
    if(root->left != NULL){
        leftBoundary(root->left);
    }
    else{
        leftBoundary(root->right);
    }
}

void leafBoundary(node* root){
    if(root == NULL){
        return;
    } 

    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
    }

    leafBoundary(root->left);
    leafBoundary(root->right);
}

void rightBoundary(node* root){
    if(root == NULL){
        return;
    }

    //leaf node
    if(root->left == NULL && root->right == NULL){
        return;
    }
    
    //only one call, either left or right
    if(root->right != NULL){
        rightBoundary(root->right);
    }
    else{
        rightBoundary(root->left);
    }

     // printing data
     cout << root->data << " ";
}

void boundaryTraversal(node* root){
    if(root == NULL)
		return;
	cout << root->data << " ";
	leftBoundary(root->left);
	leafBoundary(root->left);
	leafBoundary(root->right);
	rightBoundary(root->right);
}

int main(){
    node* root = createTree();
    boundaryTraversal(root);

    //<<---------------------------------->>
    // node* root = createTree();
    // int level = 0;
    // vector<int> leftv;
    // leftView(root, leftv, level);
    // cout<< "left View: " << endl;
    // for(int i=0; i<leftv.size(); i++){
    //     cout<< leftv[i] << " ";
    // }

    //<<------------------------------------------->>
    // int preOrder[] = {2,8,10,6,4,12};
    // int inOrder[] = {10,8,6,2,4,12};
    // int size = 6;
    // int inStart = 0;
    // int inEnd = 5;
    // int preIndex = 0;

    // node* root = createTree(preOrder, inOrder, size, inStart, inEnd, preIndex);
    // levelOrderTraversal(root);
    return 0;
}