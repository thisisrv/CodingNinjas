#include<iostream>
using namespace std;

template <typename T>
class Pair{

    T x;
    T y;
    public:

    void setx(T x){
        this -> x = x;
    }
    void sety(T y){
            this -> y = y;
        }

    T getx(){
        return x;
    }

    T gety(){
            return y;
        }
};

int main(){
    Pair<int> p1;

    p1.setx(5);
    p1.sety(6);

    cout << p1.getx() << " " << p1.gety() << endl;
}