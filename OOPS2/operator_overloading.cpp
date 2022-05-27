#include<iostream>
using namespace std;

class calculation{

    public:
    int a;
    int b;
    //Parameterised constructor
    calculation(int a, int b){
        this -> a = a;
        this -> b = b;
    }

    int operator+(int b){
        return a + b;
    }

    bool operator==(int b){
        return (a == b);
    }
};

int main(){
    calculation c(1, 2);

    cout << c.a + c.b << endl;

}