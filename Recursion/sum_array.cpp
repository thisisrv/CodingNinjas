#include<iostream>
using namespace std;

int sum(int input[], int n){

    //Base case
    if(n == 0)
        return 0;

    //Rec call
    int small_ans = sum(input + 1, n - 1);

    //Small calc
    return input[0] + small_ans;
}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    cout << sum(input, n) << endl;
}