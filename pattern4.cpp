#include <iostream>

using namespace std;

int main()
{

    /*I/p: 5
    output:
    abcde
    abcde
    abcde
    abcde

    Number of rows : n
    number of cols in ith row: n
    Value to be printed: 'A' + j - 1

    */
    int i = 1, n;

    cin >> n;

    while (i <= n){

        int j = 1;
        while (j <= n){
        char ch = 'a' + j - 1;
            cout << ch;
            j++;
        }

        cout << endl;
        i++;
    }

    return 0;
}