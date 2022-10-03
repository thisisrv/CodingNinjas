#include "TrieNode.h"
#include<string>
#include<iostream>
using namespace std;

class Trie{
    TrieNode *root;

    void insertWordHelper(TrieNode* root, string word){

        //base case
        if(word.size() == 0){
            root -> isTerminal = true;
            return;
        }

        //small calc
        int index = word[0] - 'a';
        //check if (letter exists or not) index is NULL or not
        TrieNode* child;
        if(root -> children[index] != NULL){
            child = root -> children[index];
        } 

        else{
            //letter doesnot exists
            //create a node with word = word[0]
            child = new TrieNode(word[0]);

            //connect it to root
            root -> children[index] = child;
        }

        //rec call
        insertWordHelper(child, word.substr(1));
        
    }

    bool searchHelper(TrieNode* root, string word){
        //base case
        if(word.size() == 0){
            if(root -> isTerminal == true)
                return true;
            else
                return false;
        }

        //small calc
        int index = word[0] - 'a';

        //if letter not present return false
        if(root -> children[index] == NULL)
            return false;

        //rec call
        bool ans = searchHelper(root -> children[index], word.substr(1));
        return ans;
    }

    void removeWordHelper(TrieNode* root, string word){
        //base case
        if(word.size() == 0){
            
            root -> isTerminal = false;
            return;
        }
        
        //small calc
        int index = word[0] - 'a';
        if(root -> children[index] == NULL)
            return;
            
        //else
        //rec call
        TrieNode* child = root -> children[index];
        removeWordHelper(child, word.substr(1));
    
        //remove child if child is useless
        if(child -> isTerminal == false){
            
            //check if it has children
            for(int i = 0; i < 26; i++){
                if(child -> children[i] != NULL)
                    return;
            }
            
            //Child has no children 
            delete child;
            root -> children[index] = NULL;
        }
        
    }

    public:

    //constructor
    Trie(){
        //add NULL first
        root = new TrieNode('\0');
    }

    ~Trie(){
        delete root;
    }

    //insertfn
    void insertWord(string word){
        
        //helper fn
        insertWordHelper(root, word);
    }

    bool search(string word){
        return searchHelper(root, word);
    }

    void removeWord(string word){
        removeWordHelper(root, word);
    }    
 
};

int main(){
    Trie t;

    t.insertWord("ancd");
    t.insertWord("a");
    cout << t.search("ancd");
    t.removeWord("ancd");
    cout << t.search("ancd");

}