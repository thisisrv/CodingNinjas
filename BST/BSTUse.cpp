#include<iostream>
#include<queue>
// #include<stack>
// #include<climits>
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

int main(){

    BinaryTreeNode<int>* root = takeInputLevelWise();

    cout << searchInBST(root, 12) << endl;
}