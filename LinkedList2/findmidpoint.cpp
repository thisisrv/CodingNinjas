#include<iostream>
#include "sample.cpp"
using namespace std;

//insert linked list
Node *insertvalues(){

    //value
    int data;
    cin >> data;

    Node *head = NULL, *tail = NULL;
    while(data != -1){

        //Create Node
        Node *newnode = new Node(data);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }

        else{
            tail -> next = newnode;
            tail = tail -> next;
        }

        cin >> data;
    }

    return head;
}

//Print LL
void printlinkedlist(Node *head){

    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

Node *findmid(Node *head){

    Node *slow = head, *fast = head -> next;

    while(fast != NULL && fast -> next != NULL){

        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
int main(){

    Node *head = NULL;
    head = insertvalues();

    printlinkedlist(head);

    Node *mid = findmid(head);
    cout << endl << "Mid element is: " << mid -> data << endl;
}

