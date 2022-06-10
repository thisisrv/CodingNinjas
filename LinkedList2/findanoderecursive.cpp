int findNodeRec(Node *head, int n)
{
	//Write your code here
    //Base case
    if(head == NULL)
        return -1;

    if(head -> data == n)
        return 0;

    //rec call
    int index = findNodeRec(head -> next, n);

    if(index == -1)
        return -1;
    else
        return index + 1;
}