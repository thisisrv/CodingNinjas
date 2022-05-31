#include<iostream>
#include "linkedlist.cpp"
using namespace std;

//Make linked list as : 1 -> 2 -> 3 -> 4 -> 5;
Node * insert_back(){
    int data;
    cin >> data;

    Node *head = NULL;

    //Start Loop and stop taking input if data = -1;
    while(data != -1){
        //Create a node;
        Node *newNode = new Node(data);

        if(head == NULL)
            head = newNode;
        else{
            //Go to end of list
            Node *temp = head;
            while(temp -> next != NULL)
                temp = temp -> next;

            temp -> next = newNode;
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


int main(){

    print(insert_back());
}