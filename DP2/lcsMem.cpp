#include<iostream>
#include<cstring>
using namespace std;

int lcsMemHelper(string s, string t, int **ans){
    int m = s.length();
    int n = t.length();

    //base case
    if(s.length() == 0 || t.length() == 0)
        return 0;

    //check if answer already exists 
    if(ans[m][n] != -1)
        return ans[m][n];

    //small calc and rec call
    if(s[0] == t[0])
        return ans[m][n] = 1 + lcsMemHelper(s.substr(1), t.substr(1), ans);

    //when s[0] != t[0]
    int a = lcsMemHelper(s, t.substr(1), ans);     //case 1
    int b = lcsMemHelper(s.substr(1), t, ans);     //case 2
    int c = lcsMemHelper(s.substr(1), t.substr(1), ans);     //case 3

    return ans[m][n] = max(a, max(b, c));
}

int lcsMem(string s, string t){
    //calculate size
    int m = s.length();
    int n = t.length();

    int **ans = new int*[m + 1];
    for(int i = 0; i <= m; i ++){
        ans[i] = new int[n + 1];
        for(int j = 0; j <= n; j++)
            ans[i][j] = -1;
    }

    return lcsMemHelper(s, t, ans);
}
int main(){
    string s, t;
    cin >> s >> t;

    cout << lcsMem(s, t) << endl;
}