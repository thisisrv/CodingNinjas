bool isMaxHeap(int arr[], int n) {
    // Write your code here
    //we need to take out parent index and compare parnet value with child value
    //start from 1 as 0 has no parent
    for(int i = 1; i < n; i++){
        
        int child_index = i;
        int parent_index = (child_index - 1) / 2;
        
        if(arr[parent_index] < arr[child_index])
            return false;
    }
    
    return true;
}