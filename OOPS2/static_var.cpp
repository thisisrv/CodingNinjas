#include<iostream>
using namespace std;

class student{
    public:
    int age;
    int rollNumber;

    void display(){
        cout << age << " " << rollNumber << endl;
    }

    static int totalstudents;

    //making static function
    static int gettotalstudents(){
        return totalstudents;
    }
};
//Initialising static variable
int student :: totalstudents = 52;

int main(){
    student s;
    s.display();

    cout << student :: gettotalstudents() << endl;
}