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

Node* inserNode(Node *head, int i, int data){
    //Create Node
    Node *newNode = new Node(data);
    //Create temp node;
    Node *temp = head;
    int count = 0;

    while(temp != NULL && count < i - 1){
        count++;
        temp = temp -> next;
    }

    if(count == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    else{
        //Add connection
        if(temp != NULL){
            newNode -> next = temp -> next;
            temp -> next = newNode;
        }
    }
    return head;

}
int main(){

    Node *head = insert_back();

    head = inserNode(head, 0, 100);

    print(head);
}