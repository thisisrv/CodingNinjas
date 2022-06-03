#include<iostream>
#include "linkedlist.cpp"
using namespace std;
//Make linked list as : 1 -> 2 -> 3 -> 4 -> 5;
Node * insert_back(){
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;
    //Start Loop and stop taking input if data = -1;
    while(data != -1){
        //Create a node;
        Node *newNode = new Node(data);

        if(head == NULL){
           head = newNode;
           tail = newNode;
        }

        else{
            //use tail to add element in end
            tail -> next = newNode;
            tail = tail -> next;
        }
        cin >> data;
    }

    return head;
}

void print(Node *head){
        while(head != NULL){
             cout << head -> data << " ";
             head = head -> next;
        }

        cout << endl;
}

//Insert at position i using recursion
Node *insert_recursion(Node *head, int i, int data){
    //Base case
    if(head == NULL && i != 0)
        return head;

    //small calc
    if(i == 0){
        //create a node with data as value
        Node *n = new Node(data);
        n -> next = head;
        head = n;
        return head;
    }

    //Rec call
    head -> next =  insert_recursion(head -> next, i - 1, data);
    return head;
}
int main(){

    Node *head = insert_back();
    print(head);

    int pos, data;
    cin >> pos >> data;

    head = insert_recursion(head, pos, data);
    print(head);
}