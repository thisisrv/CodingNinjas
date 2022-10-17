#include<iostream>
using namespace std;

int fibo_Helper(int n, int *ans){
    //base case
    if(n <= 1)
        return n;

    //check if ans is already present
    if(ans[n] != -1)
        return ans[n];

    //find ans and store
    int a = fibo_Helper(n - 1, ans);
    int b = fibo_Helper(n - 2, ans);

    //store ans
    ans[n] = a + b;

    return ans[n];
}
//This method is memoization method
int fibo(int n){
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++)
        ans[i] = -1;

    return fibo_Helper(n, ans);
}
int main(){
    int n;
    cin >> n;

    cout << fibo(n);
}