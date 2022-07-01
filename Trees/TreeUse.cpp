#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise(){

    int rootData;
    cout << "Enter Root data" << endl; 
    cin >> rootData;

    //create root node
    TreeNode<int>* root = new TreeNode<int>(rootData);

    //create queue
    queue<TreeNode<int>*> pendingNodes;

    //add root into queue;
    pendingNodes.push(root);

    //Loop
    while(pendingNodes.size() != 0){

        //get and store front
        TreeNode<int>* front = pendingNodes.front();

        //pop front from queue
        pendingNodes.pop();

        //add children of front
        int numChild;
        cout << "Enter number of children of " << front -> data << endl;
        cin >> numChild;

        //Loop
        for(int i = 0; i < numChild; i++){
            int childData;
            cout << "Enter" << i << "th child of " << front -> data << endl;
            cin >> childData;

            //Create child node
            TreeNode<int>* child = new TreeNode<int>(childData);

            //add child to chilren vector of front
            front -> children.push_back(child);

            //push child into queue
            pendingNodes.push(child);
        }
    }

    return root;

}
TreeNode<int>* takeInput(){

    int rootData;
    cin >> rootData;

    //create root node
    TreeNode<int>* root = new TreeNode<int>(rootData);

    //take child nodes
    int n;
    cout << "Enter number of child nodes for " << rootData << endl;
    cin >> n;

    //Rec call takeInput
    for(int i = 0; i < n; i++){
        TreeNode<int>* child = takeInput();
        //add child to root
        root -> children.push_back(child);
    } 

    return root;
}

void printTree(TreeNode<int>* root){
    //Edge case
    if(root == NULL)
        return;
    
    //small calc display root data
    cout << root -> data << ":";

    //Display it children data also
    for(int i = 0; i < root -> children.size(); i++){
        cout << root -> children[i] -> data << ",";
    }

    cout << endl;

    //Rec call
    for(int i = 0; i < root -> children.size(); i++){
        // cout << root -> children[i] -> data << ",";
        printTree(root -> children[i]);
    }

}

void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    //create queue
    queue<TreeNode<int>*> pendingNodes;

    //add root in queue
    pendingNodes.push(root);

    //loop
    while(pendingNodes.size() != 0){

        //front 
        TreeNode<int>* front = pendingNodes.front();
        
        //pop front
        pendingNodes.pop();

        //Display front data
        cout << front -> data << ":" ;

        //display children data of front;
        for(int i = 0; i < front -> children.size(); i++){

            cout << front -> children[i] -> data << ",";

            //add into queue
            pendingNodes.push(front -> children[i]);
        }

        cout << endl;
    }
}

int numNodes(TreeNode<int>* root){
    //for root;
    int ans = 1;

    //rec call and small calc
    for(int i = 0; i < root -> children.size(); i++){

        ans += numNodes(root -> children[i]); 
    }

    return ans;
}

int sumNodes(TreeNode<int>* root){
    //for root;
    int ans = root -> data;

    //rec call and small calc
    for(int i = 0; i < root -> children.size(); i++){

        ans += numNodes(root -> children[i]); 
    }

    return ans;
}


TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    //create a max node
    TreeNode<int>* maxData = root;

    //rec call and small calc
    for(int i = 0; i < root -> children.size(); i++){

        TreeNode<int>* child = maxDataNode(root -> children[i]);

        //small calc
        if(maxData -> data < child -> data)
            maxData = child;
    }

    return maxData;
}
int main(){

    // //root node
    // TreeNode<int> *root = new TreeNode<int>(1);

    // //child nodes
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);

    // //make connection
    // root -> children.push_back(node1);
    // root -> children.push_back(node2);

    TreeNode<int>* root = takeInputLevelWise();
    //Print tree
    printLevelWise(root);

    cout << numNodes(root) << endl;
    TreeNode<int>* maxData = maxDataNode(root); 
    cout << maxData -> data << endl;
}