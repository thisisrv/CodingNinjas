#include <iostream>
using namespace std;

//#include "solution.h"
//Reverse array
void reverse_array(int *input, int start_index, int end_index){

     while(start_index < end_index){

        int temp = input[start_index];
        input[start_index] = input[end_index];
        input[end_index] = temp;
        start_index++;
        end_index--;
     }
}
void rotate(int *input, int d, int n)
{
    //Write your code here
    //Reverse whole array
    reverse_array(input, 0, n - 1);

    //Reverse first n - d elements
    reverse_array(input, 0, n - d - 1);

    //Reverse last d elements
    reverse_array(input, n - d, n - 1);
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		delete[] input;
		cout << endl;
	}

	return 0;
}