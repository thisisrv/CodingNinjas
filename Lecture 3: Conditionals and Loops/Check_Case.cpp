#include<iostream>
using namespace std;

int main() {
	// Write your code here
    char c;
    cout<<"enter a char:";
    cin >> c;
    
    if (int(c) >= 97 && int(c) <= 122)
        cout << "0";
    
    else if(int(c) >= 65 && int(c) <= 90)
        cout << "1";
    
    else
        cout << "-1";
    
    return 0;
	
}

