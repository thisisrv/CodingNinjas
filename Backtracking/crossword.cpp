#include<bits/stdc++.h>
#define n 10
#include<vector>
using namespace std;

bool isValidVertical(int grid[n][n], int row, int col, string word){

}

void setVertical(){

}

void resetVertical(){

}

bool isValidHorizontal(){

}

void setHorizontal(){

}

void resetHorizontal(){

}


bool solveCrossword(int grid[n][n], vector<string> words, int index){

    //base case
    if(index == words.size()){
        //display grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
        return;
    }
    //find an empty location
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '-' || grid[i][j] == words[index][0]){
                //do vertical
                if(isValidVertical(grid, i, j, words[index]) == true){
                    //set vertical
                    setVertical(grid, i, j, words[index]);
                    //rec call
                    bool ans = solveCrossword(grid, words, index + 1);
                    if(ans == true)
                        return true;

                    resetVertical(grid, i, j, words[index]);
                }

                //do horizontal
                if(isValidHorizontal(grid, i, j, words[index]) == true){
                    //set vertical
                    setHorizontal(grid, i, j, words[index]);
                    //rec call
                    bool ans = solveCrossword(grid, words, index + 1);
                    if(ans == true)
                        return true;

                    resetHorizontal(grid, i, j, words[index]);
                }
            }
        }
    }

    return false;
}
int main(){
    
    int grid[n][n];
    //input grid
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    vector<string> words;
    string input;
    cin >> input;

    //string input to vector
    string temp = "";
    for(int i = 0; i < input.length(); i++){
        if(input[i] == ';'){
            words.push_back(temp);
            temp = "";
        }
        else 
            temp = temp + input[i];
    }
    //send last word in temp to words vector
    words.push_back(temp);

    for(int i = 0; i < words.size(); i++)
        cout << words[i] << " ";


    solveCrossword(grid, words, 0);
    return 0;
}