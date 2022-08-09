#include<iostream>
#include<queue>
#include<climits>
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

int getHeight(TreeNode<int>* root) {
    // Write your code here
    int maxHeight = 0;

    //Rec call
    for(int i =0; i < root -> children.size(); i++){
        int height = getHeight(root -> children[i]);

        if(height > maxHeight)
            maxHeight = height;
    }

    //small calc
    return 1 + maxHeight;
}

void printAtLevelK(TreeNode<int>* root, int k){

    //edge case
    if(root == NULL)
        return;

    //for k == 0
    if(k == 0){
        cout << root -> data << endl;
        return;
    }

    //Rec call if k != 0;
    for(int i = 0; i < root -> children.size(); i++){
        printAtLevelK(root -> children[i], k - 1);
    }
}

int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here

    //edge case
    if(root == NULL)
        return 0;
    
    //Base case
    if(root -> children.size() == 0)
        return 1;

    //small calc
    int leaf_count = 0;
    for(int i = 0; i < root -> children.size(); i++){
        leaf_count += getLeafNodeCount(root -> children[i]);
    }

    return leaf_count;
}   

void preOrder(TreeNode<int>* root){

    //edge case
    if(root == NULL)
        return;
    
    //print root data
    cout << root -> data << " ";

    //Rec call
    for(int i = 0; i < root -> children.size(); i++){
        preOrder(root -> children[i]);
    }
}


void printPostOrder(TreeNode<int>* root) {
    // Write your code here
    //edge case
    if(root == NULL)
        return;
    
    //Rec call
    for(int i = 0; i < root -> children.size(); i++){
        printPostOrder(root -> children[i]);
    }
    
    //Display root data
    cout << root -> data << " ";
}


//Assigment
bool isPresent(TreeNode<int>* root, int x) {
    // Write your code here

    if(x == root -> data)
        return true;

    //Rec call
    for(int i = 0; i < root -> children.size(); i++){

        bool small_ans = isPresent(root -> children[i], x);

        if(small_ans == true)
            return small_ans;
    }

    return false;
}

int getLargeNodeCount(TreeNode<int>* root, int x) {
    // Write your code here

    //Rec call
    int child_count = 0;

    for(int i = 0; i < root -> children.size(); i++){

        child_count += getLargeNodeCount(root -> children[i], x);
    }

    if(root -> data > x)
        return 1 + child_count;

    else   
        return child_count;
}
//************************************************************************
int returnSumOfTree(TreeNode<int>* root){

    int sum = root -> data;

    for(int i = 0; i < root -> children.size(); i++){

        sum += returnSumOfTree(root -> children[i]);
    }

    return sum;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    //edge case
    if(root == NULL)
        return root;

    //root has no child
    if(root -> children.size() == 0)
        return root;

    //for tree
    TreeNode<int>* max_node = root;
    int max_node_sum = root -> data;

    //Get sum of root;
    for(int i = 0; i < root -> children.size(); i++)
        max_node_sum += root -> children[i] -> data;

    //Rec call
    for(int i = 0; i < root -> children.size(); i++){

        TreeNode<int>* maxchildNode = maxSumNode(root -> children[i]);
        // int maxchildsum = root -> children[i] -> data;
        int maxchildsum = maxchildNode -> data;

        //Get maxchildsum for child
        for(int j = 0; j < maxchildNode -> children.size(); j++){
            maxchildsum += maxchildNode -> children[j] -> data;
        }

        //compare
        if(maxchildsum > max_node_sum){
            max_node = maxchildNode;
            max_node_sum = maxchildsum;
        }
            
    }


    return max_node;
}

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
    //compare root data
    if(root1 -> data != root2 -> data)
        return false;

    //compare children size
    if(root1 -> children.size() != root2 -> children.size())
        return false;

    //rec call
    for(int i = 0; i < root1 -> children.size(); i++){

        bool small_ans = areIdentical(root1 -> children[i], root2 -> children[i]);

        if(small_ans == false)
            return false;
    }

    return true;
}

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here

    //if only root is there
    if(root -> children.size() == 0){
        if(root -> data > x)
            return root;
        else
            return NULL;
    }

    //root has children
    TreeNode<int>* nextLargerNode = NULL;
    if(root -> data > x)
        nextLargerNode = root;
    
    //Rec call
    for(int i = 0; i < root ->children.size(); i++){

        TreeNode<int>* childgreaternode = getNextLargerElement(root -> children[i], x);

        if(nextLargerNode == NULL)
            nextLargerNode = childgreaternode;

        else{
            if(childgreaternode != NULL && childgreaternode -> data < nextLargerNode -> data)
                nextLargerNode = childgreaternode;
        }
    }

    return nextLargerNode;
}
//************************************************************************
void helperfn(TreeNode<int>* root,TreeNode<int>* &fmax,TreeNode<int>* &smax){

    //Edge case
    if(root == NULL)
        return;

    //small calc
    //Add root value
    if(fmax == NULL){
        fmax = root;
    } 

    //root -> data > fmax case
    else if(root -> data > fmax -> data){
        smax = fmax;
        fmax = root;
    }

    else {
        // smax < root data < fmax
            if(root -> data < fmax -> data){
                
                if(smax == NULL)
                    smax = root;
                else{
                    //compare root and smax data
                    if(root -> data > smax -> data)
                        smax = root;
                }
        }

    }

    //Rec call
    for(int i = 0; i < root -> children.size(); i++){

        helperfn(root -> children[i], fmax, smax);
    }

}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    
    //helper fn

    TreeNode<int>* fmax = NULL;
    TreeNode<int>* smax = NULL;

    helperfn(root, fmax, smax);

    return smax;
    
}
//***********************************************************************
void replaceWithDepthValuewithDepth(TreeNode<int>* root, int depth){

    //edge case
    if(root == NULL)
        return;

    //small calc
    root -> data = depth;

    //rec call
    for(int i = 0; i < root -> children.size(); i++)
        replaceWithDepthValuewithDepth(root -> children[i], depth + 1);
}
void replaceWithDepthValue(TreeNode<int>* root) {
    // Write your code here

    //We will us helper fn and pass depth as input
    replaceWithDepthValuewithDepth(root, 0);
}


//************************************************************************
//1 3 2 3 4 2 5 6 0 0 0 0
//5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
//10 3 20 30 40 2 40 50 0 0 0 0 
int main(){

    // //root node
    // TreeNode<int> *root = new TreeNode<int>(1);

    // //child nodes
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);

    // //make connection
    // root -> children.push_back(node1);
    // root -> children.push_back(node2);

    TreeNode<int>* root1 = takeInputLevelWise();
    //Print tree
    // printLevelWise(root);
    // TreeNode<int>* root2 = takeInputLevelWise();
    // cout << numNodes(root) << endl;
    // TreeNode<int>* maxData = maxDataNode(root); 
    // cout << maxData -> data << endl;

    // cout << getHeight(root) << endl;

    // printAtLevelK(root, 2);
    // cout << getLeafNodeCount(root) << endl;
    // preOrder(root);
    // printPostOrder(root);

    // cout << isPresent(root, -6);

    // cout << getLargeNodeCount(root, 10);
    
    // TreeNode<int> *maxNode = maxSumNode(root);

    // cout << maxNode -> data << endl;
    
    // cout << areIdentical(root1, root2) << endl;

    TreeNode<int>* p = maxSumNode(root1);

    cout << p -> data << endl;

    //Delete tree
    delete root1;
    // delete root2;
}