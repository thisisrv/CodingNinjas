#include<iostream>
using namespace std;

template <typename T>
class DynamicStackUsingTemplates{
    T *data;
    int nextIndex;
    int capacity;

    public:

    //Create constructor;
    DynamicStackUsingTemplates(){
        data = new T[2];
        nextIndex = 0;
        capacity = 2;
    }

    //Return size of stack
    int size(){
        return nextIndex;
    }

    //return true is stack is empty
    bool isempty(){
        if(nextIndex == 0)
            return true;
        else
            return false;
    }

    //Insert element in stack
    void push(int element){
        //check if stack is full
        if(nextIndex == capacity){
            T *newstack = new T[capacity * 2];

            //copy elements from data to newstack
            for(int i = 0; i < capacity; i++)
                newstack[i] = data[i];

            delete [] data;
            data = newstack;
            capacity *= 2;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    //Delete element in stack
    T pop(){
        if(isempty()){
            cout << "Stack is empty" << endl;
            return 0;
        }

        nextIndex--;
        return data[nextIndex];
    }

    //Return top element
    T top(){
        if(isempty()){
            cout << "Stack is empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }

};

int main(){
    DynamicStackUsingTemplates<char> s;
    s.push(97);
    s.push(98);
    s.push(99);
    s.push(100);
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