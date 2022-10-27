#include<iostream>
using namespace std;

int editDistance(string s, string t){
    //base case
    if(s.length() == 0 && t.length()){
        return 0;
    }

    if(s.length() == 0)
        return t.length();
    
    if(t.size() == 0)
        return s.length();

    //small calc
    if(s[0] == t[0])
        return editDistance(s.substr(1), t.substr(1));
    
    //if s[0] != t[0]
    //3 actions insert, delete and replace
    int x = 1 + editDistance(s.substr(1), t);
    int y = 1 + editDistance(s, t.substr(1));
    int z = 1 + editDistance(s.substr(1), t.substr(1));

    return min(x, min(y, z));
}
int main(){
    string s, t;
    cin >> s >> t;

    cout << editDistance(s, t) << endl;
}