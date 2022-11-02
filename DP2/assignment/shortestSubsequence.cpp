#include<iostream>
#include<string>
#include<climits>
using namespace std;

int solve(string s, string t){
    int m = s.length();
    int n = t.length();

    //base case
    if(m == 0)
        return 10000;   //contraints

    if(n == 0)
        return 1;

    int i;
    for(i = 0; i < n; i++){
        if(s[0] == t[i]){
            break;
        }
    }
    //if first character of string s is not present in t, return 1 as min uncommon subsequence length
    if(i == n)
        return 1;

    
    //rec call and small calc
    int x = solve(s.substr(1), t);      //Not include the first character
    int y = 1 + solve(s.substr(1), t.substr(i + 1));    //include the first character
    return min(x, y);
}
int main(){
    string s, t;
    cin >> s >> t;

    cout << solve(s, t) << endl;
}