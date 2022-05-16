#include<iostream>
using namespace std;

int count(int n){

    //Base case
    if(n / 10 == 0)
        return 1;

    //Rec call
    int small_ans = count(n / 10);

    //Small call
    return 1 + small_ans;
}

int main(){
    int n;
    cin >> n;

    cout << count(n) << endl;
}