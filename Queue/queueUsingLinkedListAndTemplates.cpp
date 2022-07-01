#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node <T> *next;

    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

template <typename T>

class Queue{

    Node<T> *head;
    Node<T> *tail;
    int size;

    public:

    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return (size == 0);
    }

    void enqueue(T element){
        //create node
        Node<T> *newnode = new Node<T> (element);

        if(head == NULL){
            head = newnode;
            tail = newnode;
        }

        else{
            tail -> next = newnode;
            tail = newnode;
        }

        size++;
    }

    T front(){

        if(size == 0){
            cout << "Queue is empty" << endl;
            return 0;
        }

        return head -> data;
    }

    T dequeue(){
        if(size == 0){
           cout << "Queue is empty" << endl;
           return 0;
        }

        Node<T> *temp = head;
        head = head -> next;
        T ans = temp -> data;
           size --;
        delete temp;
        return ans;
    }
};

int main(){

    Queue<char> q;

    q.enqueue('a');
    q.enqueue('b');

    cout << q.front() << endl;
    cout << q.getSize() << endl;
    cout << q.dequeue() << endl;
        cout << q.dequeue() << endl;
                cout << q.dequeue() << endl;
    cout << q.isEmpty() << endl;
}