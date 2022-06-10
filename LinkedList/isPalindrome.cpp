#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
//#include "solution.h"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

//Find middle element
Node *findmid(Node *head){

    Node *slow = head, *fast = head;

    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

int findlength(Node *head){
    int length = 0;

    while(head != NULL){
        length ++;
        head = head -> next;
    }

    return length;
}

Node *reverseList(Node *head){

    //Using recursion
        //Base case
        //list empty or has 1 element return
        if(head == NULL || head -> next == NULL)
            return head;

        //Rec call
        Node *remainingList = reverseList(head -> next);

        //Small calc
        head -> next -> next = head;
        head ->next = NULL;
        return remainingList;
}
//******************* CODE ********************

bool isPalindrome(Node *head)
{
    //Write your code here
    //check if ll is empty or has 1 node return true
    if(head == NULL ||head ->next == NULL)
        return true;

    //node > 1
    Node *mid = findmid(head);

    int length = findlength(head);

    Node *head2 = NULL, *tail = NULL;
    //Define tail and head2 for odd and even ll
    if(length % 2 != 0){

        //odd
        tail = mid;
        head2 = mid -> next;
    }

    else{
        //even
        head2 = mid;
        tail = head;
        while(tail -> next != mid){
            tail = tail -> next;
        }
    }

//    cout << tail -> data << " " << head2 -> data;
    //Reverse head2;
    head2 = reverseList(head2);

    //compare l1 and l2
    while(head != NULL && head2 != NULL){

        if(head -> data != head2 -> data)
            return false;

        head = head -> next;
        head2 = head2 -> next;
    }

    return true;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		cout << isPalindrome(head);
	}
	return 0;
}