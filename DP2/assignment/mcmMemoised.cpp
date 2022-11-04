#include <iostream>
#include<climits>
using namespace std;

int mcmHelper(int *arr, int s, int e, int **output){
    //base case
    //array is empty
    if(e - s <= 1)
        return 0;

    //check if output already present
    if(output[s][e] != -1)  
        return output[s][e];

    int ans = INT_MAX;
    for(int k = s + 1; k <= e - 1; k++){
        int minOperations_a = mcmHelper(arr, s, k, output);
        int minOperations_b = mcmHelper(arr, k, e, output);
        int total_operations = minOperations_a + minOperations_b + (arr[s] * arr[k] * arr[e]);
        ans = min(ans, total_operations);
    }
    
    //small calc
    return output[s][e] = ans;
}


int matrixChainMultiplication(int* arr, int n) {
    //need helper fn
    int **output = new int*[n + 1];
    for(int i = 0; i <= n; i++){
        output[i] = new int[n + 1];
        for(int j = 0; j <= n; j++)
            output[i][j] = -1;
    } 
    return mcmHelper(arr, 0, n, output);
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