#include <iostream>
#include <string>
using namespace std;

string findWinner(int n, int x, int y)
{
	// Write your code here
    bool *ans = new bool[n + 1];
    
    //here true means A is picking and false means B is picking
    
    //A picks first
    ans[0] = false;     //No coin for A to pick
    ans[1] = true;      //A picks
    
    for(int i = 2; i <= n; i++){
        
        //check who picked last
        if(i - 1 >= 0 && ans[i - 1] == false)   //B picked last hence A will pick now
            ans[i] = true;
            
        if(i - x >= 0 && ans[i - x] == false)
            ans[i] = true;
            
        if(i - y >= 0 && ans[i - y] == false)
            ans[i] = true;

        else 
            ans[i] = false;
    }
    
    if(ans[n] == true)
        return "Beerus";
    
    return "Whis";
}
int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}