#include<iostream>
#include<stack>

using namespace std;

int main(){

    stack <char> s;

    s.push('a');
    s.push('b');
    s.push('c');
    cout << s.top() << endl;
    cout << s.empty() << endl;
    s.pop();
    s.pop();
//    cout << s.pop() << endl;
//    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.empty() << endl;


}