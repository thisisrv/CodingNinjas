//This is a proper backtracking rec problem 
//will convert it into dp
#include<iostream>
#include<climits>
using namespace std;

int minCostPathHelper(int **input, int m, int n, int x, int y){
    //base case
    if(x == m - 1 && y == n - 1){
        return input[x][y];
    }

    //set boundaries
    if(x < 0 || x >= m || y < 0 || y >= n)
        return INT_MAX;
    
    //rec call
    int cost1 = minCostPathHelper(input, m, n, x + 1, y);   //down
    int cost2 = minCostPathHelper(input, m, n, x, y + 1);   //right
    int cost3 = minCostPathHelper(input, m, n, x + 1, y + 1);   //diagonal

    //small calc
    return input[x][y] + min(cost1, min(cost2, cost3));
}

int minCostPath(int **input, int m, int n)
{
    //HELPER FN
    return minCostPathHelper(input, m, n, 0, 0);
}

int main(){
    int m, n;
    cin >> m >> n;

    int **input = new int*[m];
    for(int i = 0; i < m; i++){
        input[i] = new int[n];
        //take input
        for(int j = 0; j < n; j++)
            cin >> input[i][j];
    }

    cout << minCostPath(input, m, n) << endl;
}