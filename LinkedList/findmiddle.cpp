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

Node *findmiddle(Node *head)
{
    //Write your code here
    Node *slow = head, *fast = head;
    while(fast != NULL && fast -> next != NULL){
        //Move fast pointer by 2 and slow by 1
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    //return middle element
    return slow;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		Node *data = findmiddle(head);
		cout << data -> data << endl;
	}
	return 0;
}