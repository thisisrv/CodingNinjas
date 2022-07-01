#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;

    cout << "Size: " << v.size() << endl;  

    cout << v.capacity() << endl;

    v.pop_back();

    cout << v.at(2) << endl;
}