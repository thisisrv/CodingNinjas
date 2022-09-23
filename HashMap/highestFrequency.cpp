#include<iostream>
#include<unordered_map>

using namespace std;

int highestFrequency(int arr[], int n) {
        // Insert all elements in hash.
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;
 
    // find the max frequency
    int max_freq = 0;
    
    //Find max freq
    unordered_map<int, int> :: iterator it = hash.begin();
    
    while(it != hash.end()){
        
        if(it -> second > max_freq)
            max_freq = it -> second;
        
        it++;
    }
    
    // cout << max_freq << endl;
    //match values of arr[i] with freq
    for(int i = 0; i < n; i++){
        if(hash[arr[i]] == max_freq)
            return arr[i];
    }

    return 0;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}