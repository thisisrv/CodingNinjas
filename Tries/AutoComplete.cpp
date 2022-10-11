//##########################################################################################################
    void autoComplete(vector<string> input, string pattern) {
        //insert all vector elements in Trie
        for(int i = 0; i < input.size(); i++)
            insertWord(input[i]);
            
        autoComplete(root, pattern, "");
    }
    
// Fn to reach to given pattern node and then call allpossiblewords fn
    void autoComplete(TrieNode* root, string pattern, string output){
        //base case
        if(pattern.size() == 0){
            allpossiblewords(root, output);
            return;
        }
        
        //small calc
        int index = pattern[0] - 'a';
        if(root -> children[index] == NULL)
            return;
        
        //rec call
        autoComplete(root -> children[index], pattern.substr(1), output + root -> children[index] -> data);
    }
    
// Fn to display output whenever leaf node appears or word ends
    void allpossiblewords(TrieNode* root, string output){
        //small calc
        if(root -> isTerminal == true){
            cout << output << endl;
        }
        
        //small calc
        for(int i = 0; i < 26; i++){
            if(root -> children[i] != NULL){
                //rec call
                allpossiblewords(root -> children[i], output + root -> children[i] -> data);
            }
        }
    }
