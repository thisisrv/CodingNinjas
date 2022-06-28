#include<iostream>
using namespace std;

template <typename T, typename V>
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
    Pair<int, char> p1;

    p1.setx(5);
    p1.sety('a');

    cout << p1.getx() << " " << p1.gety() << endl;
}