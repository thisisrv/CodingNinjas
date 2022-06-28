#include<iostream>
#include "DynamicStack.cpp"
using namespace std;

int main(){
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << s.top() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.isempty() << endl;
    cout << s.pop() << endl;
    cout << s.isempty() << endl;
}