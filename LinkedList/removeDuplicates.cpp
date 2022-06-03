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

Node *removeDuplicates(Node *head)
{
    //Write your code here
    if(head == NULL)
        return head;

    Node *t1 = head;
    Node *t2 = head -> next;

    while(t2 != NULL){
        if(t1 -> data == t2 -> data && t2 -> next == NULL){
            Node *t = t2;
            t1 -> next = NULL;
            t2 = t2 -> next;
            delete t;
        }

        else if(t1 -> data == t2 -> data){
            Node *temp = t2;
            t2 = t2 -> next;
            delete temp;
        }

        else{
            //t1 ->data != t2 -> data;
            t1 -> next = t2;
            t1 = t2;
            t2 = t2 -> next;
        }
    }

    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}