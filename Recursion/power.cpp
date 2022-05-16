#include<iostream>
using namespace std;

int power(int x, int n){

    //Base case
    if(n == 0)
        return 1;

    //Rec call
    int small_ans = power(x, n - 1);

    //Small ans
    return x * small_ans;
}

int main(){

    int num, exp;

    cin >> num >> exp;

    cout << power(num, exp) << endl;
}