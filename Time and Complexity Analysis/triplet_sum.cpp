#include <iostream>
#include <algorithm>
using namespace std;

//#include "solution.h"
//Merge sort
void helperfn(int input[], int start_index, int end_index){

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

void mergeSort(int input[], int size){
	// Write your code here

	helperfn(input, 0, size - 1);

}
//***************************** CODE ******************************
int tripletSum(int *arr, int n, int num)
{
	//Write your code here
	//Sort array
    	mergeSort(arr, n);

    	//traversing array

    	int count = 0;

        //Check if all same values in array.
        bool all_same = true;

        for(int i = 0; i < n; i++){

            if(arr[0] != arr[i]){
                all_same = false;
                break;
            }
        }

        if(all_same == false){

            for(int k = 0; k < n - 2; k++){
                int i = k + 1, j = n - 1;
                while(i < j){

                    if(arr[i] + arr[j] == num - arr[k]){

                          //count repeating i
                          int count_i = 1, count_j = 1;
                          while(arr[i] == arr[i + 1]){
                             count_i++;
                             i++;
                          }

                          //count repeating j
                          while(arr[j] == arr[j - 1]){

                             count_j++;
                             j--;
                          }

                          //Add number in count.
                          count += count_i * count_j;
                          i++;
                          j--;
                    }

                    else if(arr[i] + arr[j] < num)
                         i++;

                    else
                         j--;
                    }
            }
        }

        else
            count = (n * (n - 1)) / 2;

    	return count;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;


		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}