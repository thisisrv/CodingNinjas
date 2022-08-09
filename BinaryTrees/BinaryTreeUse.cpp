#include<iostream>
#include<queue>
#include<stack>
#include<climits>
#include "BinaryTreeNode.h"

using namespace std;

void printTree(BinaryTreeNode<int>* root){

    //Base case
    if(root == NULL)
        return;
    
    //small calc
    cout << root -> data << ": ";

    if(root -> left != NULL)
        cout << "L" << root -> left -> data;

    if(root -> right != NULL){
        cout << "R" << root -> right -> data; 
    }

    cout << endl;

    //rec call
    printTree(root -> left);
    printTree(root -> right);
}

//take input levelwise
BinaryTreeNode<int>* takeInputLevelWise(){

    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;

    //check if -1
    if(rootData == -1)
        return NULL;
    
    //Create root node
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    //create queue
    queue<BinaryTreeNode<int>*> pendingNodes;

    //push root to queue
    pendingNodes.push(root);

    //while loop
    while(pendingNodes.size() != 0){

        //take out front
        BinaryTreeNode<int>* front = pendingNodes.front();

        //pop
        pendingNodes.pop();

        //take left child input
        int leftchilddata;
        cout << "Enter left chilf of " << front -> data << endl;
        cin >> leftchilddata;

        //make node, attach to left and push in queue
        if(leftchilddata != -1){

            BinaryTreeNode<int>* leftchild = new BinaryTreeNode<int>(leftchilddata);

            //attatch
            front -> left = leftchild;

            //push into queue
            pendingNodes.push(leftchild);
        }

        //take right child input
        int rightchilddata;
        cout << "Enter right chilf of " << front -> data << endl;
        cin >> rightchilddata;

        //make node, attach to left and push in queue
        if(rightchilddata != -1){

            BinaryTreeNode<int>* rightchild = new BinaryTreeNode<int>(rightchilddata);

            //attatch
            front -> right = rightchild;

            //push into queue
            pendingNodes.push(rightchild);
        }
    }

    return root;
}

void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    //make queue
    queue<BinaryTreeNode<int>*> pendingNodes;

    //push root in queue;
    pendingNodes.push(root);

    //Loop

    while(pendingNodes.size() != 0){

        //front
        BinaryTreeNode<int>* front = pendingNodes.front();

        //pop
        pendingNodes.pop();

        //Display 
        cout << front -> data << ":";
        
        if(front -> left != NULL){
            cout << "L:" << front -> left -> data << ",";
            pendingNodes.push(front -> left);
        }
            
        else
            cout << "L:-1,";
        
        if(front -> right != NULL){
            cout << "R:" << front -> right -> data;
            pendingNodes.push(front -> right);
        }
            

        else    
            cout << "R:-1";

        cout << endl;
    }

}

int countNodes(BinaryTreeNode<int>* root){

    //Base case
    if(root == NULL)
        return 0;

    //small calc and rec all
    return 1 + countNodes(root -> left) + countNodes(root -> right);
}

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here

    //edge case
    if(root == NULL)
        return false;

    //check root data
    if(root -> data == x)
        return true;
    

    //Rec call on left tree
    bool ans_left = isNodePresent(root -> left, x);

    if(ans_left == true)
        return ans_left;
    

    //Rec call on right tree
    bool ans_right = isNodePresent(root -> right, x);

    if(ans_right == true)
        return ans_right;

    //if node not present in left as well as right tree
    return false;
}

int height(BinaryTreeNode<int>* root) {
    // Write our code here

    //base case
    if(root == NULL)
        return 0;

    //small calc and rec call
    return 1 + max(height(root -> left), height(root -> right));
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here

    //base case
    if(root == NULL)
        return;

    //rec call
    mirrorBinaryTree(root -> left);
    mirrorBinaryTree(root -> right);

    //small calc
    BinaryTreeNode<int>* temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;

}

void inorder(BinaryTreeNode<int>* root){

    //Base case
    if(root == NULL)
        return;

    //small calc and rec call
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(BinaryTreeNode<int>* root){

    //Base case
    if(root == NULL)
        return;

    //small calc and rec call
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(BinaryTreeNode<int>* root){

    //Base case
    if(root == NULL)
        return;

    //small calc and rec call
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

//*******************************************************
BinaryTreeNode<int>* buildTreehelper(int *preorder, int *inorder, int prS, int prE, int inS, int inE) {

    //Base case
    //if array are empty
    if(inS > inE)
        return NULL;

    //Create root node
    int rootData = preorder[prS];

    //calculate root index
    int rootIndex = -1;

    for(int i = inS; i <= inE; i++){
        if(inorder[i] == rootData){
            rootIndex = i;
            break;
        }
    }

    int leftInorderStart = inS;
    int leftInorderEnd = rootIndex - 1;
    int leftPreorderStart = prS + 1;
    int leftPreorderEnd = leftInorderEnd - leftInorderStart + leftPreorderStart;
    int rightInorderStart = rootIndex + 1;
    int rightInorderEnd = inE;
    int rightPreorderStart = leftPreorderEnd + 1;
    int rightPreorderEnd = prE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    root -> left = buildTreehelper(preorder, inorder, leftPreorderStart, leftPreorderEnd, leftInorderStart, leftInorderEnd);
    root -> right = buildTreehelper(preorder, inorder, rightPreorderStart, rightPreorderEnd, rightInorderStart, rightInorderEnd);
 

    return root;

}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength){


    BinaryTreeNode<int>* root = buildTreehelper(preorder, inorder, 0, preLength - 1, 0, inLength - 1);

    return root;
}


pair<int, int> heightDiameter(BinaryTreeNode<int>* root){

    //base case
    if(root == NULL){

        //create pair with height = 0 and diameter = 0;
        //first = height and second  = diameter
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    //rec call
    pair<int, int> leftAns = heightDiameter(root -> left);
    pair<int, int> rightAns = heightDiameter(root -> right);

    //small calc
    int leftChildheight = leftAns.first;
    int leftChilddiameter = leftAns.second;
    int rightChildheight = rightAns.first;
    int rightChilddiameter = rightAns.second;

    //create pair
    int height = 1 + max(leftChildheight, rightChildheight);
    int diameter = max(leftChildheight + rightChildheight, max(leftChilddiameter, rightChilddiameter));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;

    return p;
}

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here

    //base case
    if(root == NULL){

        pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;

        return p;
    }


    //rec call
    pair<int, int> leftAns = getMinAndMax(root -> left);
    pair<int, int> rightAns = getMinAndMax(root -> right);

    //small calc
    int leftMin = leftAns.first;
    int leftMax = leftAns.second;
    int rightMin = rightAns.first;
    int rightMax = rightAns.second;

    int minimum = min(root -> data, min(leftMin, rightMin));
    int maximim = max(root -> data, max(leftMax, rightMax));

    //create pair
    pair<int, int> p;
    p.first = minimum;
    p.second = maximim;

    return p;
}


//******************************************************************************************
//ASSIGNMENT
int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
    //base case
    if(root == NULL)
        return 0;

    //Rec call
    int leftsum = getSum(root -> left);
    int rightsum = getSum(root -> right);

    //small calc
    return root -> data + leftsum + rightsum;
}

pair<int, bool> isBalancedHelper(BinaryTreeNode<int>* root){

    //base case
    //root is NULL
    if(root == NULL){
        pair<int, bool> p;
        p.first = 0;
        p.second = true;

        return p;
    }

    //Rec call
    pair<int, bool> left = isBalancedHelper(root -> left);
    pair<int, bool> right = isBalancedHelper(root -> right);


    //small calc
    pair<int, bool> p;

    p.first = 1 + max(left.first, right.first);

    //check for balanced
    if(left.second == false || right.second == false)
        p.second = false;
    
    else{

        //if both are balanced
        if(left.first - right.first >= -1 && left.first - right.first <= 1)
            p.second = true;
        
        else
            p.second = false;
    }

    return p;
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here

    pair<int, bool> p = isBalancedHelper(root);

    return p.second;
}


void levelOrderTraversal(BinaryTreeNode<int> *root) {
    // Write your code here
    
    //check base case
    if(root == NULL)
        return;
    
    //create a queue
    queue<BinaryTreeNode<int>* > q ;
    
    //Push root node
    q.push(root);
    q.push(NULL);
    
    //Loop
    while(q.size() != 0){
        
        //Front and pop
        BinaryTreeNode<int>* front = q.front();
        
        //pop
        q.pop();
        
        //check if front is NULL
        if(front == NULL){
            //check if queue is not empty
            if(q.size() != 0){
                cout << endl;
                q.push(NULL);
            }
        }
        
        //Front is not NULL
        else{
            //Add children to queue
            cout << front -> data << " ";
            
            if(front -> left != NULL)
                q.push(front -> left);
            
            if(front -> right != NULL)
                q.push(front -> right);
        }
	}
}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here
    //Base case
    if(root == NULL)
        return root;

    //small calc
    if(root -> left == NULL && root -> right == NULL)
        return NULL;
    
    //Rec call
    if(root -> left != NULL)
        root -> left = removeLeafNodes(root -> left);
    
    if(root -> right != NULL)
        root -> right = removeLeafNodes(root -> right);

    return root;
}


template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
            
    //vector to store LL heads;
    vector<Node<int>*> v;
    if(root == NULL)
        return v;
    // Write your code here
    Node<int>* head = NULL;
    Node<int>*tail = NULL;
    
    //make queue
    queue<BinaryTreeNode<int>*> pendingNodes;
    
    
    
    //Push root and NULL in queueu
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    
    //Loop
    while(pendingNodes.size() != 0){
        //Front and pop
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        
        //if front is NULL
        if(front == NULL){
            
            //add head to vector
            v.push_back(head);
            
            //reset head and tail
            head = tail = NULL;
            
            //Push NULL if queue is not empty
            if(pendingNodes.size() != 0)
                pendingNodes.push(NULL);
        }
        
        //if front != NULL
        else{
            
            //create node of front -> data
            Node<int>* newnode = new Node<int>(front -> data);
            
            //check if head == NULL then attach both head and tail to node
            if(head == NULL){
                head = tail = newnode;
            }
            
            else{
                //add newnode in tail -> next and increment tail
                tail -> next = newnode;
                tail = newnode;
            }
            
            //Insert children if front in queue
            if(front -> left != NULL)
                pendingNodes.push(front -> left);
            
            if(front -> right != NULL)
                pendingNodes.push(front -> right);
        }
    }
    
    return v;

}

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    //Base case
    if(root == NULL)
        return;
    
    //stacks
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    
    //Push root to s1
    s1.push(root);
    
    //loop
    while(s1.size() != 0 || s2.size() != 0){
        
        //Loop for s1
        while(s1.size() != 0){
            
            BinaryTreeNode<int>* top = s1.top();
            
            s1.pop();
            
            //display top
            cout << top -> data << " ";
            
            //Add children to s2 L R
            
            if(top -> left)
                s2.push(top -> left);
            
            if(top -> right)
                s2.push(top -> right);
            
        }
        
        cout << endl;
        
        //Loop for s2
        while(s2.size() != 0){
            
            BinaryTreeNode<int>* top = s2.top();
            
            s2.pop();
            
            //display top
            cout << top -> data << " ";
            
            //Add children to s1 R L
            
            if(top -> right)
                s1.push(top -> right);
            
            if(top -> left)
                s1.push(top -> left);
            
        }
        
        cout << endl;
        
        
    }

}

int find_depth(BinaryTreeNode<int>* root, int p, int level){
    //base case
    
    if(root == NULL)
        return -1;
    
    //small calc
    if(root -> data == p)
        return level;
    
    //rec call
    int left_depth = find_depth(root -> left, p, level + 1);
    
    if(left_depth != -1)
        return left_depth;
    
    return find_depth(root -> right, p, level + 1);
}
#include<climits>
int find_parent(BinaryTreeNode<int>* root, int p, int parent){
    
    //base case
    if(root == NULL)
        return INT_MIN;
    
    //small calc
    if(root -> data == p)
        return parent;
    
    //rec call
    int left_parent = find_parent(root -> left, p, root -> data);
    if(left_parent != INT_MIN)
        return left_parent;
    
    return find_parent(root -> right, p, root -> data);
}

// ####################################  TEST ############################################
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
    //base case
    if(root == NULL)
        return false;
    
    int p_level = find_depth(root, p, 0);
    int q_level = find_depth(root, q, 0);
    
    if(p_level == -1 && q_level == -1)
        return false;
    
    //find parent of p and q;
    if(p_level == q_level){
        
        //calculate parent;
        int p_parent = find_parent(root, p, INT_MIN);
        int q_parent = find_parent(root, q, INT_MIN);
        
        if(p_parent == q_parent)
            return false;
        
        else
            return true;
    }
    
	return false;
}

//*******************************************************
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
//
int main(){

    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

    // BinaryTreeNode<int> *root = takeInputLevelWise();

    // printLevelWise(root);

    // cout << countNodes(root) << endl;
    
    // cout << isNodePresent(root, 7) << endl;
    // cout << height(root) << endl;

    // mirrorBinaryTree(root);

    // printLevelWise(root);
    
    // inorder(root);
    // preorder(root);

    // int size;
    // cin >> size;
    // int *pre = new int[size];
    // int *in = new int[size];
    // for (int i = 0; i < size; i++) cin >> pre[i];
    // for (int i = 0; i < size; i++) cin >> in[i];
    // BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    // printLevelWise(root);
    
    BinaryTreeNode<int> *root = takeInputLevelWise();

    // pair<int, int> p = heightDiameter(root);
    // pair<int, int> p = getMinAndMax(root);

    // cout << "Min: " << p.first << endl;
    // cout << "Max: " << p.second << endl;

    // cout << isBalanced(root) << endl;
    // printLevelWise(root);

    // root = removeLeafNodes(root);
    // levelOrderTraversal(root);

    // zigZagOrder(root);
    cout << find_depth(root, 3, 0) << endl;
    cout << find_depth(root, 6, 0) << endl;

    cout << find_parent(root, 3, INT_MIN) << endl;
    cout << find_parent(root, 6, INT_MIN) << endl;
    //delete tree   
    delete root;
    
}