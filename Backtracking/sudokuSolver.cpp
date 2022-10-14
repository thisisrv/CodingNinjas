#include <iostream>
#define n 9
using namespace std;
bool isSafe(int grid[n][n], int row, int col, int num){
    //check in same column
    for(int i = 0; i < n; i++){
        if(grid[i][col] == num)
            return false;
    }
    
    //check in same row
    for(int i = 0; i < n; i++){
        if(grid[row][i] == num)
            return false;
    }
    
    //check in same grid
    int row_factor = row - (row % 3);
    int col_factor = col - (col % 3);
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i + row_factor][j + col_factor] == num)
                return false;
        }
    }
    
    return true;
}
bool findEmptyLocation(int grid[n][n], int &row, int &col){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(int grid[n][n]){
    //find empty place
    int row, col;
    if(findEmptyLocation(grid, row, col) == false)
        return true;
        
    //if found empty position, start filling values
    for(int i = 1; i <= 9; i++){
        //check if value is safe
        if(isSafe(grid, row, col, i) == true){
            
            grid[row][col] = i;
            bool ans = solveSudoku(grid);
            if(ans == true)
                return true;
            
            //backtrack if sudoki not solved
            grid[row][col] = 0;
        }
    }
    
    return false;
        
}
int main()
{
    int grid[n][n];
    
    //Take input in grid;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    
    bool ans = solveSudoku(grid);
    
    if(ans == 1)
        cout << "true";
    else
        cout << "false";
    
    // //Print Sudoku 
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}