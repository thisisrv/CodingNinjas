#include<iostream>
using namespace std;

int factorial(int n){

    //Base case
    if(n == 0)
        return 1;

    //Rec call
    int small_output = factorial(n - 1);

    //Small calc
    return n * small_output;
}

int main(){

    cout << factorial(5) << endl;
}