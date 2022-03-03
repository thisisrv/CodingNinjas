#include <iostream>

using namespace std;

int main()
{

    /*I/p: 5
    output:
    A
    AB
    ABC
    ABCD
    ABCDE

    Number of rows : n
    number of cols in ith row: i
    Value to be printed: 'A' + j - 1

    */
    int i = 1, n;

    cin >> n;

    while (i <= n){

        int j = 1;
        while (j <= i){
        char ch = 'A' + j - 1;
            cout << ch;
            j++;
        }

        cout << endl;
        i++;
    }

    return 0;
}