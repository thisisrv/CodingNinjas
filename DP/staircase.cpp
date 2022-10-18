#include<bits/stdc++.h>
using namespace std;

long long stairCaseDPHelper(int n, long long *ans){
    //base case
    if(n == 1 || n == 0)
        return 1;
    
    if(n < 0)
        return 0;

    //check if ans is available
    if(ans[n] != -1)
        return ans[n];

    //rec call
    long long x = stairCaseDPHelper(n - 1, ans);
    long long y = stairCaseDPHelper(n - 2, ans);
    long long z = stairCaseDPHelper(n - 3, ans);
    
    return ans[n] = (x + y + z)%(1000000000 + 7);
}

long long stairCaseDP(int n){
    long long *ans = new long long[n + 1];

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