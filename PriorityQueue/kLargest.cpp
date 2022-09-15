#include<vector>
#include<queue>
#include<algorithm>

vector<int> kLargest(int input[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
	// Write your code here
    priority_queue<int, vector<int>, greater<int>> pq;
    
    //add first k elements in pq
    for(int i = 0; i < k; i++)
        pq.push(input[i]);
    
    //insert and pop elements from pq for remaining n-k terms
    for(int i = k; i < n; i++){
        
        if(input[i] > pq.top()){
            pq.pop();
            pq.push(input[i]);
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