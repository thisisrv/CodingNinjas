#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
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

//BST
vector<int>* getPathBST(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    //base case
    if(root == NULL)
        return NULL;
    

    if(root -> data == data){
        //create a vector
        vector<int>* ouptut = new vector<int>();
        ouptut -> push_back(root -> data);
        return ouptut;
    }

    //Rec call
    if(data < root -> data){

        vector<int>* leftans = getPathBST(root -> left, data);

        if(leftans != NULL){
            leftans -> push_back(root -> data);
            return leftans;
        }
    }

    if(data > root -> data){

        vector<int>* rightans = getPathBST(root -> right, data);

        if(rightans != NULL){
            rightans -> push_back(root -> data);
            return rightans;
        }
    }

    return NULL;
}

//Assignment 
void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
    //Base case
    if(root == NULL)
        return;
    
    insertDuplicateNode(root -> left);
    insertDuplicateNode(root -> right);
    
    //create a new node
    BinaryTreeNode<int>* temp = new BinaryTreeNode<int>(root -> data);
    
    //Small calc
    temp -> left = root -> left;
    
    root -> left = temp;
}

void tree_to_array(BinaryTreeNode<int>* root, vector<int>* &array){
    //Inorder
    if(root == NULL)
        return;
    
    //rec call and small calc
    tree_to_array(root -> left, array);
    array -> push_back(root -> data);
    tree_to_array(root -> right, array);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    //base case
    if(root == NULL)
        return;

    //convert tree to array
    vector<int> * treeData = new vector<int>();

    tree_to_array(root, treeData);

    //sort array
    sort(treeData->begin(), treeData->end());

    //while loop
    int i = 0;
    int j = treeData->size() - 1;

    while(i < j){

        if(treeData->at(i) + treeData -> at(j) == sum){
            cout << treeData->at(i) << " " << treeData->at(j) << endl;  
            i++;
            j--;
        }
            
        
        else if(treeData->at(i) + treeData -> at(j) > sum)
            j--;
        
        else
            i++;
    }
    
}

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
    // Base case
    if(root == NULL)
        return -1;

    if(root -> data == a || root -> data == b)
        return root -> data;

    //Rec call
    int left_ans = getLCA(root -> left, a, b);
    int right_ans = getLCA(root -> right, a, b);
    
    //small calc
    if(left_ans == -1 && right_ans == -1)
        return -1;
    
    else if(left_ans != -1 && right_ans == -1)
        return left_ans;
    
    else {

        if(right_ans != -1 && left_ans == -1)
            return right_ans;
    }
        

    //if both left_ans and right_ans != -1
    return root -> data;
}

int getLCABST(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here

    // Base case
    if(root == NULL)
        return -1;

    // if(root -> data == val1 || root -> data == val2)
    //     return root -> data;

    //rec call
    if(val1 < root -> data && val2 < root -> data){
        return getLCABST(root -> left, val1, val2);
    }

    if(val1 > root -> data && val2 > root -> data){
        return getLCABST(root -> right, val1, val2);
    }

    return root -> data;

}
pair< pair<int,int>, pair<bool, int>> largestBSTSubtreeHelper(BinaryTreeNode<int> *root) {
    // Write your code here
    //Base case
    if(root == NULL){

        //use pair to set values: min, max, isBST, max height of BST
        pair<pair<int, int>, pair<bool, int> >p;
        //min value
        p.first.first = INT_MAX;
        //max value
        p.first.second = INT_MIN;

        //isBST
        p.second.first = true;

        //max height of bst
        p.second.second = 0;

        return p;
    }


    //rec call
    pair<pair<int, int>, pair<bool, int>> left_ans = largestBSTSubtreeHelper(root -> left);
    pair<pair<int, int>, pair<bool, int>> right_ans = largestBSTSubtreeHelper(root -> right);

    //small calc
    pair<pair<int, int>, pair<bool, int>> p;

    //case 1: if both children are bst
    if(left_ans.second.first == true && right_ans.second.first == true){

        //check if root is bst
        if(root -> data > left_ans.first.second && root -> data < right_ans.first.first){

            //root is also a bst;
            //min value
            p.first.first = min(root -> data, left_ans.first.first);
            //max value
            p.first.second = max(root -> data, right_ans.first.second);

            //isBST
            p.second.first = true;

            //max height of bst
            p.second.second = 1 + max(left_ans.second.second, right_ans.second.second);
        }

        else{
            
            //root is not bst only child are
            //min value
            p.first.first = left_ans.first.first;
            //max value
            p.first.second = right_ans.first.second;

            //isBST
            p.second.first = false;

            //max height of bst
            p.second.second = max(left_ans.second.second, right_ans.second.second);
        }
    }

    //case 2: if only 1 child is bst; && case 3: if both children are not BST;
    else //if( (left_ans.second.first == true && right_ans.second.first == false) || (left_ans.second.first == false && right_ans.second.first == true) )
    {

            //min value
            p.first.first = min(root -> data, min(left_ans.first.first, right_ans.first.first));
            //max value
            p.first.second = max(root -> data, max(left_ans.first.second, right_ans.first.second));

            //isBST
            p.second.first = false;

            //max height of bst
            p.second.second = max(left_ans.second.second, right_ans.second.second);
    }

    return p;

}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    pair<pair<int, int>, pair<bool, int> >p = largestBSTSubtreeHelper(root);

    return p.second.second;
}


void replaceWithLargerNodesSumHelper(BinaryTreeNode<int>* root, int &sum){

    //base case
    if(root == NULL)
        return;

    //left call
    replaceWithLargerNodesSumHelper(root -> right, sum);

    sum = sum + root -> data;
    root -> data = sum;

    //right call
    replaceWithLargerNodesSumHelper(root -> left, sum);

}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    int sum = 0;
    replaceWithLargerNodesSumHelper(root, sum);
}
int main(){

    BinaryTreeNode<int>* root = takeInputLevelWise();

    // cout << isBST(root) << endl;

    // vector<int> *ans = getRootToNodePath(root, 8);

    // vector<int> *ans = getPathBST(root, 2);
    // for(int i = 0; i < ans -> size(); i++)
    //     cout <<  ans -> at(i) << " ";

    // delete ans;

    // pairSum(root , 15);

    // cout << getLCABST(root, 8, 15);

    // cout << largestBSTSubtree(root) << endl;

    replaceWithLargerNodesSum(root);

    printTree(root);

    delete root;
}