#include<cmath>
#include<iostream>
using namespace std;
int minCountHelper(int n, int *ans)
{
	//Write your code here
    //base case
    if(n == 0)
        return 0;
    
    if(ans[n] != -1)
        return ans[n];
    
    //small calc and rec call
    int small_ans = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(i == 1)
        	small_ans = minCountHelper(n - (i*i), ans);
        else{
            small_ans = min(small_ans, minCountHelper(n - (i*i), ans));
        }
    }
                        
    return ans[n] = small_ans + 1;
}

int minCount(int n){
    
    int *ans = new int[n + 1];
    
    for(int i = 0; i <= n; i++)
        ans[i] = -1;
    
    return minCountHelper(n, ans);
}

int main(){
    int n;
    cin >> n;
    cout << minCount(n) << endl;
}