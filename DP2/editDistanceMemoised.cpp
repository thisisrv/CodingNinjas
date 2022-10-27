int editDistanceHelper(string s1, string s2, int **ans) {
	// Write your code here
	int m = s1.length();
	int n = s2.length();
	
    //base case
    if(s1.length() == 0 && s2.length() == 0){
        return 0;
    }

    if(s1.length() == 0)
        return s2.length();
    
    if(s2.size() == 0)
        return s1.length();
    
    //check if ans already exists
    if(ans[m][n] != -1)
        return ans[m][n];

    //small calc
    if(s1[0] == s2[0])
        return ans[m][n] = editDistanceHelper(s1.substr(1), s2.substr(1), ans);
    
    //if s[0] != t[0]
    //3 actions insert, delete and replace
    int x = 1 + editDistanceHelper(s1.substr(1), s2, ans);
    int y = 1 + editDistanceHelper(s1, s2.substr(1), ans);
    int z = 1 + editDistanceHelper(s1.substr(1), s2.substr(1), ans);

    return ans[m][n] = min(x, min(y, z));
}
int editDistance(string s, string t){
    int m = s.length();
    int n = t.length();
    
    int **ans = new int*[m + 1];
    for(int i = 0; i <= m; i++){
        ans[i] = new int[n + 1];
        for(int j = 0; j <= n; j++)
            ans[i][j] = -1;
    }
    
    //helper fn 
    return editDistanceHelper(s, t, ans);
}