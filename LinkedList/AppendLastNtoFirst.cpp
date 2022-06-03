#include <iostream>
using namespace std;

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

//************************ CODE ***************************
Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    Node *tail = head;

    //length of linked list;
    int length = 0;

    while(tail -> next != NULL){
        length++;
        tail = tail -> next;
    }

    length++;

    //Calculcate number of nodes from starting
    int start_nodes = length - n;

    //start exporting nodes to end;
    for(int i = 0; i < start_nodes; i++){
        Node *temp = head;
        tail -> next = temp;
        head = head -> next;
        tail = tail -> next;
        temp -> next = NULL;
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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}