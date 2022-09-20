#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main(){

    unordered_map<string, int> ourmap;

    //insertion
    //method 1
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    
    //method 2
    ourmap["def"] = 2;

    //Access elements
    cout << ourmap["abc"] << endl;      //Risky
    cout << ourmap.at("def") << endl;
    // cout << ourmap["ghi"] << endl;

    //check presence
    if(ourmap.count("ghi") > 0)
        cout << "ghi is present" << endl;

    //erase element
    ourmap.erase("abc");

    cout << ourmap.at("abc") << endl;
}