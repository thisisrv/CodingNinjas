#include<iostream>
#include<queue>
using namespace std;

void kSortedArray(int input[], int n, int k){
    //make pq and insert first k elements in it
    priority_queue<int> pq;

    for(int i = 0; i < k; i++)
        pq.push(input[i]);

    //pop and top and insert top value in input array
    int j = 0;
    for(int i = k; i < n; i++){
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    } 

    //insert remaining elements
    while(pq.size() != 0){
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}
int main(){

    int input[5] = {12,7,5,9,4};
    kSortedArray(input, 5, 3);

    for(int i = 0; i < 5; i++)
        cout << input[i] << " ";

}