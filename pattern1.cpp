#include <iostream>

using namespace std;

int main()
{

    /*I/p: 4
    output:
    1
    12
    123
    1234

    Number of rows : n
    number of cols in ith row: i
    Value to be printed: j

    */
    int i = 1, n;

    cin >> n;

    while (i <= n){

        int j = 1;
        while (j <= i){
            cout << j;
            j++;
        }

        cout << endl;
        i++;
    }

    return 0;
}
