#include<cmath>
int getAllWaysHelper(int a, int b, int num){
	int val = a - pow(num, b);

	//base case
	if(val == 0)
		return 1;
	
	if(val < 0)
		return 0;

	//rec call
	//include this num
	int x = getAllWaysHelper(val, b, num + 1);

	//not include this num
	int y = getAllWaysHelper(a, b, num + 1);

	// small calc
	return x + y;
}

int getAllWays(int a, int b){
	return getAllWaysHelper(a, b, 1);
}
