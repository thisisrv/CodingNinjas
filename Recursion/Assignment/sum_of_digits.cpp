#include<iostream>
using namespace std;

int sumDigits(int n){
    //Base case
    if(n / 10 == 0)
        return n;

    //Rec call
    int small_sum = sumDigits(n / 10);

    //small calc
    return (n % 10) + small_sum;
}
int main(){

    int n;
    cin >> n;

    cout << sumDigits(n) << endl;
}