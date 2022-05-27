#include<iostream>
using namespace std;

class student{
    int age;
    const int rollNumber;

    public:
    //initialisation list to set value of const int rollnumber;
    student(int r) : rollNumber(r){
    }

    //initialising multiple class variables
    student(int r, int age) : rollNumber(r), age(age){
    }

    void display(){
        cout << age << " " << rollNumber << endl;
    }
};

int main(){
    student s(25, 25);
    s.display();
}