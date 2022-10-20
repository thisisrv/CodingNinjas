#include<iostream>
using namespace std;

int balancedBTHelper(int n, int *ans){
    //base case
    if(n <= 1)  
        return 1;

    //check if alrady present
    if(ans[n] != -1)
        return ans[n];

    //rec call
    int x = balancedBTHelper(n - 1, ans);
    int y = balancedBTHelper(n - 2, ans);

    //important small calc
    return ans[n] = x*x + 2*x*y;
}

int balancedBT(int n){
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++)
        ans[i] = -1;

    balancedBTHelper(n, ans);
}
int main(){
    int n;
    cin >> n;

    cout << balancedBT(n) << endl;
}