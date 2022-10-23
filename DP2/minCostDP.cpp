//This is a proper backtracking rec problem 
//will convert it into dp
#include<iostream>
#include<climits>
using namespace std;

int minCostPathHelper(int **input, int m, int n, int x, int y, int **ans){
    //base case
    if(x == m - 1 && y == n - 1){
        return input[x][y];
    }

    //check if ans already exist;
    if(ans[x][y] != -1)
        return ans[x][y];
    
    //set boundaries
    if(x < 0 || x >= m || y < 0 || y >= n)
        return INT_MAX;
    
    //rec call
    int cost1 = minCostPathHelper(input, m, n, x + 1, y, ans);   //down
    int cost2 = minCostPathHelper(input, m, n, x, y + 1, ans);   //right
    int cost3 = minCostPathHelper(input, m, n, x + 1, y + 1, ans);   //diagonal

    //small calc
    return ans[x][y] = input[x][y] + min(cost1, min(cost2, cost3));
}

int minCostPath(int **input, int m, int n)
{
    int **ans = new int*[m + 1];
    for(int i = 0; i <= m; i++){
        ans[i] = new int[n + 1];
        for(int j = 0; j <= n; j++)
            ans[i][j] = -1;
    }

    //HELPER FN
    return minCostPathHelper(input, m, n, 0, 0, ans);
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