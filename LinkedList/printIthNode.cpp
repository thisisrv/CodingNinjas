
void printIthNode(Node *head, int i)
{
    //Write your code here
    int count = 0;
    Node *temp = head;

    while(temp != NULL){

        count++;
        if(count == i + 1){
            cout << temp -> data;
            break;
        }

        temp = temp -> next;
    }
}