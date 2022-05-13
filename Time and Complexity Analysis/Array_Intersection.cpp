#include <iostream>
#include <algorithm>
using namespace std;


void helperfn(int *input, int start_index, int end_index){

    //Base case
    if(start_index >= end_index)
        return;

    //Rec call
    int mid  = (start_index + end_index) / 2;

    helperfn(input, start_index, mid);
    helperfn(input, mid + 1, end_index);


    //Small calc
    //Merge 2 sorted arrays into 1;
    int size = end_index - start_index + 1;
    int temp[size];

    int i = start_index;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= end_index){

        if(input[i] < input[j]){

            temp[k] = input[i];
            k++;
            i++;
        }

        else{

            temp[k] = input[j];
            k++;
            j++;
        }
    }

    //Add remaining elements of small arrays
    while(i <= mid){

        temp[k] = input[i];
            k++;
            i++;
    }

    while(j <= end_index){

        temp[k] = input[j];
            k++;
            j++;
    }

    //Copy temp to input array.
    for(int i = start_index; i <= end_index; i++)
        input[i] = temp[i - start_index];
}

void mergeSort(int *input, int size){
	// Write your code here

	helperfn(input, 0, size - 1);

}
//#include "solution.h"
void intersection(int *arr1, int *arr2, int n, int m)
{
    //Write your code here
    mergeSort(arr1, n);
    mergeSort(arr2, m);

    //using i and j for checking common values
    int i = 0, j = 0;
    //Display arrays
    for(int i = 0; i < n; i++)
        cout << arr1[i] << " ";

    cout << endl;
    for(int i = 0; i < m; i++)
            cout << arr2[i] << " ";

    cout << endl;
    while(i < n && j < m){

        if(arr1[i] == arr2[j]){

            cout << arr1[i] << " ";
            i++;
            j++;
        }

        else if(arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);

		delete[] input1;
		delete[] input2;

		cout << endl;
	}

	return 0;
}