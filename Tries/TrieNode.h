#include<iostream>
using namespace std;
//reduces space complexity
class TrieNode{
    public:
    char data;
    TrieNode ** children;
    bool isTerminal;

    //constructor
    TrieNode(char data){
        this -> data = data;
        children = new TrieNode*[26];
        //set children to null
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
            
        isTerminal = false;
    }

    //destructor
    ~TrieNode(){
        for(int i = 0; i < 26; i++)
            delete children[i];

        delete [] children;
    }
};