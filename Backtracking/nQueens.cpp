#include <iostream>

using namespace std;

int boards[11][11];

bool isPossible(int n, int row, int column){
    //check in same column
    for(int i = row - 1; i >= 0; i--){
        if(boards[i][column] == 1)
            return false;
    }
    
    //check queen in left diagonal
    for(int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--){
        if(boards[i][j] == 1)
            return false;
    }
    
    //check queen in left diagonal
    for(int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++){
        if(boards[i][j] == 1)
            return false;
    }
    
    return true;
}
void nQueensHelper(int n, int row){
    //base case
    if(row == n){
        //print boards
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << boards[i][j] << " ";
        }
        
        cout << endl;
        return;
    }
    
    
    //small calc
    for(int j = 0; j < n; j++){
        if(isPossible(n, row, j) == true){
            boards[row][j] = 1;
            //rec call
            nQueensHelper(n, row + 1);
            
            boards[row][j] = 0;
        }
    }
    
    return;
}
void placeNQueens(int n){
    //initialise all elements as 0
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            boards[i][j] = 0;
        }
    }
    
    nQueensHelper(n, 0);
}
int main()
{
    int n;
    cin >> n;
    
    placeNQueens(n);
    return 0;
}