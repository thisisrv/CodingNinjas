#include<bits/stdc++.h>
using namespace std;

//Here we will make a choice to add or not input[0]
int countSubsetSum(int* input, int n, int sum){
    //base case
    if(n == 0 && sum == 0)
        return 1;
    if(n == 0)
        return 0;
    
    //small calc and rec call OR choice
    //include input[0];
    int count_included = countSubsetSum(input + 1, n - 1, sum - input[0]);
    //Dont include input[0];
    int count_excluded = countSubsetSum(input + 1, n - 1, sum);
    
    return count_included + count_excluded;
}

int main(){
    
    // write your code here
    int t, n, target;
    cin >> t;
    
    while(t > 0){
        
    cin >> n >> target;
    
    int input[n];
    for(int i = 0; i < n; i++)
        cin >> input[i];
    
    cout << countSubsetSum(input, n, target) << endl;
    t--;
    }
    return 0;
}