#include<iostream>
#include "hashMap.h"
using namespace std;

int main(){

    ourmap<int> map;

    for(int i = 0; i < 10; i++){
        string s = to_string(i);
        map.insert(s, i);
        cout << map.getLoadFactor() << endl;
    }

    for(int i = 0; i < 10; i++){
        string s = to_string(i);
        cout << s << " : " << map.getValue(s) << endl;
    }

    cout << map.size() << endl;
}