int solveHelper(string s, string t, int **ans) {
    // Write your code here
    int m = s.length();
    int n = t.length();

    //base case
    if(m == 0)
        return 1000;

    if(n == 0)
        return 1;
    //check if ans exists
    if(ans[m][n] != -1)
        return ans[m][n];

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
    int x = solveHelper(s.substr(1), t, ans);      //Not include the first character
    int y = 1 + solveHelper(s.substr(1), t.substr(i + 1), ans);    //include the first character
    return ans[m][n] = min(x, y);
}

int solve(string s, string t){
    int m = s.length();
    int n = t.length();

    int **ans = new int*[m + 1];
    for(int i = 0; i <= m; i++){
        ans[i] = new int[n + 1];
        for(int j = 0; j <= n; j++)
            ans[i][j] = -1;
    }

    return solveHelper(s, t, ans);
}