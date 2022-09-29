#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
	
    unordered_map<int, int> ourmap;
    int pairs = 0;
    for(int i = 0; i < n; i++){
        //check if arr[i] + k and arr[i] - k [k!=0] is present in map
        if(ourmap.find(arr[i] + k) != ourmap.end())
            pairs += ourmap[arr[i] + k];
        
        if(k != 0 && ourmap.find(arr[i] - k) != ourmap.end())
            pairs += ourmap[arr[i] - k];
        
        ourmap[arr[i]]++;
    }
    
    return pairs;
}