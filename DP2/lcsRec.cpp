#include<iostream>
#include<cstring>
using namespace std;

int lcsRec(string s, string t){
    //base case
    if(s.length() == 0 || t.length() == 0)
        return 0;

    //small calc and rec call
    if(s[0] == t[0])
        return 1 + lcsRec(s.substr(1), t.substr(1));

    //when s[0] != t[0]
    int a = lcsRec(s, t.substr(1));     //case 1
    int b = lcsRec(s.substr(1), t);     //case 2
    int c = lcsRec(s.substr(1), t.substr(1));     //case 3
    return max(a, max(b, c));
}
int main(){
    string s, t;
    cin >> s >> t;

    cout << lcsRec(s, t) << endl;
}