#include<iostream>
using namespace std;

bool checkNumber(int input[], int size, int x) {

    //Base case
    if(size == 0)
        return false;

    //Small calc
    if(input[0] == x)
        return true;

    //Rec call
    bool ans = checkNumber(input + 1, size - 1, x);
    return ans;
}
int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int x;

    cin >> x;

    if(checkNumber(input, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}