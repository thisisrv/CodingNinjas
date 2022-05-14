#include <iostream>
using namespace std;

//#include "solution.h"
//Merge sort
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

//Binary search
int bsearch(int input[], int low, int high, int num){

    //base case
    if(low > high)
        return -1;

    //small calculation
    int mid = (low + high) / 2;

    if(input[mid] == num)
        return mid;

    //rec calls
    if(num > input[mid])
        return bsearch(input, mid + 1, high, num);
    else
        return bsearch(input, low, mid - 1, num);
}
//**************************** CODE ******************************
int arrayRotateCheck(int *input, int size)
{
    //Write your code here
    //Copy input array to temp array
    int temp[size];
    for(int i = 0; i < size; i++)
        temp[i] = input[i];

    //Sort temp array
    mergeSort(temp, size);

    int min_element = temp[0];

    //Find index of min element using linear search.
    for(int i = 0; i < size; i++){

       if(min_element == input[i])
            return i;
    }

    return index;
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}

	return 0;
}