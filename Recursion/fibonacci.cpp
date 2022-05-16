//Fing nth fibonacci number
// 1st is 1, 2nd is 1, 3rd is 2
#include<iostream>
using namespace std;

int fib(int n){
    //base case
    if(n == 0)
        return 0;

    if(n == 1)
        return 1;

    //rec call
    int first_number = fib(n - 1);
    int second_number = fib(n - 2);

    //Small calc
    return first_number + second_number;
}

int main(){

    int n;
    cin >> n;

    cout << fib(n) << endl;
}