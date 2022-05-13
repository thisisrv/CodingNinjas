int findUnique(int *arr, int n) {
    // Write your code here
    int element  = 0;

    for(int i = 0; i < n; i++){

        element = element ^ arr[i];
    }

    return element;
}