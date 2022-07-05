#include<iostream>
#include<vector>
using namespace std;

template<typename T>

class TreeNode{
    public:
    T data;
    vector<TreeNode<T> *> children;

    //contructor
    TreeNode(T data){
        this -> data = data;
    }

    //Destructor
    ~TreeNode(){
        for(int i = 0; i < children.size(); i++)
            delete children[i];
    }
};