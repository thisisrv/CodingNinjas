#include <iostream>

using namespace std;

int main()
{

    /*I/p: 4
    output:
    ****
    ****
    ****
    ****

    Number of rows : n
    number of cols in ith row: n
    Value to be printed: *

    */
    int i = 1, n;

    cin >> n;

    while (i <= n){

        int j = 1;
        while (j <= n){
            cout << "*";
            j++;
        }

        cout << endl;
        i++;
    }

    return 0;
}