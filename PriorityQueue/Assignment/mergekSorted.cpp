#include<queue>
#include<vector>
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    //using min heap and add all vectors in min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < input.size(); i++){
        
        for(int j = 0; j < input[i] -> size(); j++)
            	pq.push(input[i]->at(j));
    }
    
    
    //pop and store top in output vector;
    vector<int> output;
    
    while(pq.size()!= 0){
        output.push_back(pq.top());
        pq.pop();
    }
    
    return output;
}