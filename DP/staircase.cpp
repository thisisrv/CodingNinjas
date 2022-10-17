#include<bits/stdc++.h>
using namespace std;

int stairCase(int n){
    //rec
    //base case
    if(n == 1 || n == 0)
        return 1;

    if(n < 0) 
        return 0;

    int x = stairCase(n - 1);
    int y = stairCase(n - 2);
    int z = stairCase(n - 3);
    
    return x + y + z;
}

int stairCaseDPHelper(int n, int *ans){
    //base case
    if(n == 1 || n == 0)
        return 1;
    
    if(n < 0)
        return 0;

    //check if ans is available
    if(ans[n] != -1)
        return ans[n];

    //rec call
    int x = stairCaseDPHelper(n - 1, ans);
    int y = stairCaseDPHelper(n - 2, ans);
    int z = stairCaseDPHelper(n - 3, ans);
    
    ans[n] = x + y + z;
    return ans[n];
}

int stairCaseDP(int n){
    int *ans = new int[n + 1];

    for(int i = 0; i <= n; i++)
        ans[i] = -1;

    return stairCaseDPHelper(n, ans);
}
int main(){
    
    // write your code here
    int t;
    cin >> t;

    while(t > 0){
        int n;
        cin >> n;
        cout << stairCaseDP(n) << endl;
        t--;
    }
    return 0;
}