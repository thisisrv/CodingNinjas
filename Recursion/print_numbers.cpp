#include<iostream>
using namespace std;

void print(int n){

    //Base case
    if(n == 0)
        return;

    //Small call
    print(n - 1);

    //small calc
    cout << n << " ";
}

int main(){
    int n;
    cin >> n;

    print(n);
}