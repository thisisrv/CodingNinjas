#include <iostream>

using namespace std;

int main()
{

    /*I/p: 4
    output:
    1111
    1111
    1111
    1111

    Number of rows : n
    number of cols in ith row: n
    Value to be printed: 1

    */
    int i = 1, n;

    cin >> n;

    while (i <= n){

        int j = 1;
        while (j <= n){
            cout << "1";
            j++;
        }

        cout << endl;
        i++;
    }

    return 0;
}