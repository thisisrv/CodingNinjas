#include<iostream>
#include<cstring>
using namespace std;

class Student{
    int age;
    //Using Dynamic allocation for arrays now;
    char *name;

    public:
    //Creating parameterised constructor
    Student(int age, char *name){
        this -> age = age;
        //Deep copy
        this -> name = new char[strlen(name) + 1];
        strcpy(this -> name, name);
    }

    //Copy Constructor
    Student (Student const &s){
        this -> age = s.age;
        //Shallow copy
        //this -> name = s.name;
        //Deep Copy
        this -> name = new char[strlen(s.name) + 1];
        strcpy(this -> name, s.name);
    }

    //Display function
    void display(){
        cout << name << " " << age << endl;
    }
};

int main(){
    char name[] = "abcd";
    Student s1(20, name);

    name[3] = 'e';
    Student s2(24, name);
    Student s3(s2);
    s1.display();
    s2.display();
    s3.display();
}

