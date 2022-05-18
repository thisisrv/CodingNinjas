#include<iostream>
using namespace std;

bool isSorted(int input[], int size){

    //Base case array empty and 1 size
    if(size == 0 || size == 1)
        return true;

    //Rec call
    bool small_ans = isSorted(input + 1, size - 1);

    if(small_ans){
        //Check first two elements
        if(input[0] <= input[1])
            return true;
        else
            return false;
    }
    else
        return small_ans;
}

int main(){

    //Create array
    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << isSorted(arr, n) ;

    delete arr;
}