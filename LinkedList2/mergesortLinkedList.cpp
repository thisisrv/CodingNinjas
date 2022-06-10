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

Node *mergeTwoLinkedLists(Node *head1, Node *head2){

    if(head1 == NULL && head2 == NULL)
        return head1;

    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;

    //if both head1 and head2 != NULL;
    Node *fh, *ft;
    //check for smaller head;
    if(head1 -> data < head2 -> data){
        fh = ft = head1;
        head1 = head1 -> next;
    }

    else{
        fh = ft = head2;
        head2 = head2 -> next;
    }

    //While loop
    while(head1 != NULL && head2 != NULL){

        if(head1 -> data < head2 -> data){
            ft -> next = head1;
            ft = head1;
            head1 = head1 -> next;
        }
        else{
            ft -> next = head2;
            ft = head2;
            head2 = head2 -> next;
        }
    }

    if(head1 != NULL)
      ft -> next = head1;
    else if(head2 != NULL)
      ft -> next = head2;

    return fh;
}
Node *findmid(Node *head){

    Node *slow = head, *fast = head -> next;

    while(fast != NULL && fast -> next != NULL){

        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
Node *mergeSort(Node *head){

    if(head == NULL || head -> next == NULL)
        return head;

    Node *mid = findmid(head);
    Node *head1 = mid -> next;
    mid -> next = NULL;

    //Rec call
    head = mergeSort(head);
    head1 = mergeSort(head1);

    //small calc
    Node *head3 = mergeTwoLinkedLists(head, head1);
    return head3;
}
int main(){

    Node *head1 = NULL;
    head1 = insertvalues();

//    Node *head2 = NULL;
//    head2 = insertvalues();

    Node *head3 = mergeSort(head1);
    printlinkedlist(head3);
}

