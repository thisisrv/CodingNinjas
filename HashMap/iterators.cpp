#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main(){

    unordered_map<string, int> ourmap;

    ourmap["abc"] = 0;
    ourmap["abc1"] = 1;
    ourmap["abc2"] = 1;
    ourmap["abc3"] = 1;
    ourmap["abc4"] = 1;
    ourmap["abc5"] = 1;

    //iterators
    unordered_map<string, int> :: iterator it = ourmap.begin();

    while(it != ourmap.end()){
        cout << "Key: " << it -> first << "Value: " << it -> second << endl;
        it++;
    }
}