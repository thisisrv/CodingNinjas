#include<unordered_map>
#include<string>
#include <iostream>
using namespace std;

string uniqueChar(string str) {
	// Write your code here
    string output = "";
    unordered_map<char, int> ourmap;
    for(int i = 0; i < str.length(); i++){
        
        char c = str[i];
        
        //check if c is present in map or not
        if(ourmap[c] > 0){
            continue;
        }
        
        output += c;
        ourmap[c]++;
    }

    return output;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}