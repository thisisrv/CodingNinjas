#include<iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {

    //base case
    if(size == 0)
        return 0;

    //rec call
    int small_size = allIndexes(input + 1, size - 1, x, output);

    if(input[0] == x){

        //Shift elements by right and add 1 and add 0 to 0th position
        for(int i = small_size - 1; i >= 0; i--)
            output[i + 1] = output[i] + 1;
        output[0] = 0;
        small_size++;
    }

    else{

        //only add 1 to elements;
        for(int i = 0; i < small_size; i++)
            output[i] = output[i] + 1;
    }

    return small_size;
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

    int *output = new int[n];

    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    delete [] input;

    delete [] output;


}