#include <iostream>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    //base case
    if(value == 0)
        return 1;       //there is 1 way to make value 0 i.e to not include anything

    if(numDenominations == 0 || value < 0)
        return 0;       // if there are 0 types of coins and value > 0 then there is no way to make the value

    //rec call
    //include denominations[0]
    int x = countWaysToMakeChange(denominations, numDenominations, value - denominations[0]);
    int y = countWaysToMakeChange(denominations + 1, numDenominations - 1, value);      //exclude denominetion[0] type of coin

    //small calc
    return x + y;
}

int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}