// same frog question but calls K

#include <iostream>
#include <cmath>
#include<climits>
using namespace std;

int frogHelper(int *height, int n, int k, int *ans){
    //base case
    if(n < 2)
        return 0;
        
    if(n == 2)
        return abs(height[0] - height[1]);
    
    //check if ans exists
    if(ans[n] != -1)
        return ans[n];
    
    int cost = INT_MAX;
    for(int i = 1; i <= k; i++){
        int small_ans = height[0] + frogHelper(height + i, n - i, k, ans);
        cost = min(cost, small_ans);
    }
    return ans[n] = cost;
}

int frog(int *height, int n, int k){
    
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++)
        ans[i] = -1;
    
    return frogHelper(height, n, k, ans);
    
}


int main()
{
    int n, k;
    cin >> n >> k;
    
    int *height = new int[n];
    
    for(int i= 0; i < n; i++)
        cin >> height[i];
        
    cout << frog(height, n, k) << endl;

    return 0;
}