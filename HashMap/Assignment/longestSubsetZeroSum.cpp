#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    
    //using hashmap to store sum till i and i as key-value pairs
    unordered_map<int, int> ourmap;
    int max_length = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        
        sum = sum + arr[i];
        
        //if array element is 0 and max_length is 0
        if(arr[i] == 0 && max_length == 0)
            max_length = 1;
        
        if(sum == 0)
            max_length = i + 1;
        
        //Now the base concept check is sum value is already present in map;
        if(ourmap.find(sum) != ourmap.end()){
            
            //calculate length
            int length = i - ourmap[sum];
            
            if(length > max_length)
                max_length = length;
        }
        
        else//if sum is not present add sum and index
            ourmap[sum] = i;
    }
    
    return max_length;
}