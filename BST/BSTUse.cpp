#include<iostream>
#include<queue>
#include<vector>
// #include<stack>
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

bool searchInBST(BinaryTreeNode<int> *root , int k) {
	// Write your code here
    //Base case
    if(root == NULL)
        return false;

    //small calc
    if(k == root -> data)
        return true;

    //Rec call
    if(k > root -> data)
        return searchInBST(root -> right, k);
    
    else    
        return searchInBST(root -> left, k);
    
}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	// Write your code here
    //base case
    if(root == NULL)	
        return;
    
   
    //rec call
    if(root -> data > k1)
        elementsInRangeK1K2(root -> left, k1, k2);
    
    //small calc
    if(root -> data >= k1 && root -> data <= k2)
        cout << root -> data << " ";
    
    if(root -> data < k2)
        elementsInRangeK1K2(root -> right, k1, k2);
}


bool isBSTHelper(BinaryTreeNode<int> *root, int minimum, int maximum){
    //Base case
    if(root == NULL)
        return true;
    
    //small calc
    if(root -> data < minimum || root -> data > maximum)
        return false;
    
    //rec call
    bool leftans = isBSTHelper(root -> left, minimum, root -> data - 1);
    bool rightans = isBSTHelper(root -> right, root ->data , maximum);

    return leftans && rightans;
}
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    //helper fn
    return isBSTHelper(root, INT_MIN, INT_MAX);
}

BinaryTreeNode<int>* constructTreeHelper(int *input, int si, int ei) {
    //base case
    if(si > ei)
        return NULL;
    
    //Rec call and small calc
    int mid = (si + ei) / 2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    
    root -> left = constructTreeHelper(input, si, mid - 1);
    root -> right = constructTreeHelper(input, mid + 1, ei);
    
    return root;
}


BinaryTreeNode<int>* constructTreeFromSortedArray(int *input, int n) {
	// Write your code here
    //Helper fn
    return constructTreeHelper(input, 0, n - 1);
}

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){

    //Base case
    if(root == NULL)
        return NULL;
    
    if(root -> data == data){
        //create a vector
        vector<int>* ouptut = new vector<int>();
        ouptut -> push_back(root -> data);
        return ouptut;
    }

    //Rec call left tree
    vector<int>* leftans = getRootToNodePath(root -> left, data);
    if(leftans != NULL){

        //push root data into leftans
        leftans -> push_back(root -> data);
        return leftans;
    }

    //Rec call right tree
    vector<int>* rightans = getRootToNodePath(root -> right, data);
    if(rightans != NULL){

        //push root data into leftans
        rightans -> push_back(root -> data);
        return rightans;
    }
    
    return NULL;
}


int main(){

    BinaryTreeNode<int>* root = takeInputLevelWise();

    // cout << isBST(root) << endl;

    vector<int> *ans = getRootToNodePath(root, 8);

    for(int i = 0; i < ans -> size(); i++)
        cout << *(ans + i) << " ";
}