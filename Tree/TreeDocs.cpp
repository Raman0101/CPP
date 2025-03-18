#include<bits/stdc++.h>
using namespace std;

//Create Node for Tree
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

//Build Tree
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

//PRE ORDER TRAVERSAL
void preOrder(node* root){
    //BASE CASE 
    if(root == NULL) return;

    cout<< root->data << " "; // root node

    //left node
    preOrder(root->left);

    //right node
    preOrder(root->right);

}

//INORDERTRAVERSAL
void inOrder(node* root){
    //Base case
    if(root == NULL) return;

    // left call
    inOrder(root->left);
    //root
    cout<< root->data << " ";
    //right call
    inOrder(root->right);
}

//POSTORDERTRAVERSAL
void postOrder(node* root){
    //Base case
    if(root == NULL) return;

    // left call
    postOrder(root->left);
    //right call
    postOrder(root->right);
    //root
    cout<< root->data << " ";
}

//LEVEL ORDER TRAVERSAL
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* front = q.front();
        q.pop();

        cout<< front->data << " ";

        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
}

//MAX HEIGHT OF TREE
int height(node* root) {
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int height = max(leftHeight, rightHeight) + 1;
    return height;
}

//DIAMETER OF TREE
int diameterOfBinaryTree(node* root) {
    if(root == NULL) return 0;

    int leftLen = diameterOfBinaryTree(root->left);
    int rightLen = diameterOfBinaryTree(root->right);
    int bothLen = height(root->left) + height(root->right);

    int ans = max(leftLen, max(rightLen, bothLen));

    return ans;
}

//LOWEST COMMON ANCESTOR
node* lowestCommonAncestor(node* root, node* p, node* q) {
    //base cases
    if(root == NULL) return NULL;
    if(root->data == p->data) return p;
    if(root->data == q->data) return q;

    node* leftAns = lowestCommonAncestor(root->left, p, q);
    node* rightAns = lowestCommonAncestor(root->right, p, q);

    if(leftAns == NULL && rightAns == NULL) return NULL;
    else if(leftAns != NULL && rightAns == NULL) return leftAns;
    else if(leftAns == NULL && rightAns != NULL) return rightAns;
    else return root;
}

// BALANCED BINARY TREE
bool isBalanced(node* root) {
    if(root == NULL) return true;

    //curr Node
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int diff = abs(leftHeight  - rightHeight);

    bool currNodeAns = (diff <=1);

    //recursive calls

    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    if(currNodeAns && leftAns && rightAns){
        return true;
    }
    else return false;
}


//<<---- Views of Tree --------------------->>
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

//<<--- Boundary Traversal ------------------->>
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

