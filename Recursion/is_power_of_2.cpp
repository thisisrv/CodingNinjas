#include<iostream>
using namespace std;

bool ispoweroftwo(int x){

    //Base case
    if(x == 0 || x == 1)
        return true;

    //Small calc
    if(x % 2 == 0){
        bool ans = ispoweroftwo(x / 2);
        return ans;
    }

    else
        return false;
}

int main(){

    int num;

    cin >> num;

    cout << ispoweroftwo(num) << endl;
}