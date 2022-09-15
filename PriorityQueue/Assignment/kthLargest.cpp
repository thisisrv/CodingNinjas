#include<queue>
int kthLargest(int* arr, int n, int k) {
    // Write your code here
    //we can use minPQ for making TC ~ O[(n+k)logk] [ As n>>k; TC ~ O(n)]
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    //insert k elements
    for(int i = 0; i < k; i++)
        pq.push(arr[i]);
    
    //update for n-k elements
    for(int i = k; i < n; i++){
        
        if(arr[i] > pq.top()){
            pq.push(arr[i]);
            pq.pop();
        }
    }
          
    
    return pq.top();
}