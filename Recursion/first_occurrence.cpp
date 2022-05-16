#include<iostream>
using namespace std;

int firstIndex(int input[], int size, int x) {

    //Base case
    if(size == 0)
        return -1;

    //small calc
    if(input[0] == x)
        return 0;

    int index = firstIndex(input + 1, size - 1, x);

    if(index == -1)
        return index;
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

    cout << firstIndex(input, n, x) << endl;

}