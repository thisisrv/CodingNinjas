#include<iostream>
#include "BST.h"
using namespace std;

//4 2 1 3 6 5 7 -1
int main(){

    BST b;
    
    int data;
    cin >> data;

    while(data != -1){
        b.insertData(data);
        cin >> data;
    }

    // b.display();

    int num;
    cin >> num;

    b.display();
    cout << endl;
    b.deleteData(num);

    b.display();

}