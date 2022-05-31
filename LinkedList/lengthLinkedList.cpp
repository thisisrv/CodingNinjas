int length(Node *head)
{
    //Write your code here
    int count = 0;
    Node *temp = head;

    //Loop
    while(temp != NULL){

        count++;
        temp = temp -> next;
    }

    return count;
}
