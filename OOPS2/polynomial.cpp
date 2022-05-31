#include<iostream>
using namespace std;

class polynomial{

    int *defcoeff;
    int capacity;
    public:

    //Default contructor;
    polynomial(){
        defcoeff = new int[5];
        capacity = 5;

        for(int i = 0; i < capacity; i++)
               defcoeff[i] = 0;
    }

    //Set coefficient
    void setCoefficient(int index, int element){
        //check if index >= capacity
        if(index >= capacity){

            //create a new array with double size
            int *newdefCoeff = new int[2 * capacity];

//            for(int i = 0; i < 2 * capacity; i++){
//
//                if(i < capacity)
//                    newdefCoeff[i] = defcoeff[i];
//
//                else
//                    newdefCoeff[i] = 0;
//            }

            for(int i = 0; i < capacity; i++)
                newdefCoeff[i] = 0;

            for(int i = 0; i < capacity; i++)
                newdefCoeff[i] = defcoeff[i];

            //set defcoeff to newdefcoeff
            defcoeff = newdefCoeff;
            delete [] newdefCoeff;
            capacity *= 2;
        }

        defcoeff[index] = element;
    }

    //Display polynomial
    void display(){

        for(int i = 0; i < capacity; i++){
             if(defcoeff[i] == 0)
                continue;
             cout << defcoeff[i] << "x" << i << " ";
        }
        cout << endl;
    }
};

int main(){
    int size;
    cin >> size;

    int *degree = new int[size];

    for(int i = 0; i < size; i++)
        cin >> degree[i];

    //Coeff;
    int *coeff = new int[size];
    for(int i = 0; i < size; i++)
            cin >> coeff[i];

    polynomial first;
    //adding into polynomial
    for(int i = 0; i < size; i++){
        first.setCoefficient(degree[i], coeff[i]);
    }


    first.display();
}