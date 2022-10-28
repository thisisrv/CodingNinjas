/*
Problem Statement
There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is h[i].
​
There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:

If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. Here, a cost of ∣ h[i] − h[j]∣  is incurred, where j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone N.

Constraints
All values in input are integers.
2≤N≤10 
1 ≤ h[i] ≤ 10^4
*/

#include <iostream>
#include <cmath>
using namespace std;

int frogHelper(int *height, int n, int *ans){
    //base case
    if(n < 2)
        return 0;
        
    if(n == 2)
        return abs(height[0] - height[1]);
    
    //check if ans exists
    if(ans[n] != -1)
        return ans[n];
        
    //rec call
    int min_cost_a = frogHelper(height + 1, n - 1, ans);
    int x = abs(height[0] - height[1]) + min_cost_a;
    
    int min_cost_b = frogHelper(height + 2, n - 2, ans);
    int y = abs(height[0] - height[2]) + min_cost_b;
    
    return ans[n] = min(x, y);
}

int frog(int *height, int n){
    
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++)
        ans[i] = -1;
    
    return frogHelper(height, n, ans);
}


int main()
{
    int n;
    cin >> n;
    
    int *height = new int[n];
    
    for(int i= 0; i < n; i++)
        cin >> height[i];
        
    cout << frog(height, n) << endl;

    return 0;
}
