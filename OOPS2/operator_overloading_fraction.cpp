#include<iostream>
using namespace std;

class fraction{
    int numerator;
    int denominator;
    public:
    //Parameterised constructor
    fraction (int numerator, int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    //Pre increment overload
    fraction& operator++(){
        numerator = numerator + denominator;
//        cout << numerator << " / " << denominator << endl;
        return *this;
    }

    //Post increment overload
    fraction operator++(int){
        fraction fnew(numerator, denominator);
        numerator = numerator + denominator;
        return fnew;
    }
    //Simplify function
    void simplify(){
        int gcd = 1;

        for(int i = 1; i < min(numerator, denominator); i++){
            if(numerator % i == 0 && denominator % i == 0)
                gcd = i;
        }

        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }
    void display() const{
        cout << numerator << " / " << denominator << endl;
    }

    //Overload + operator
    fraction operator+ (fraction const &f){
        denominator = denominator * f.denominator;
        int x = denominator / numerator;
        int y = denominator / f.numerator;

        numerator = x * numerator + (y * f.numerator);

        simplify();
        return *this;
    }

    //Operator += overload
    fraction& operator+=(fraction const &f){
        denominator = denominator * f.denominator;
        int x = denominator / numerator;
        int y = denominator / f.numerator;

        numerator = x * numerator + (y * f.numerator);

        simplify();
        return *this;
    }
};

int main(){
   fraction f1(10, 2);
   fraction f2(15, 4);
   fraction f3 = f1 + f2;
   f3.display();
//   f2.display();

}