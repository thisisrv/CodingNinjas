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


Node *deleteNode(Node *head, int pos)
{
    //temp. Cover all cases of pos < 0, pos = 0, pos > 0;
        Node *temp = head;
        if(pos < 0)
            return head;

        if(pos == 0){

            head = head -> next;
            delete temp;
            return head;
        }

        //pos > 0.
        //Traverse till pos
        int i = 0;
        while(temp != NULL && i < pos - 1){
            i++;
            temp = temp -> next;
        }

        if(temp != NULL && temp -> next != NULL){

            Node *t = temp -> next;
            temp -> next = temp -> next -> next;
            delete t;
        }

        return head;
}
int main(){

    Node *head = insert_back();
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);

    print(head);
}