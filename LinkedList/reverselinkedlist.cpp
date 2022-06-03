void printReverse(Node *head)
{
    //Write your code here
    //base case
    if(head == NULL)
        return;

    //Rec call
    printReverse(head -> next);

    //Small calc
    cout << head -> data << " ";
}