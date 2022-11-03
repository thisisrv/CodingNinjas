#include <iostream>
using namespace std;

int countWaysToMakeChangeHelper(int denominations[], int numDenominations, int value, int **ans){
	//Write your code here
	//base case
	if(value == 0)
		return 1;

	if(numDenominations == 0 || value < 0)
		return 0;

	//check if already exists
	if(ans[numDenominations][value] != -1)
		return ans[numDenominations][value];
	//small calc and rec call
	int x= countWaysToMakeChangeHelper(denominations, numDenominations, value - denominations[0], ans);
	int y = countWaysToMakeChangeHelper(denominations + 1, numDenominations - 1, value, ans);
	return ans[numDenominations][value] = x + y;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	int **ans = new int*[numDenominations + 1];
	for(int i = 0; i <= numDenominations; i++){
		ans[i] = new int[value + 1];
		for(int j = 0; j <= value; j++)
			ans[i][j] = -1;
	}

	return countWaysToMakeChangeHelper(denominations, numDenominations, value, ans);
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