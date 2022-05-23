#include<iostream>
using namespace std;

class student{
    int age, rollnumber;
    public:
    student(){
        age = 0;
        rollnumber = 0;
    }

    //Paremeterised constructor
    student(int age, int rollnumber){
        this -> age = age;
        this -> rollnumber = rollnumber;
    }

    void display(){
        cout << this -> age << " : " << this -> rollnumber << endl;
    }
};

int main(){
    student s1(100, 1001);
    student s2(200, 2001);

    student *s3 = new student;

    s1.display();
    s2.display();
    *s3 = s2;
    s3 -> display();
}