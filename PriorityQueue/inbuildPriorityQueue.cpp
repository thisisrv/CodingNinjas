#include<iostream>
#include<queue>
using namespace std;

int main(){

    priority_queue<int> pq;

    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(40);
    pq.push(100);

    cout << pq.size() << endl;
    cout << pq.top() << endl;
    
    while(pq.size() != 0){
        cout << pq.top() << " ";
        pq.pop();
    }
}