#include<iostream>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;

    //constructor
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

template <typename T>
class Stack{

    Node<T> *head;
    T size;
    public:

    Stack(){
        head = NULL;
        size = 0;
    }

    //Push fn
    void push(T element){
        //Add node in front
        Node<T> *newnode = new Node<T>(element);

        if(head == NULL)
            head = newnode;
        else{
            newnode -> next = head;
            head = newnode;
        }
        size++;
    }

    //Pop fn
    T pop(){
        //check if stack if empty
        if(size == 0){
            cout << "Stack is empty" << endl;
            return 0;
        }

        Node<T> *temp = head;
        T ans = temp -> data;
        head = head -> next;
        delete temp;
        size -- ;
        return ans;
    }

    T getsize(){
        return size;
    }

    bool isempty(){
        return (size == 0);
    }

    T top(){
        //check if stack is empty
        if(size == 0){
            cout << "Stack is empty" << endl;
            return 0;
        }

        return head -> data;
    }
};

int main(){

    Stack <char> s;

    s.push('a');
    s.push('b');
    s.push('c');
    cout << s.top() << endl;
    cout << s.isempty() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
//    cout << s.pop() << endl;
//    cout << s.pop() << endl;
        cout << s.top() << endl;
    cout << s.isempty() << endl;


}