#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

    for(int i = 0; i < n; i++){
        
        //insert
        if(max.size() == 0 && min.size() == 0)
            max.push(arr[i]);
        
        //insert in min
        else if(arr[i] > max.top()){
            min.push(arr[i]);

            //rearrage if size diff is > 1
            if(min.size() - max.size() > 1){
                max.push(min.top());
                min.pop();
            }
        }

        else{
            //add in max
            max.push(arr[i]);

            //rearrange if size diff is > 1
            if(max.size() - min.size() > 1){
                min.push(max.top());
                max.pop();
            }
        }

        //display median
        if(min.size() == 0 || max.size() > min.size())
            cout << max.top() << " ";

        if(max.size() == 0 || min.size() > max.size())
            cout << min.top() << " ";

        if(max.size() == min.size())
            cout << (max.top() + min.top()) / 2 << " ";
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
