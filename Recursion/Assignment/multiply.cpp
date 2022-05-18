#include<iostream>
using namespace std;

int multiply(int a, int b){

    if (b == 1)
        return a;

    //Rec call
    int small_ans = multiply(a, b - 1);

    //small calc
    return a + small_ans;
}

int main(){

    int a,b;
    cin >> a >> b;

    cout << multiply(a, b) << endl;
}