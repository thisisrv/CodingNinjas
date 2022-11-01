int maxMoneyLootedHelper(int *arr, int n, int *ans)
{
	//base case
    if(n <= 0)
        return 0;
    
    //like knapsack include or not include
    //check if ans alreday exists
    if(ans[n] != -1)
        return ans[n];
    // include arr[0];
    int x = arr[0] + maxMoneyLootedHelper(arr + 2, n - 2, ans);
    
    //not include
    int y = maxMoneyLootedHelper(arr + 1, n - 1, ans);
    
    return ans[n] = max(x, y);
}

int maxMoneyLooted(int *arr, int n){
    int *ans = new int[n + 1];
    
    for(int i = 0; i <= n; i++){
        ans[i] = -1;
    }
    
    return maxMoneyLootedHelper(arr, n, ans);
}