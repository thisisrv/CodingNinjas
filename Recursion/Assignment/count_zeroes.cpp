#include<iostream>
using namespace std;

int countzeroes(int n){

    //Base case
    if(n == 0)
        return 1;
    if(n / 10 == 0){

        //check value
        if(n % 10 == 0)
            return 1;
        else
            return 0;
    }
    //Rec call
    int zerocount = countzeroes(n / 10);

    if(n % 10 == 0)
        return 1 + zerocount;

    else
        return zerocount;
}

int main(){

    int n;
    cin >> n;

    cout << countzeroes(n);
}