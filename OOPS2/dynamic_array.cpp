#include<iostream>
using namespace std;

class dynamicArray{
    int *data;
    int nextIndex;
    int capacity;   //Arr size

    public:

    dynamicArray(){
        data = new int[5];  //Taken value khudse
        nextIndex = 0;
        capacity = 5;
    }

    //Add element fn;
    void add_element(int element){
        //Check if array is full
        if(nextIndex == capacity){
            //Create new array with double capacity
            int *newdata = new int[2 * capacity];

            //copy elements from data to newdata
            for(int i = 0; i < capacity; i++)
                newdata[i] = data[i];

            delete [] data;
            data = newdata;
            capacity = 2 * capacity;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    //Display array
    void display(){
        for(int i = 0; i < nextIndex; i++)
                cout << data[i] << " ";
        cout << endl;
    }

    int get_value(int index){
        if(index < nextIndex)
            return data[index];
        else
            return -1;
    }

    //Add element at specific index in array
    void add_element(int index, int element){
        if(index < nextIndex)
            data[index] = element;

        else if(index == nextIndex)
            add_element(element);

        else
            return;
    }
};

int main(){
    dynamicArray arr1;
    arr1.add_element(10);
    arr1.add_element(20);
    arr1.add_element(30);
    arr1.add_element(40);
    arr1.add_element(50);
    arr1.add_element(60);
    arr1.display();

    arr1.add_element(6, 400);
    arr1.display();
//    cout << arr1.get_value(2);
}