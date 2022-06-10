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

//******************* CODE ********************

Node *reverseLinkedList(Node *head)
{   //Using recursion
    //Base case
    //list empty or has 1 element return
    if(head == NULL || head -> next == NULL)
        return head;

    //Rec call
    Node *remainingList = reverseLinkedList(head -> next);

    //Small calc
    head -> next -> next = head;
    head ->next = NULL;
    return remainingList;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = reverseLinkedList(head);
		print(head);
	}
	return 0;
}