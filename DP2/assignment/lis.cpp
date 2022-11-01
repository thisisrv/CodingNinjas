#include <iostream>
using namespace std;

int longestIncreasingSubsequence(int *arr, int n){
    //make LIS arr
    int *LIS = new int[n];

    //Initialise lis of arr[0] as 1
    LIS[0] = 1;

    for(int i = 1; i < n; i++){
        //initialise LIS of arr[i] as 1 initially
        LIS[i] = 1;

        //loop backwards to compare LIS
        for(int j = i - 1; j >= 0; j--){
            if(arr[j] >= arr[i])
                continue;

            int possibleLIS = LIS[j] + 1;
            if(possibleLIS > LIS[i])
                LIS[i] = possibleLIS;
        }
    }

    //get max lis from lis array
    int bestLIS = 0;
    for(int i = 0; i < n; i++){
        if(bestLIS < LIS[i])
            bestLIS = LIS[i];
    }

    return bestLIS;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n) << endl;
}