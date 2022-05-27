#include<iostream>
using namespace std;

class Student{
    int age;
    //Using Dynamic allocation for arrays now;
    char *name;

    public:
    //Creating parameterised constructor
    Student(int age, char *name){
        this -> age = age;
        //Shallow Copy
        this -> name = name;
    }
    //Display function
    void display(){
        cout << name << " " << age << endl;
    }
};

int main(){
    char name[] = "abcd";
    Student s1(20, name);
    s1.display();

    name[3] = 'e';
    Student s2(24, name);
    s2.display();
}

