#include<unordered_map>
int pairSum(int *arr, int n) {
	unordered_map<int,int> pq;
    int count=0;
    
    for(int i=0;i<n;i++){
// 	if -arr[i] is present then increment count
        
        if(pq[arr[i]*-1]>0){
            count +=pq[arr[i]*-1];
        }
        
        pq[arr[i]]++;
    }
    return count;
}