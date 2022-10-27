//This is a proper backtracking rec problem 
//will convert it into dp
#include<iostream>
#include<climits>
using namespace std;

int min_cost = INT_MAX;

void minCostHelper(int **input, int m, int n, int **path, int x, int y, int sum){
    //base case
    if(x == m - 1 && y == n - 1){
        sum += input[x][y];
        min_cost = min(min_cost, sum);
        return;
    }

    //explore all paths and find correct position
    if(x < 0 || x >= m || y < 0 || y >= n || path[x][y] == 1)
        return;

    path[x][y] = 1;
    sum += input[x][y];

    //move to smaller problem OR rec call
    minCostHelper(input, m, n, path, x + 1, y, sum);    //Down
    minCostHelper(input, m, n, path, x, y + 1, sum);    //Right
    minCostHelper(input, m, n, path, x + 1, y + 1, sum);    //Diagonal

    //backtrack
    sum -= input[x][y];
    path[x][y] = 0;

    return;
}
int minCost(int **input, int m, int n){
    //create path array
    int **path = new int*[m];
    for(int i = 0; i < m; i++){
        path[i] = new int[n];
        //initialise to 0
        for(int j = 0; j < n; j++)
            path[i][j] = 0;
    }

    minCostHelper(input, m, n, path, 0, 0, 0);
    return min_cost;
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

    cout << minCost(input, m, n) << endl;
}