#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int buyTicket(int *arr, int n, int k) {
    // Write your code here
    //make a queue and max pq
    queue<int> q;
    priority_queue<int> pq;

    //add indexes of arr in q and elements in pq
    for(int i = 0; i < n; i++){
        q.push(i);
        pq.push(arr[i]);
    }

    int time = 0;
    while(q.size() != 0){

        //if first element has the highest priority
        if(arr[q.front()] == pq.top()){
            //increment time and pop both q and pq
            time++;

            if(q.front() == k)
                break;
            
            q.pop();
            pq.pop();
        }

        //if elements priority is less than highest priority, pop and push at back
        if(arr[q.front()] < pq.top()){
            q.push(q.front());
            q.pop();
        }
    }

    return time;
}


int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}