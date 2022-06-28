#include<iostream>
using namespace std;

template < typename T , typename V>
class Pair{

    T x;
    V y;
    public:

    void setx(T x){
        this -> x = x;
    }
    void sety(V y){
            this -> y = y;
        }

    T getx(){
        return x;
    }

    V gety(){
            return y;
        }
};

int main(){
    Pair<Pair<int, float>, char> p1;

    Pair<int, float> p;
    p.setx(5);
    p.sety(5.11);
//    p1.setx(5);
    p1.setx(p);
    p1.sety('a');

    cout << p1.getx().getx() << " " << p1.getx().gety() << " " << p1.gety() << endl;
}