#include "BinaryTreeNode.h"
#include<iostream>
#include<climits>
using namespace std;

class BST{

    BinaryTreeNode<int>* root;
    bool hasDataHelper(BinaryTreeNode<int>* root, int data){

        //Base case
        if(root == NULL)
            return false;
        
        //small calc
        if(root -> data == data)
            return true;
        
        //call
        if(data < root -> data)
            return hasDataHelper(root -> left, data);

        if(data > root -> data)
            return hasDataHelper(root -> right, data);
        
        return false;
    }

    BinaryTreeNode<int>* insertDataHelper(BinaryTreeNode<int>* root, int data){
        //Base case
        if(root == NULL){
            //create root node and return root
            BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
            return root;
        }

        //Rec call
        if(data < root -> data)
            root -> left = insertDataHelper(root -> left, data);
        
        if(data > root -> data)
            root -> right = insertDataHelper(root -> right, data);

        return root;
    }

    void inorder(BinaryTreeNode<int>* root){

        //Base case
        if(root == NULL)
            return;
        
        inorder(root -> left);

        cout << root -> data << " ";

        inorder(root -> right);
    }

    int findMin(BinaryTreeNode<int>* root){
        //Base case
        if(root == NULL){
            return INT_MAX;
        }    
        
        int minimum = findMin(root -> left);
        
        return min(minimum, root -> data);
        
    }
    BinaryTreeNode<int>* deleteDataHelper(BinaryTreeNode<int>* root, int data){
        //Base case
        if(root == NULL)
            return NULL;

        //small calc
        if(data == root -> data){

            //case 1
            if(root -> left == NULL && root -> right == NULL){

                //return null
                return NULL;
            }

            //case 2
            if(root -> left != NULL && root -> right == NULL){

                //make root = root -> left;
                BinaryTreeNode<int>* temp = root -> left;
                delete(root);
                return temp;

            }
            if(root -> right != NULL && root -> left == NULL){

                //make root = root -> right;
                BinaryTreeNode<int>* temp = root -> right;
                delete(root);
                return root;

            }

            //Case 3
        if(root -> left != NULL && root -> right != NULL){

            //Get min from root -> right subtree
            int minimum = findMin(root -> right);

            //Update root with minimum value
            root -> data = minimum;

            //delete minimum value from right
            root -> right = deleteDataHelper(root -> right, minimum);
        }
        }


        //Rec call
        if(data < root -> data)
            root -> left = deleteDataHelper(root -> left, data);
        
        if(data > root -> data)
            root -> right = deleteDataHelper(root -> right, data);

        return root;
    }

    public:

    BST(){
        root = NULL;
    }

    ~BST(){
        delete root;
    }

    
    bool hasData(int data){

        //Helper fn
        return hasDataHelper(root, data);

    }


    void insertData(int data){
        
        root = insertDataHelper(root, data);
    }

    void display(){
        inorder(root);
    }

    void deleteData(int data){

        root = deleteDataHelper(root, data);
    }
};