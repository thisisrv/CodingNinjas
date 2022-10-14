/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;

void printSolution(int **solution, int n){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << solution[i][j] << " ";
    }
    
    cout << endl;
}
void mazeHelp(int maze[][20], int n, int **solution, int x, int y){
    //base case
    if(x == n - 1 && y == n - 1){
        solution[x][y] = 1;
        printSolution(solution, n);
        solution[x][y] = 0;
        return;
    }
    
    //small calc
    //calculate possible positions
    if(x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || solution[x][y] == 1)
        return;
    
    solution[x][y] = 1;
    
    //rec call U, D, L, R
    mazeHelp(maze, n, solution, x-1, y);
    mazeHelp(maze, n, solution, x+1, y);
    mazeHelp(maze, n, solution, x, y - 1);
    mazeHelp(maze, n, solution, x, y + 1);
    
    //backtrack
    solution[x][y] = 0;
    
}
void ratInAMaze(int maze[][20], int n){
    
    //create a solution array
    int **solution = new int*[n];
    
    for(int i = 0; i < n; i++){
        solution[i] = new int[n];
    }
    
    //initialise this array
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            solution[i][j] = 0;
    }
    
    //call mazehelp
    mazeHelp(maze, n, solution, 0, 0);
}
int main() {

	// Write your code here
    int n;
    cin >> n;
    
    int maze[n][20];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> maze[i][j];
        }
    }
    
    ratInAMaze(maze, n);
	return 0;
}
