#include<iostream>
using namespace std;

int main() {
	// Write your code here
	/* Input : Number
       Output: Sum_Even Sum_Odd
    */
    
    int number;
    cin >> number;
    
    int sum_even = 0, sum_odd = 0;
    
    while (number > 0){
        
        int remainder = number % 10;
        
        if (remainder % 2 == 0)
            sum_even = sum_even + remainder;
        
        else
            sum_odd = sum_odd + remainder;
    
        number = number / 10;
    }
    
    cout << sum_even << " " << sum_odd;
}

