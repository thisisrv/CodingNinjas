#include<queue>
vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    priority_queue<int> pq;
    
    //add first k elements in pq
    for(int i = 0; i < k; i++)
        pq.push(arr[i]);
    
    //insert and pop elements from pq for remaining n-k terms
    for(int i = k; i < n; i++){
        
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    //fill output array with min values in pq
    vector<int> output;
    while(pq.size() != 0){
        output.push_back(pq.top());
        pq.pop();
    }
    
    reverse(output.begin(), output.end());
    return output;
}