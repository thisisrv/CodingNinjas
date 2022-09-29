#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    //make a map
    unordered_map<int, bool> ourmap;

    //add in map
    for(int i = 0; i < n; i++)
        ourmap[arr[i]] = true;

    //make max_length
    int max_length = 0;
    int start_value = 0;
    int end_value = 0;

    for(int i = 0; i < n; i++){

        //check if arr[i] is the starting point of any sequence, we can use find() fn
        if(ourmap.find(arr[i] - 1) == ourmap.end()){
            //means for arr[i], arr[i] - 1 is not present

            int value = arr[i];
            while(ourmap.find(value) != ourmap.end())
                value++;

            //update max length and start value
            if(value - arr[i] > max_length){
                max_length = value - arr[i];
                start_value = arr[i];
                end_value = start_value + max_length - 1;
            }
        }
    }

    vector<int> output;
    output.push_back(start_value);
    output.push_back(end_value);
    return output;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}