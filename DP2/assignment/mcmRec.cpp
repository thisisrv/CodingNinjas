#include <iostream>
#include<climits>
using namespace std;

int mcmHelper(int *arr, int s, int e){
    //base case
    //array is empty
    if(e - s <= 1)
        return 0;

    int ans = INT_MAX;
    for(int k = s + 1; k <= e - 1; k++){
        int minOperations_a = mcmHelper(arr, s, k);
        int minOperations_b = mcmHelper(arr, k, e);
        int total_operations = minOperations_a + minOperations_b + (arr[s] * arr[k] * arr[e]);
        ans = min(ans, total_operations);
    }
    
    //small calc
    return ans;
}


int matrixChainMultiplication(int* arr, int n) {
    //need helper fn
    return mcmHelper(arr, 0, n);
}


int main() {
    int n;
    cin >> n;
    int* arr = new int[n + 1];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}