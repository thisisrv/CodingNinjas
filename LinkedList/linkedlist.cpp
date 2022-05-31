#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    //Constructor
    Node (int data){
        this -> data = data;
        this -> next = NULL;
    }

};

//int main(){
//
//    //statically
////    Node n1(1), n2(2);
////    Node *head = &n1;
////    n1.next = &n2;
////
////    cout << head -> data << head -> next -> data << endl;
////    cout << n1.data << " " << n2.data << endl;
////    Dynamically
//    Node *n1 = new Node(1), *n2 = new Node(2);
//    Node *n3 = new Node(3);
//
//    Node *head  = n1;
//    n1 -> next = n2;
//    n2 -> next = n3;
//
//    cout << head -> data << " " << head -> next -> data << " " << head -> next -> next -> data << endl;
//
//}