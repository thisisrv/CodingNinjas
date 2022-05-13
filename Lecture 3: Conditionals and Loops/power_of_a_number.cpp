#include<iostream>
using namespace std;

int main() {
	// Write your code here
	/*Input : x n
      Output: Number*/
    
    int number, power;
    
    cin >> number >> power;
    
    if (number == 0 && power == 0)
        cout << "1";
    
    else{
        
        int product = 1;
        
        while ( power != 0){
            
            product = product * number;
            
            power = power - 1;
        }
        
        cout << product;
    }
     
}

