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

//    student(student &s){
//        this -> age = s.age;
//        this -> rollnumber = s.rollnumber;
//    }

    void display(){
        cout << this -> age << " : " << this -> rollnumber << endl;
    }
};

int main(){
    student s1(100, 200);
    s1.display();
    student s2(s1);
    s2.display();
}