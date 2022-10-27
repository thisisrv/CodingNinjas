int knapsackHelper(int *weights, int *values, int n, int maxWeight, int **ans)
{
	//write your code here
    //base case
    if(n == 0 || maxWeight == 0)
        return 0;
    
    //check if ans already present
    if(ans[n][maxWeight] != -1)
        return ans[n][maxWeight];

    //small calc and rec call
    if(weights[0] <= maxWeight){
        //include values[0];
        int x = values[0] + knapsackHelper(weights + 1, values + 1, n - 1, maxWeight - weights[0], ans);
        
        //not included
        int y = knapsackHelper(weights + 1, values + 1, n - 1, maxWeight, ans);
        return ans[n][maxWeight] = max(x, y);
    }
    
    return ans[n][maxWeight] = knapsackHelper(weights + 1, values + 1, n - 1, maxWeight, ans);
}

int knapsack(int *weights, int *values, int n, int maxWeight){

    int **ans = new int*[n + 1];
    for(int i = 0; i <= n; i++){
        ans[i] = new int[maxWeight + 1];
        for(int j = 0; j <= maxWeight; j++)
            ans[i][j] = -1;
    }

    return knapsackHelper(weights, values, n, maxWeight, ans);
}