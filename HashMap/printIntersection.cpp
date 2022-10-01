#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    
    unordered_map<int, int> ourmap;
    
    //add contents of arr 1 in it
    for(int i = 0; i < n; i++)
        ourmap[arr1[i]] ++;
    
    //finding common contents
    for(int i = 0; i < m; i++){
        
        if(ourmap.count(arr2[i]) > 0 && ourmap[arr2[i]] > 0){
            cout <<  arr2[i] << endl;
            ourmap[arr2[i]]--;
        }
    }
}