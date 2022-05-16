#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {

    //Base case
    if(size == 0)
        return -1;

    //rec call
    int index = lastIndex(input + 1, size - 1, x);

    if(index == -1){

        //check at 0th index
        if(input[0] == x)
            return 0;
        else
            return index;
    }

    else
        return 1 + index;

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

    cout << lastIndex(input, n, x) << endl;

}