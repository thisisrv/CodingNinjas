#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int *a, int size){

    vector<int> output;
    unordered_map<int, bool> seen;

    for(int i = 0; i < size; i++){

        //check element is already present
        if(seen.count(a[i]) > 0)
            continue;
        
        seen[a[i]] = true;
        output.push_back(a[i]);
    }

    return output;
}
int main(){

    int size;
    cin >> size;

    int *a = new int[size];

    for(int i = 0; i < size; i++)
        cin >> a[i];

    vector<int> output = removeDuplicates(a, size);

    for(int i = 0; i < output.size(); i++)
        cout << output[i] << " ";

    delete[] a;
}