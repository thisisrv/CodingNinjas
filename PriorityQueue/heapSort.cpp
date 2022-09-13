#include <iostream>
using namespace std;

void heapSort(int pq[], int n){

    //build Heap in input array pq
    //Start fron i = 1
    for(int i = 1; i < n; i++){

        //minPQ insertfn
        int childIndex = i;
        while(childIndex > 0){

            //parent index
            int parentIndex = (childIndex - 1) / 2;

            if(pq[childIndex] < pq[parentIndex]){
                //swap both
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }

            else
                break;

            //update
            childIndex = parentIndex;
        }
    }

    //Now make removeMin fn
    int size = n;

    while(size > 1){

        //swap 0 and last element
        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size - 1] = temp;

        size --; // instead of popping out we assume that size is decreased by 1

        //removemin fn of priority queue
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        int minIndex = parentIndex;

        while(leftChildIndex < size){

            if(pq[leftChildIndex] < pq[minIndex])
                minIndex = leftChildIndex;

            if(rightChildIndex < size && pq[rightChildIndex] < pq[minIndex])
                minIndex = rightChildIndex;
            
            if(minIndex == parentIndex)
                break;
            
            //swap minIndex and parentIndex
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            //Update values
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}


int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}