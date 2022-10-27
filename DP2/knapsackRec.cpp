int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
    //base case
    if(n == 0 || maxWeight == 0)
        return 0;
    
    //small calc and rec call
    if(weights[0] <= maxWeight){
        //include values[0];
        int x = values[0] + knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]);
        
        //not included
        int y = knapsack(weights + 1, values + 1, n - 1, maxWeight);
        return max(x, y);
    }
    
    return knapsack(weights + 1, values + 1, n - 1, maxWeight);;
}