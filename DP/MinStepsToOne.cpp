#include<iostream>
using namespace std;

int countMinStepsToOne(int n)
{
	//Write your code here
    //base case
    if(n == 1)
        return 0;
    
    int ans = countMinStepsToOne(n - 1);
    
    //small calc and rec call
    if(n % 3 == 0)
        ans = min(ans, countMinStepsToOne(n / 3));
    
    if(n % 2 == 0)
        ans = min(ans, countMinStepsToOne(n / 2));
    
    return 1 + ans;
}

int countMinStepsToOneDPHelper(int n, int *ans){
    //base case
    if(n == 1)
        return 0;
    
    //check if already present
    if(ans[n] != -1){
        return ans[n];
    }
    
    int res = countMinStepsToOneDPHelper(n - 1, ans);
    
    //small calc and rec call
    if(n % 3 == 0){
         res = min(res, countMinStepsToOneDPHelper(n / 3, ans));
    }
    
    if(n % 2 == 0){
        res = min(res, countMinStepsToOneDPHelper(n / 2, ans));
    }
    
    ans[n] = 1 + res;
    return ans[n];
}

int countMinStepsToOneDP(int n){
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++)
        ans[i] = -1;

    return countMinStepsToOneDPHelper(n, ans);
}
int main(){
    int n;
    cin >> n;

    // cout << countMinStepsToOne(n) << endl;
    cout << countMinStepsToOneDP(n) << endl;
}