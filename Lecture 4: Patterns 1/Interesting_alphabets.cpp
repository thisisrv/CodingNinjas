#include<iostream>
using namespace std;


int main() {
    
    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
    int i = 1, n;
    
    cin >> n;
    
    while (i <= n){
        
        int j = 1;
        char startChar = 'A' + n - i ;
        while (j <= i){
            
            char ch = startChar + j - 1;
            cout << ch;
            j++;
        }
        cout << endl;
        i++;
    }
}

