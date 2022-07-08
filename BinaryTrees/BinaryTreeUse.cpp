#include<iostream>
#include<queue>
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


// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
//
int main(){

    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

    BinaryTreeNode<int> *root = takeInputLevelWise();

    printLevelWise(root);

    // cout << countNodes(root) << endl;
    
    // cout << isNodePresent(root, 7) << endl;
    // cout << height(root) << endl;

    mirrorBinaryTree(root);

    printLevelWise(root);
    //delete tree
    delete root;
    
}