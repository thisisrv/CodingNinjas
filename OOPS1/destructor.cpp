#include<iostream>
using namespace std;

class student{
    int age, rollnumber;
    public:
    student(){
        cout << "Contructor created" << endl;
    }

    //Creating destructor
    ~ student(){
        cout << "Destructor called" << endl;
    }
};

int main(){
    student s1, s2;
    student *s3 = new student;
    delete s3;
}