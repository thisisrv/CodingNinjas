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

Node *test(){
     Node *head = NULL;
        Node *tail = NULL;
        //Start Loop and stop taking input if data = -1;
        int i = 1;
        while(i <= 1000000){
            //Create a node;
            Node *newNode = new Node(i);

            if(head == NULL){
               head = newNode;
               tail = newNode;
            }

            else{
                //use tail to add element in end
                tail -> next = newNode;
                tail = tail -> next;
            }
//            cin >> data;
            i++;
        }

        return head;
}
int main(){

    Node *head = test();
}