#include<iostream>
using namespace std;

class Student{
    public:
    int rollNumber;
    int age;

    //Default constructor
    Student(){
        cout << "Constructor called" << endl;
    }

    Student(int r){
        rollNumber = r;
        cout << "Value set " << r << endl;
    }

    Student(int a, int r){
        age = a;
        rollNumber = r;
    }

    void display(){
        cout << "Age is: " << age << "Roll Number is: " << rollNumber << " " << this << endl;
    }
};

int main(){
    Student s1;
    Student s2(19);
    Student *s3 = new Student(1, 15);
    s3 -> display();
    cout << "Address of s3: " << s3 << endl;
}